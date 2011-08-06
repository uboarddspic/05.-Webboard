///////////////////////////////////////////////////////////////////////////
//  Product/Project : Button test                                        //
///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Delay.c
//  Version      : 1.0
//  Description  : Simple delay routines
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 03-01-2011
//
//  Copyright (c) Staronic 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
///////////////////////////////////////////////////////////////////////////
#include    "uBRD.h"
#include    "Delay.h"

    extern unsigned int Count;

void Delayms(int n)
{
    long i;

    while(n--)
    {
        i = (3625*(FCY/40000))/1000;
        while(i)
	{
            i--;
	}
    }
}

void Delayus(int n)
{
    long i;

    while(n--)
    {
        i = (4 *(FCY/40000))/1000;
        while(i)
	{
            i--;
    	}
    }
}
