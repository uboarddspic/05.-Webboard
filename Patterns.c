/*/////////////////////////////////////////////////////////////////////////
//
//  File Name    : Patterns.c
//  Version      : 1.0
//  Description  : Code for the various patterns
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802 on uBRD
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 09-07-2011
//
//  Get latest updates from www.uBoard.eu
//  Copyright (c) Bloxi 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
/////////////////////////////////////////////////////////////////////////*/
#include    "Delay.h"
#include    "Patterns.h"
#include    "Peripherals.h"
#include    "uBRD.h"

void Eraseleds() {
    unsigned char g = 0;

    for (g = 0; g < 192; g++) {
        SHIFT_DATA = 0;
        SHIFT_CLOCK = 1;
        Delayus(1);
        SHIFT_CLOCK = 0;
        Delayus(1);
    }
    SHIFT_DATA = 0;
    SHIFT_STROBE = 1;
    Delayus(1);
    SHIFT_STROBE = 0;
    Delayms(1);
}

void Shiftpwm(unsigned char* pixel, unsigned char dimval)
{
    /* Total time of this function has to be 0.02 S */
    switch (dimval)
    {
        case 1:
            /* Leds 50% on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                break;

            case 2:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                break;

        case 3:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 4:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 5:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 6:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 7:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 8:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 9:
            /* Leds 50% on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

            case 10:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 11:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 12:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 13:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 14:
                /* Leds fully on */
                Shift(0x00);
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 15:
                /* Leds fully on */
                Shift(0x00);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;

        case 16:
                /* Leds fully on */
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                Shift(pixel);
                break;
    }
}

void Shift(unsigned char* pixel) {
    unsigned char i = 0;

    for (i = 0; i < 192; i++) {
        if (pixel[i] & 0x01) SHIFT_DATA = 1;
        else SHIFT_DATA = 0;

        SHIFT_CLOCK = 1;
        Delayus(1);
        SHIFT_CLOCK = 0;
    }
    /* Latch after 192 clock pulses */
    SHIFT_STROBE = 1;
    Delayus(1);
    SHIFT_STROBE = 0;
}

void Mirror(unsigned char* pixel) {
    unsigned char p = 144;
    unsigned char tmpval[192];
    for (p = 144; p < 192; p++) {
        /* Temporarily store pixel value */
        tmpval[p] = pixel[p];
    }

    pixel[144] = tmpval[189]; /* B */
    pixel[145] = tmpval[190]; /* G */
    pixel[146] = tmpval[191]; /* R */

    pixel[147] = tmpval[186];
    pixel[148] = tmpval[187];
    pixel[149] = tmpval[188];

    pixel[150] = tmpval[183];
    pixel[151] = tmpval[184];
    pixel[152] = tmpval[185];

    pixel[153] = tmpval[180];
    pixel[154] = tmpval[181];
    pixel[155] = tmpval[182];

    pixel[156] = tmpval[177];
    pixel[157] = tmpval[178];
    pixel[158] = tmpval[179];

    pixel[159] = tmpval[174];
    pixel[160] = tmpval[175];
    pixel[161] = tmpval[176];

    pixel[162] = tmpval[171];
    pixel[163] = tmpval[172];
    pixel[164] = tmpval[173];

    pixel[165] = tmpval[168];
    pixel[166] = tmpval[169];
    pixel[167] = tmpval[170];

    pixel[168] = tmpval[165];
    pixel[169] = tmpval[166];
    pixel[170] = tmpval[167];

    pixel[171] = tmpval[162];
    pixel[172] = tmpval[163];
    pixel[173] = tmpval[164];

    pixel[174] = tmpval[159];
    pixel[175] = tmpval[160];
    pixel[176] = tmpval[161];

    pixel[177] = tmpval[156];
    pixel[178] = tmpval[157];
    pixel[179] = tmpval[158];

    pixel[180] = tmpval[153];
    pixel[181] = tmpval[154];
    pixel[182] = tmpval[155];

    pixel[183] = tmpval[150];
    pixel[184] = tmpval[151];
    pixel[185] = tmpval[152];

    pixel[186] = tmpval[147];
    pixel[187] = tmpval[148];
    pixel[188] = tmpval[149];

    pixel[189] = tmpval[144];
    pixel[190] = tmpval[145];
    pixel[191] = tmpval[146];
}

void Update(unsigned char* pixel) {
    unsigned char j = 1;
    unsigned char pixeltempr = 0;
    unsigned char pixeltempg = 0;
    unsigned char pixeltempb = 0;
    unsigned char temp[192];

    /* Shift the other 47 leds up */
    for (j = 1; j < 48; j++) {
        pixel[j] = pixel[j - 1];
    }
    j++;

    pixel[95] = pixel[48];
    for (j = 49; j < 96; j++) {
        pixel[j] = pixel[j + 1];
    }
    j++;

    /* Fill a temporary array */
    for (j = 96; j < 144; j++) {
        temp[j] = pixel[j];
    }



    pixeltempr = pixel[141];
    pixeltempg = pixel[142];
    pixeltempb = pixel[143];
    for (j = 99; j < 144; j++) {
        pixel[j] = temp[j - 3];
    }
    /* Store saved pixel in last pixel */
    pixel[96] = pixeltempr;
    pixel[97] = pixeltempg;
    pixel[98] = pixeltempb;


    pixeltempr = pixel[144];
    pixeltempg = pixel[145];
    pixeltempb = pixel[146];
    for (j = 144; j < 189; j++) {
        pixel[j] = pixel[j + 3];
    }
    /* Store saved pixel in last pixel */
    pixel[189] = pixeltempr;
    pixel[190] = pixeltempg;
    pixel[191] = pixeltempb;
}
