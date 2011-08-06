///////////////////////////////////////////////////////////////////////////
//  Product/Project : Web board with simple HTML site                    //
///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Main.c
//  Version      : 1.0
//  Description  : Connect the uBoard to the internet with the "Web board"
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 21-06-2011
//
//  Copyright (c) Staronic 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
///////////////////////////////////////////////////////////////////////////
#include    "Delay.h"
#include    "Peripherals.h"
#include    "Patterns.h"
#include    "Socket.h"
#include    "stdio.h"
#include    "stdlib.h"
#include    "string.h"
#include    "uBRD.h"
#include    "W5100.h"
#include    <avr/pgmspace.h>

//Configuration-for-programmer--------------------------
_FBS(RBS_NO_RAM & BSS_NO_FLASH & BWRP_WRPROTECT_OFF);               // No boot ram, flash, write protection
_FSS(RSS_NO_RAM & SWRP_WRPROTECT_OFF);                              // No protected sections
_FGS(GSS_OFF
& GCP_OFF & GWRP_OFF);                                              // No code protection
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF);                                  // FRC Oscillator with PLL, no two-speed oscillator
_FOSC(FCKSM_CSDCMD & IOL1WAY_OFF & OSCIOFNC_ON  & POSCMD_NONE);     // Clock Switching and Fail Safe Clock Monitor is disabled
                                                                    // Multiple I/O reconfigurations admitted                                                                  // OSC2 Pin is digital I/O														                      // Primaire Oscillator Mode: none
_FWDT(FWDTEN_OFF & WINDIS_OFF);                                     // Watchdog Timer off
_FPOR(ALTI2C_ON & FPWRT_PWR64);                                     // 64 ms power-up timer
_FICD(JTAGEN_OFF & ICS_PGD2);                                       // JTAG program port off
//------------------------------------------------------

// Global W5100 defines
unsigned char mac_addr[] = {0x00, 0x16, 0x36, 0xDE, 0x58, 0xF6};
unsigned char ip_addr[] = {192, 168, 1, 130};
unsigned char sub_mask[] = {255, 255, 255, 0};
unsigned char gtw_addr[] = {192, 168, 1, 1};

unsigned char startup[60] = "uBoard                                  "
        "Web board site";

unsigned char sockreg;
unsigned char buf[MAX_BUF];
int tempvalue;
unsigned char ledmode;

// Led pixels defines
unsigned char patt[192] = {
    //0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    //48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    //96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01,

    //144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01
};

unsigned char testpatt[192] = {
    //0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    //48  49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    //96  97    98    99    100   101   102   103   104   105   106   107   108   109   110   111   112   113   114   115   116   117   118   119
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    //144 145   146   147   148   149   150   151   152   153   154   155   156   157   158   159   160   161   162   163   164   165   166   167
    //B   G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R     B     G     R
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void __attribute__((interrupt,no_auto_psv)) _T1Interrupt( void ) {
    static unsigned int t = 1;
    // interrupt service routine for Timer1
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
    TMR1 = 0;
    T1CONbits.TON = 1;
    // reset Timer 1 interrupt flag

    t++;
    if (t >= 500) {

        // Select the LED Mode here
        if (ledmode == 1) {
            Shift(patt);
            Update(patt);

            t = 1;
        }

        if (ledmode == 0) {
            Shiftleds(0xFFFF);
        }
    }
}

int main(void) {
    // Ledstrips inits
    Init_timer1();
    Init_shift();
    OSCTUN = 21;
    PLLFBD = 38; // M=40
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE = 0; // N2=2
    Eraseleds();
    // even ledstrips have to be mirrored
    Mirror(patt);

    // LCD inits
    Init_mcp();
    Init_LCD();
    Write_LCD(startup);

    // W5100 inits
    Init_pin_SPI();
    Init_SPI();
    W5100_Init(gtw_addr,mac_addr,sub_mask,ip_addr);
    T_SPI_CS;
    SPI_CS = 1;

    // W5100 defines
    unsigned char sockstat;
    unsigned int rsize;
    char radiostat0[10], radiostat1[10];
    int getidx, postidx;
    // Initial variable used
    sockreg = 0;
    tempvalue = 0;
    ledmode = 1;
    unsigned short i=0x8000;
    
    while (1) {

        sockstat = SPI_Read(S0_SR);
        switch (sockstat) {
            case SOCK_CLOSED:
                if (socket(sockreg, MR_TCP, TCP_PORT) > 0) {
                    // Listen to Socket 0
                    if (listen(sockreg) <= 0)
                        Delayms(1);
                }
                break;

            case SOCK_ESTABLISHED:
                // Get the client request size
                rsize = recv_size();
                if (rsize > 0) {
                    // Now read the client Request
                    if (recv(sockreg, buf, rsize) <= 0)
                        break;

                    // Check the Request Header
                    getidx = strindex((char *) buf, "GET /");
                    postidx = strindex((char *) buf, "POST /");

                    if (getidx >= 0 || postidx >= 0) {

                        // Now check the Radio Button for POST request
                        if (postidx >= 0) {
                            if (strindex((char *) buf, "radio=0") > 0)
                                ledmode=0;
                            if (strindex((char *) buf, "radio=1") > 0)
                        	ledmode=1;
                        }

            // Create the HTTP Response	Header
	    strcpy((char *)buf,("HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n"
                                "<body style=\"background-color:FFFFFF;\">\r\n"));
	    strcat((char *)buf,("<html><body>\r\n"
                                "<span style=\"color:#E5208A\">\r\n"
                                "<font face=\"Verdana\" color=FF0066>\r\n"
                                "<img border=\"0\" src=\"http://www.deliciousdance.nl/Plaatjes/tasslogo.jpg\""
                                "width=\"1000\" height=\"120\"/> \r\n"
                                "<h2>BloXi interface</h2>\r\n"
                                "<h4>uBoard & Web board</h4>\r\n"
                                "<form method=\"POST\">\r\n"));
            // Now Send the HTTP Response
	    if (send(sockreg,buf,strlen((char *)buf)) <= 0) break;

            LCD_Clear();
            LCD_PutByte(ledmode);
	    if (ledmode == 1) {
	      strcpy(radiostat0,"");
	      strcpy(radiostat1,("checked"));
	    } else {
	      strcpy(radiostat0,("checked"));
	      strcpy(radiostat1,"");
	    }

            // Create the HTTP Radio Button Response
	    strcpy((char *)buf,("<p><input type=\"radio\" name=\"radio\" value=\"0\" "));
	    strcat((char *)buf,radiostat0);
	    strcat((char *)buf,(">Chase effect\r\n"));
	    strcat((char *)buf,("<br><input type=\"radio\" name=\"radio\" value=\"1\" "));
	    strcat((char *)buf,radiostat1);
	    strcat((char *)buf,(">Rainbow effect\r\n"));
 	    strcat((char *)buf,("</strong><p>\r\n"));
	    strcat((char *)buf,("<input type=\"submit\">\r\n"));
	    strcat((char *)buf,("</form></span></body></html>\r\n"));            // Now Send the HTTP Remaining Response
	    if (send(sockreg,buf,strlen((char *)buf)) <= 0)
                break;


                    } // Disconnect the socket
                    disconnect(sockreg);
                } else
                    Delayms(1); // Wait for request
                break;

            case SOCK_FIN_WAIT:
            case SOCK_CLOSING:
            case SOCK_TIME_WAIT:
            case SOCK_CLOSE_WAIT:
            case SOCK_LAST_ACK:
                // Force to close the socket
                close(sockreg);

                break;
        }
    }
    return 0;
}
