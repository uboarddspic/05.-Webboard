///////////////////////////////////////////////////////////////////////////
//
//  File Name    : W5100.c
//  Version      : 1.0
//  Description  : Initializations and SPI routines for W5100
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802 on uBRD
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 18-06-2011
//
//  Get latest updates from www.uboard.eu
//  Copyright (c) Staronic 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
///////////////////////////////////////////////////////////////////////////
#include    "Delay.h"
#include    "uBRD.h"
#include    "W5100.h"

void Init_pin_SPI(void) {
    OSCCONbits.IOLOCK = 0; // Clear I/O lock
    RPINR20 = 0x0007; // Assign SPI1 Data Input to RP7 pin
    RPOR1 = 0x0700; // SPI1 SD0 is Assigned to RP3 Output Pin
    RPOR2 = 0x0008; // SPI1 SCK is Assigned to RP4 Output Pin
    OSCCONbits.IOLOCK = 1; // Set I/O lock
    TRISBbits.TRISB7 = 1; // SPI1 Data pin is input
    TRISAbits.TRISA4 = 0; // SPI1 Latch is output
    T_SPI_CS;
    SPI_CS = 1;
}

void Init_SPI(void) {
    IFS0bits.SPI1IF = 0; // Clear the Interrupt Flag
    IEC0bits.SPI1IE = 0; // Disable the Interrupt
    SPI1STATbits.SPIROV = 0; // Clear Receive overflow flag bit
    SPI1CON1bits.DISSCK = 0; // Internal Serial Clock is Enabled
    SPI1CON1bits.DISSDO = 0; // SDOx pin is controlled by the module
    SPI1CON1bits.MODE16 = 0; // Communication is byte-wide (8 bits)
    SPI1CON1bits.CKE = 0; // Serial output data changes on rising edge
    SPI1CON1bits.SSEN = 0; // /SS1 pin is not used by the module.
    // from Idle clock state to active clock state
    SPI1CON1bits.CKP = 0; // Idle state for clock is a low level
    SPI1CON1bits.MSTEN = 1; // Master mode Enabled
    SPI1CON1bits.SMP = 0; // 1Input data is sampled at falling edge
    SPI1STATbits.SPIEN = 1; // Enable SPI module
}

void W5100_Init(unsigned char* gtw_addr,unsigned char* mac_addr,unsigned char* sub_mask,unsigned char* ip_addr) {

    SPI_Write(MR, 0x80); // Soft reset W5100
    Delayms(1);

    // Setting the W5100 Gateway Address (GAR)
    SPI_Write(GAR + 0, gtw_addr[0]);
    SPI_Write(GAR + 1, gtw_addr[1]);
    SPI_Write(GAR + 2, gtw_addr[2]);
    SPI_Write(GAR + 3, gtw_addr[3]);
    Delayms(1);

    // Setting the W5100 Source Address (SAR)
    SPI_Write(SAR + 0, mac_addr[0]);
    SPI_Write(SAR + 1, mac_addr[1]);
    SPI_Write(SAR + 2, mac_addr[2]);
    SPI_Write(SAR + 3, mac_addr[3]);
    SPI_Write(SAR + 4, mac_addr[4]);
    SPI_Write(SAR + 5, mac_addr[5]);
    Delayms(1);

    // Setting the W5100 Sub Mask Address (SUBR)
    SPI_Write(SUBR + 0, sub_mask[0]);
    SPI_Write(SUBR + 1, sub_mask[1]);
    SPI_Write(SUBR + 2, sub_mask[2]);
    SPI_Write(SUBR + 3, sub_mask[3]);
    Delayms(1);

    // Setting the W5100 IP Address (SIPR)
    SPI_Write(SIPR + 0, ip_addr[0]);
    SPI_Write(SIPR + 1, ip_addr[1]);
    SPI_Write(SIPR + 2, ip_addr[2]);
    SPI_Write(SIPR + 3, ip_addr[3]);
    Delayms(1);

    // Setting the W5100 RX and TX Memory Size (2KB)
    SPI_Write(RMSR, MEMALLOC);
    SPI_Write(TMSR, MEMALLOC);
}

void SPI_Write(unsigned int addr, unsigned char data) {
    short temp;
    SPI_CS = 0;

    // Start W5100 write opcode
    temp = SPI1BUF; // dummy read of SPI1BUF register to clear SPIRBF flag
    SPI1BUF = WRITE_OPCODE;
    while (!SPI1STATbits.SPIRBF) // wait for the data to be sent out
        ;

    // Start W5100 address high byte transmission
    temp = SPI1BUF; // dummy read of SPI1BUF register to clear SPIRBF flag
    SPI1BUF = (addr & 0xFF00) >> 8;
    while (!SPI1STATbits.SPIRBF) // wait for the data to be sent out
        ;

    // Start W5100 address low byte transmission
    temp = SPI1BUF; // dummy read of SPI1BUF register to clear SPIRBF flag
    SPI1BUF = addr & 0x00FF;
    while (!SPI1STATbits.SPIRBF) // wait for data to be sent out
        ;

    // Start W5100 address low byte transmission
    temp = SPI1BUF; // dummy read of SPI1BUF register to clear SPIRBF flag
    SPI1BUF = data;
    while (!SPI1STATbits.SPIRBF) // wait for the data to be sent out
        ;

    SPI_CS = 1;
}

unsigned char SPI_Read(unsigned int addr) {
    short temp;
    SPI_CS = 0;

    // Start W5100 read opcode
    temp = SPI1BUF; // dummy read of SPI1BUF register to clear SPIRBF flag
    SPI1BUF = READ_OPCODE;
    while (!SPI1STATbits.SPIRBF) // wait for the data to be sent out
        ;

    // Start W5100 address high byte
    temp = SPI1BUF; // dummy read of SPI1BUF register to clear SPIRBF flag
    SPI1BUF = (addr & 0xFF00) >> 8;
    while (!SPI1STATbits.SPIRBF) // wait for the data to be sent out
        ;

    // Start W5100 address low byte
    temp = SPI1BUF; // dummy read of the SPI1BUF register to clear the SPIRBF flag
    SPI1BUF = addr & 0x00FF;
    while (!SPI1STATbits.SPIRBF) // wait for the data to be sent out
        ;

    // Send dummy data and read received data
    temp = SPI1BUF; // dummy read of SPI1BUF register to clear SPIRBF flag
    SPI1STATbits.SPIROV = 0;
    SPI1BUF = 0x00;
    while (!SPI1STATbits.SPIRBF) // wait for the data to be sent in
        ;

    SPI_CS = 1;
    return (SPI1BUF);
}
