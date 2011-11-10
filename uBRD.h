/*
 * Hardware definitions for the uBRD dsPIC development board
 */
#ifndef	__uBRD_h
#define	__uBRD_h
#include    "p33FJ64GP802.h"

/* Global */
#define	FCY   	  	40000000    /* Instruction cycle */
#define BAUDRATE	115200      /* RS232 baud rate */
#define BRGVAL 		((FCY/BAUDRATE)/16)-1	/* Baud rate generator value */

/* Speaker piezo */
#define SPEAKER       LATBbits.LATB11
#define T_SPEAKER     TRISBbits.TRISB11=0
#define SPKR          LATBbits.LATB11
#define T_SPKR        TRISBbits.TRISB11=0

/* Shift register */
#define	SHIFT_DATA      LATAbits.LATA2
#define	T_SHIFT_DATA    TRISAbits.TRISA2=0
#define	SHIFT_CLOCK	LATAbits.LATA3
#define	T_SHIFT_CLOCK   TRISAbits.TRISA3=0
#define	SHIFT_STROBE    LATAbits.LATA4
#define	T_SHIFT_STROBE  TRISAbits.TRISA4=0

/* UART */
#define UTX     LATBbits.LATB8
#define T_UTX   TRISBbits.TRISB8=0
#define URX     LATBbits.LATB9
#define T_URX   TRISBbits.TRISB9=1

/* I2C */
#define SDA       LATBbits.LATB5
#define T_SDA     TRISBbits.TRISB5=1
#define SCL       LATBbits.LATB6
#define T_SCL     TRISBbits.TRISB6=1

/* RGB led */
#define LEDG    LATBbits.LATB7
#define T_LEDG  TRISBbits.TRISB7=0
#define LEDB    LATBbits.LATB4
#define T_LEDB  TRISBbits.TRISB4=0
#define LEDR    LATBbits.LATB3
#define T_LEDR  TRISBbits.TRISB3=0

/* VU leds */
#define VU_A1   0x8000
#define VU_A2   0xA000
#define VU_A3   0xA800
#define VU_A4   0xAA00
#define VU_A5   0xAA80
#define VU_A6   0xAAA0
#define VU_A7   0xAAA8
#define VU_A8   0xAAAA

#define VU_B1   0x4000
#define VU_B2   0x5000
#define VU_B3   0x5400
#define VU_B4   0x5500
#define VU_B5   0x5540
#define VU_B6   0x5550
#define VU_B7   0x5554
#define VU_B8   0x5555

/* Analog inputs */
#define	AD_LEFT     0
#define	AD_RIGHT    1
#define	AD_POT1     2
#define	AD_POT2     3
#define	AD_POT3     4

/* Analog outputs */
#define	DA_LEFT     0
#define	DA_RIGHT    1

/* Button values */
#define BTNDOWN    0xF0     /* switch status: 1 1 1 1 0 */
#define BTNRIGHT   0xE8     /* switch status: 1 1 1 0 1 */
#define BTNMID     0xD8     /* switch status: 1 1 0 1 1 */
#define BTNLEFT    0xB8     /* switch status: 1 0 1 1 1 */
#define BTNUP      0x78     /* switch status: 0 1 1 1 1 */

#define TMR_ON  IEC0bits.T1IE
#define PORTEXP_UBRD    0x00

/* User defined settings */
/* Place your own defines here */

#endif
