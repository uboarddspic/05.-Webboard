/*/////////////////////////////////////////////////////////////////////////
//
//  File Name    : Socket.c
//  Version      : 1.0
//  Description  : Using the sockets of the W5100
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802 on uBRD
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 21-06-2011
//
//  Get latest updates from www.uBoard.eu
//  Copyright (c) Bloxi 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
/////////////////////////////////////////////////////////////////////////*/
#include    "Delay.h"
#include    "Socket.h"
#include    "stdio.h"
#include    "string.h"
#include    "W5100.h"

void close(unsigned char sock) {
    if (sock != 0)
        return;

    /* Send Close Command */
    SPI_Write(S0_CR, CR_CLOSE); /* Wait until S0_CR is clear */
    while (SPI_Read(S0_CR));
}

void disconnect(unsigned char sock) {
    if (sock != 0)
        return; /* Send disconnect command */

    SPI_Write(S0_CR, CR_DISCON); /* Wait for disconecting process */
    while (SPI_Read(S0_CR));
}

unsigned char socket(unsigned char sock, unsigned char eth_protocol, unsigned int tcp_port) {
    unsigned char retval = 0;
    if (sock != 0)
        return retval;

    /* Close socket first */
    if (SPI_Read(S0_SR) == SOCK_CLOSED) {
        close(sock);
    } /* Assigned Socket 0 Mode Register */
    SPI_Write(S0_MR, eth_protocol);

    /* Now open the Socket 0 */
    SPI_Write(S0_PORT, ((tcp_port & 0xFF00) >> 8));
    SPI_Write(S0_PORT + 1, (tcp_port & 0x00FF));
    SPI_Write(S0_CR, CR_OPEN); /* Open Socket, wait for Opening Process  */
    while (SPI_Read(S0_CR)); /* Check for Init Status */
    if (SPI_Read(S0_SR) == SOCK_INIT)
        retval = 1;
    else
        close(sock);

    return retval;
}

unsigned char listen(unsigned char sock) {
    unsigned char retval = 0;
    if (sock != 0)
        return retval;

    if (SPI_Read(S0_SR) == SOCK_INIT) {
        /* Send the LISTEN Command */
        SPI_Write(S0_CR, CR_LISTEN);

        /* Wait for Listening Process */
        while (SPI_Read(S0_CR)); /* Check for Listen Status */
        if (SPI_Read(S0_SR) == SOCK_LISTEN)
            retval = 1;
        else
            close(sock);
    }
    return retval;
}

unsigned int send(unsigned char sock, const unsigned char *buf, unsigned int buflen) {
    unsigned int ptr, offaddr, realaddr, txsize, timeout;

    if (buflen <= 0 || sock != 0)
        return 0;

    txsize = SPI_Read(SO_TX_FSR);
    txsize = (((txsize & 0x00FF) << 8) + SPI_Read(SO_TX_FSR + 1));

    while (txsize < buflen) {
        Delayms(1);
        txsize = SPI_Read(SO_TX_FSR);
        txsize = (((txsize & 0x00FF) << 8) + SPI_Read(SO_TX_FSR + 1)); /* Timeout for approx 1000 ms */
        if (timeout++ > 1000) {

            /* Disconnect the connection */
            disconnect(sock);
            return 0;
        }
    }

    /* Read the Tx Write Pointer */
    ptr = SPI_Read(S0_TX_WR);
    offaddr = (((ptr & 0x00FF) << 8) + SPI_Read(S0_TX_WR + 1));

    while (buflen) {
        buflen--;
        /* Calculate the real W5100 physical Tx Buffer Address */
        realaddr = TXBUFADDR + (offaddr & TX_BUF_MASK); /* Copy the application data to the W5100 Tx Buffer */
        SPI_Write(realaddr, *buf);
        offaddr++;
        buf++;
    }

    /* Increase the S0_TX_WR value, so it point to the next transmit */
    SPI_Write(S0_TX_WR, (offaddr & 0xFF00) >> 8);
    SPI_Write(S0_TX_WR + 1, (offaddr & 0x00FF));

    /* Now Send the SEND command */
    SPI_Write(S0_CR, CR_SEND);

    /* Wait for Sending Process */
    while (SPI_Read(S0_CR));

    return 1;
}

unsigned int recv(unsigned char sock, unsigned char *buf, unsigned int buflen) {
    unsigned int ptr, offaddr, realaddr;

    if (buflen <= 0 || sock != 0) return 1;

    /* If the request size > MAX_BUF,just truncate it */
    if (buflen > MAX_BUF)
        buflen = MAX_BUF - 2; /* Read the Rx Read Pointer */
    ptr = SPI_Read(S0_RX_RD);
    offaddr = (((ptr & 0x00FF) << 8) + SPI_Read(S0_RX_RD + 1));

    while (buflen) {
        buflen--;
        realaddr = RXBUFADDR + (offaddr & RX_BUF_MASK);
        *buf = SPI_Read(realaddr);
        offaddr++;
        buf++;
    }
    *buf = '\0'; /* String terminated character */

    /* Increase the S0_RX_RD value, so it point to the next receive */
    SPI_Write(S0_RX_RD, (offaddr & 0xFF00) >> 8);
    SPI_Write(S0_RX_RD + 1, (offaddr & 0x00FF));

    /* Now Send the RECV command */
    SPI_Write(S0_CR, CR_RECV);
    Delayms(1); /* Wait for Receive Process */

    return 1;
}

unsigned int recv_size(void) {
    return ((SPI_Read(S0_RX_RSR) & 0x00FF) << 8) +SPI_Read(S0_RX_RSR + 1);
}

int strindex(char *s, char *t) {
    unsigned int i, n;

    n = strlen(t);
    for (i = 0; *(s + i); i++) {
        if (strncmp(s + i, t, n) == 0)
            return i;
    }
    return -1;
}
