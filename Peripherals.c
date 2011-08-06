///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Peripherals.c
//  Version      : 1.1
//  Description  : Code for all on-board peripherals
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802 on uBRD
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 21-06-2011
//
//  Get latest updates from www.uboard.eu
//  Copyright (c) Staronic 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
///////////////////////////////////////////////////////////////////////////
#include    "Delay.h"
#include    "i2c.h"
#include    "Peripherals.h"
#include    "uBRD.h"

///////////////////////////////////////////////////////////////////////////
//  Onboard initializations	                                         //
///////////////////////////////////////////////////////////////////////////

void Init(void) {
    /*
     *  Initialize PLL for maximum speed
     *  FRC = 7.370 MHz + 21*30kHz= 8.000 Mhz
     *  Fosc= 8 MHz * 40/(2*2) = 80 Mhz
     *  Fcy = 40 MHz
     */
    // Tune FRC oscillator: 7.370 MHz + 21*30kHz= 8 Mhz
    OSCTUN = 21;
    PLLFBD = 38; // M=40
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE = 0; // N2=2
}

void Init_shift(void) {
    // Initialize digital I/O
    T_SHIFT_DATA; // Shiftregister data
    T_SHIFT_CLOCK; // Shiftregister clock
    T_SHIFT_STROBE; // Shiftregister strobe
}

void Init_RGB(void) {
    OSCCONbits.IOLOCK = 0; // Clear I/O lock
    RPOR1 = 0x1200; // RP3 Led Red (OC1)
    RPOR2 = 0x0013; // RP4 Led Green (OC2)
    RPOR3 = 0x1400; // RP7 Led Blue (OC3)
    RPOR5 = 0x1500; //RP11 piezo speaker  /RP10 nc
    OSCCONbits.IOLOCK = 1; // Set I/O lock
}

void Erase_VU(void) {
    int i;
    // Erase VU meter leds
    SHIFT_DATA = 0;
    SHIFT_CLOCK = 0;
    for (i = 0; i < 16; i++) {
        SHIFT_CLOCK = 1;
        SHIFT_CLOCK = 0;
    }
    SHIFT_STROBE = 1;
    SHIFT_STROBE = 0;
}

void Init_mcp(void) {
    unsigned int config2, config1;
    config2 = 0x190; // Baud rate is set for 100 kHz
    config1 = 0b1000001000100000;
    /* 
     * (I2C_ON & I2C_IDLE_CON & I2C_CLK_HLD & I2C_IPMI_DIS & I2C_7BIT_ADD &
     * I2C_SLW_DIS & I2C_SM_DIS & I2C_GCALL_DIS & I2C_STR_DIS & I2C_NACK &
     * I2C_ACK_DIS & I2C_RCV_DIS & I2C_STOP_DIS &   I2C_RESTART_DIS &
     * I2C_START_DIS)
     */
    // Configure I2C for 7 bit address mode
    OpenI2C1(config1, config2);
    IdleI2C1();

    //Initialize MCP23017 i2c I/O expander
    Write23X08_17(IOCONA, 0b01111000, 0x00);
    Write23X08_17(GPPUA, 0x00, 0x00); // Set Pull-up resistors
    Write23X08_17(GPPUB, 0x1F, 0x00); // Set Pull-up resistors
    Write23X08_17(IPOLA, 0x00, 0x00); // I/O polarity normal
    Write23X08_17(IPOLB, 0x00, 0x00); // I/O polarity normal
    Write23X08_17(GPIOA, 0x00, 0x00); // Row is kept LOW while changing I/O
    Write23X08_17(GPIOB, 0x00, 0x00); // Row is kept LOW while changing I/O
    Write23X08_17(IODIRA, 0x00, 0x00); // Rows = inputs; Columns = outputs
    Write23X08_17(IODIRB, 0x1F, 0x00); // Rows = inputs; Columns = outputs
}

void Init_LCD(void) {
    LCD_Clear();
    Delayms(15);
    LCD_Write_INST(0x30);
    Delayms(5);
    LCD_Write_INST(0x30);
    Delayms(1);
    LCD_Write_INST(0x30);
    Delayms(1);
    LCD_Write_INST(0x38);
    Delayms(1);

    // LCD operating characteristics
    // cursor and display shift settings
    LCD_Write_INST(0x18);
    // display on, blink off
    LCD_Write_INST(0x0C);
    // clear display
    LCD_Write_INST(0x01);
    // entry mode settings
    LCD_Write_INST(0x06);
}

void Init_timers(void) {
    // Initialize Timer2
    OC1CONbits.OCTSEL = 0; // Timer2 = input
    OC1CONbits.OCM = 0b110; // OC1 in PWM mode
    OC1RS = 0;
    OC2CONbits.OCTSEL = 0; // Timer2 = input
    OC2CONbits.OCM = 0b110; // OC2 in PWM mode
    OC2RS = 0;
    OC3CONbits.OCTSEL = 0; // Timer2 = input
    OC3CONbits.OCM = 0b110; // OC3 in PWM mode
    OC3RS = 0;

    T2CONbits.T32 = 0; // Timer2: 16 bits timer
    T2CONbits.TCKPS = 0b10; // Timer2: prescaler 1:64
    T2CONbits.TCS = 0; // Timer2: internal clock (Fosc/2)
    T2CONbits.TGATE = 0; // Timer2: normal timer
    PR2 = 256; // Timer2: reset at 256
    T2CONbits.TON = 1; // Timer2: start

    // Initialize Timer4
    T4CONbits.T32 = 0; // Timer4: 16 bits timer
    T4CONbits.TCKPS = 0b01; // Timer4: prescaler 1:8
    T4CONbits.TCS = 0; // Timer4: internal clock (Fosc/2)
    T4CONbits.TGATE = 0; // Timer4: normal timer
    PR4 = 500; // Timer4: reset at 500
    T4CONbits.TON = 1; // Timer4: start (period= 100 us)
    // Lowest frequency = 10kHz/(8000/20)= 25Hz
}

void Init_timer_echo(void) {
    //Timer2 initialisation
    T2CONbits.T32 = 0; // 16 bits timer
    T2CONbits.TCKPS = 0b00; // Prescaler = 1:1
    T2CONbits.TCS = 0; // Internal clock(Fosc/2)
    T2CONbits.TGATE = 0; // Normal timer
    IEC0bits.T2IE = 1; // Timer2 interrupt enable
    IFS0bits.T2IF = 0; // Timer2 interrupt flag low
    PR2 = 1000; // Timer2 period = 1000 * 2 = 2000 clock cycles
    // = 80 MHz/2000 = 40000 kHz
    INTCON1bits.NSTDIS = 1; // Interrupt nesting disabled
    IPC1bits.T2IP = 0b111; // Highest interrupt priority
    T2CONbits.TON = 1; // Interrupt on
}

void Init_timer1(void) {
    T1CON = 0; // Timer reset
    IFS0bits.T1IF = 0; // Reset Timer1 interrupt flag
    IPC0bits.T1IP = 6; // Timer1 Interrupt priority level=4
    TMR_ON = 1; // Enable Timer1 interrupt
    TMR1 = 0x0000;
    PR1 = 0xFFFF; // Timer1 period register
    T1CONbits.TON = 1; // Enable Timer1 and start the counter
}

void Init_UART(void) {
    /*
     *  Initialize UART1 (USB-RS232)
     *  UART enabled / No IrDA decoder / T1TX and U1RX used
     *  No wakeup, loopback and auto-baud
     *  Standard mode baudrate generator
     *	8-bit, no parity, 2 stop bits
     */
    U1MODE = 0x8801;
    U1STA = 0x0400; // Enable transmitter / Receiver is active
    U1BRG = BRGVAL; // Initialize baud rate generator
}

void Init_buzzer(void) {
    T_SPEAKER; // Activate speaker output
    // Initialize PWM registers
    T2CON = 0b1000000000010000; // Timer 2 1:8 prescale
    T3CON = 0b1000000000010000; // Timer 3 1:8 prescale
    OC1CON = 0b0000000000000110; // PWM mode timer 2 = timer source
    OC2CON = 0b0000000000000110; // PWM mode timer 2 = timer source
    OC3CON = 0b0000000000000110; // PWM mode timer 2 = timer source
    OC4CON = 0b0000000000001110; // PWM mode timer 3 = timer source
    OC1R = 0xFFFF;
    OC1RS = 0;
    OC2R = 0xFFFF;
    OC2RS = 0;
    OC3R = 0xFFFF;
    OC3RS = 0;
    OC4R = 0xFFFF;
    OC4RS = 0;
}

void Init_ADC_pot(void) {
    // AD Conversion
    AD1PCFGL = 0xFFFF; // Everything digital I/O
    AD1PCFGLbits.PCFG0 = 0; // AN0 analog input (audio left)
    AD1PCFGLbits.PCFG1 = 0; // AN1 analog input (audio right)
    AD1PCFGLbits.PCFG2 = 0; // AN2 analog input (potmeter 1)
    AD1PCFGLbits.PCFG3 = 0; // AN3 analog input (potmeter 2)
    AD1PCFGLbits.PCFG4 = 0; // AN4 analog input (potmeter 3)
    AD1CON1bits.AD12B = 0; // 10-bit conversion
    AD1CON2bits.VCFG = 0b000; // AVdd and AVss as ADC reference
    AD1CON3bits.ADRC = 0; // Systemclock for ADC
    AD1CON3bits.ADCS = 3; // TAD = 4*Tcy = 100 ns
    AD1CON3bits.SAMC = 15; // 16*TAD = sample time
    AD1CON2bits.CHPS = 0b00; // Convert channel 0
    AD1CON1bits.ASAM = 0; // Manually start sampling
    AD1CON1bits.SSRC = 0b000; // Manually start conversion
    AD1CON1bits.FORM = 0b01; // Signed integer
    AD1CON1bits.ADON = 1; // Start A/D module
}

void Init_ADC_sine(void) {
    AD1PCFGL = 0xFFFF; // Everything digital I/O
    AD1PCFGLbits.PCFG0 = 0; // AN0 analog input (potmeter)
    AD1PCFGLbits.PCFG1 = 0; // AN1 analog input (blue)
    AD1PCFGLbits.PCFG2 = 0; // AN2 analog input (red, audio L)
    AD1PCFGLbits.PCFG3 = 0; // AN3 analog input (green, audio R)
    AD1CON1bits.AD12B = 0; // 10-bit conversion
    AD1CON2bits.VCFG = 0b000; // AVdd and AVss as ADC reference voltage
    AD1CON3bits.ADRC = 0; // System clock for ADC
    AD1CON3bits.ADCS = 3; // TAD = 4*Tcy = 100 ns
    AD1CON3bits.SAMC = 15; // 16*TAD = sampletime
    AD1CHS0bits.CH0NA = 0; // Vref- = negative input
    AD1CHS0bits.CH0SA = 2; // AN0 = positieve input
    AD1CON2bits.CHPS = 0b00; // Convertert channel 0
    AD1CON1bits.ASAM = 1; // Start sample automatic
    AD1CON1bits.SSRC = 0b111; // Convert after sampletime automatic
    AD1CON1bits.FORM = 0b01; // Signed integer format
    AD1CON1bits.ADON = 1; // Start A/D module
}

void Init_DAC_sine(void) {
    ACLKCONbits.SELACLK = 0; // Fast RC with PLL as aux. osc divider source (80 MHz)
    ACLKCONbits.ASRCSEL = 1; // Primair osc as aux. osc source
    ACLKCONbits.APSTSCLR = 0b111; // Aux. oscillator divider 1
    DAC1CONbits.DACFDIV = 3; // DAC clock divider 4
    DAC1DFLT = 0x0000; // Default value
    DAC1CONbits.FORM = 1; // Signed integer
    DAC1STATbits.LOEN = 1; // Left output enabled
    DAC1STATbits.ROEN = 1; // Right output enabled
    DAC1CONbits.DACEN = 1; // Start D/A module
}

void Init_ADC_echo(void) {
    AD1CON1bits.ADON = 0; // ADC module off
    AD1PCFGL = 0b0001111111111100; // AN0 and AN1 analog inputs
    AD1CON2bits.VCFG = 0b000; // +Ref=AVDD and -Ref=AVSS
    AD1CON3bits.ADCS = 0b0001010; // Tosc = 1/80 MHz * 2 = TCY * 10 = TAD
    AD1CON3bits.ADRC = 0; // Clock is system clock
    AD1CON2bits.CHPS = 0b00; // S/H ch0
    AD1CHS0bits.CH0NA = 0; // Vref- is negative input
    AD1CON1bits.SSRC = 0b111; // Auto-convert
    AD1CON3bits.SAMC = 0b01010; // Sampling = 10 * TAD
    AD1CON1bits.FORM = 0b01; // Integer is output in ADC1BUF0
    AD1CON1bits.ASAM = 1; // Sampling starts when SAMP = 1
    AD1CON1bits.AD12B = 1; // 12-bit, 1 channel ADC operation
    AD1CON1bits.ADON = 1; // ADC module on
}

void Init_DAC_echo(void) {
    DAC1CONbits.DACEN = 0; // Stop D/A module
    ACLKCONbits.SELACLK = 0; // Fast RC with PLL as aux. osc divider source
    ACLKCONbits.ASRCSEL = 1; // Primair oscillator as aux. oscillator source
    ACLKCONbits.APSTSCLR = 0b111; // Aux. oscillator divider 1
    DAC1CONbits.DACFDIV = 3; // DAC clock divider 4
    DAC1DFLT = 0x0000; // Default value
    DAC1CONbits.FORM = 1; // Signed integer as input
    DAC1STATbits.LOEN = 1; // Left output enabled
    DAC1STATbits.ROEN = 1; // Right output enabled
    DAC1CONbits.DACEN = 1; // Start D/A module
}

///////////////////////////////////////////////////////////////////////////
//  Onboard peripherals 	                                           	 //
///////////////////////////////////////////////////////////////////////////

int ADC(int c) {
    AD1CHS0bits.CH0NA = 0; // Vref- = negative input
    AD1CHS0bits.CH0SA = c; // AN<c> = positive input
    AD1CON1bits.SAMP = 1; // start sampling
    Delayus(10); // sampling time = 10us
    AD1CON1bits.SAMP = 0; // start conversion
    while (!AD1CON1bits.DONE);
    return (ADC1BUF0);
}

void DAC(int left, int right) {
    DAC1LDAT = left;
    DAC1RDAT = right;
}

void RGBfade(int r, int g, int b) {
    int i;

    for (i = 0; i < 128; i++) {
        // Fade the 3 colors
        setRGB((r * i) >> 7, (g * i) >> 7, (b * i) >> 7);
        Delayms(5);
    }

    for (i = 127; i > 0; i--) {
        // Fade the 3 colors
        setRGB((r * i) >> 7, (g * i) >> 7, (b * i) >> 7);
        Delayms(5);
    }
}

void setRGB(int r, int g, int b) {
    // Assign PWM modules to R,G,B
    OC1RS = r;
    OC2RS = g;
    OC3RS = b;
}

void Shiftleds(unsigned short i) {
    unsigned char j;

    SHIFT_CLOCK = 0;
    SHIFT_STROBE = 0;

    for (j = 0; j < 17; j++) {
        // Data gets clocked on rising edge
        SHIFT_CLOCK = 1;
        SHIFT_CLOCK = 0;
        if (i & 0x01) SHIFT_DATA = 1;
        else SHIFT_DATA = 0;

        i = i >> 1;
    }
    SHIFT_STROBE = 1;
    SHIFT_STROBE = 0;
}

void VU_meter(unsigned short l, unsigned short r) {
    unsigned short lvu, rvu;

    switch (l) {
        case 1:
            lvu = VU_A1;
            break;
        case 2:
            lvu = VU_A2;
            break;
        case 3:
            lvu = VU_A3;
            break;
        case 4:
            lvu = VU_A4;
            break;
        case 5:
            lvu = VU_A5;
            break;
        case 6:
            lvu = VU_A6;
            break;
        case 7:
            lvu = VU_A7;
            break;
        case 8:
            lvu = VU_A8;
            break;
        default:
            lvu = 0;
    }
    switch (r) {
        case 1:
            rvu = VU_B1;
            break;
        case 2:
            rvu = VU_B2;
            break;
        case 3:
            rvu = VU_B3;
            break;
        case 4:
            rvu = VU_B4;
            break;
        case 5:
            rvu = VU_B5;
            break;
        case 6:
            rvu = VU_B6;
            break;
        case 7:
            rvu = VU_B7;
            break;
        case 8:
            rvu = VU_B8;
            break;
        default:
            rvu = 0;
    }
    Shiftleds(lvu | rvu);
}

///////////////////////////////////////////////////////////////////////////
//  Serial communication		                                     	 //
///////////////////////////////////////////////////////////////////////////

void Putcharacter(char c) {
    // Send a character to USB RS232 port
    while (U1STAbits.UTXBF);
    U1TXREG = c;
}

void Putstr(char *s) {
    // Send a string to USB RS232 port
    while (*s) {
        Putcharacter(*s++);
    }
}

char Getcharacter(void) {
    // Receive a character from the RS232 port
    while (!U1STAbits.URXDA);
    return (U1RXREG);
}

///////////////////////////////////////////////////////////////////////////
//  Onboard I2C 			                                          	 //
///////////////////////////////////////////////////////////////////////////

void Write23X08_17(unsigned char reg, unsigned char data, unsigned char gAddrPins) {
    StartI2C1();
    // Wait till start sequence is completed
    while (I2C1CONbits.SEN);
    MasterWriteI2C1(gControlByte | WrtCmd | gAddrPins);
    WaitForACK();
    MasterWriteI2C1(reg);
    WaitForACK();
    MasterWriteI2C1(data);
    WaitForACK();
    StopI2C1();
    // Wait till stop sequence is completed
    while (I2C1CONbits.PEN);
}

unsigned char Read23X08_17(unsigned char reg, unsigned char gAddrPins) {
    unsigned char num;

    StartI2C1();
    // Wait till start sequence is completed
    while (I2C1CONbits.SEN);
    MasterWriteI2C1(gControlByte | WrtCmd | gAddrPins);
    WaitForACK();
    MasterWriteI2C1(reg);
    WaitForACK();
    RestartI2C1();
    IdleI2C1();
    MasterWriteI2C1(gControlByte | RdCmd | gAddrPins);
    WaitForACK();
    num = MasterReadI2C1();
    NotAckI2C1();
    StopI2C1();
    IdleI2C1();
    return (num);
}

void WaitForACK() {
    // Wait till address is transmitted
    while (I2C1STATbits.TBF); // 8 clock cycles
    while (I2C1STATbits.TRSTAT);
    while (I2C1STATbits.ACKSTAT);
}

unsigned char Switches(void) {
    unsigned int io, rval;

    // Returns the status of the five switches
    io = Read23X08_17(GPIOB, 0x00);
    rval = 0;
    /*
     * defined as: 0 0 0 sw5 sw4 sw3 sw2 sw1
     *        [sw1]
     * [sw2]  [sw3]  [sw4]
     *        [sw5]
     */
    if (!(io & 0b00010000)) rval |= 0b00000001; // SW1
    if (!(io & 0b00001000)) rval |= 0b00000010; // SW2
    if (!(io & 0b00000100)) rval |= 0b00000100; // SW3
    if (!(io & 0b00000010)) rval |= 0b00001000; // SW4
    if (!(io & 0b00000001)) rval |= 0b00010000; // SW5

    return (rval);
}

///////////////////////////////////////////////////////////////////////////
//  LCD functions                                                   	 //
///////////////////////////////////////////////////////////////////////////

void Write_LCD(unsigned char * text) {
    LCD_Clear();
    unsigned char cnt;

    for (cnt = 0; text[cnt]; cnt++)
        LCD_Write_DATA(text[cnt]);
}

void LCD_Write_INST(unsigned char display_value) {
    // Setup GPIOB LCD control bits for instruction
    Write23X08_17(GPIOB, WRT_INST, 0x00);
    // Write the Instruction to GPIOA
    Write23X08_17(GPIOA, display_value, 0x00);
    // Disable the LCD control bits on GPIOB
    Write23X08_17(GPIOB, 0x00, 0x00);
}

void LCD_Write_DATA(unsigned char display_value) {
    if (display_value == '\n') {
        // Cursor on second line, first position
        LCD_Write_INST(0xc0);
    } else {
        // Setup control bits on LCD
        Write23X08_17(GPIOB, WRT_DATA, 0x00);
        // Write the data to the LCD
        Write23X08_17(GPIOA, display_value, 0x00);
        // Disable the LCD control bits on GPIOB
        Write23X08_17(GPIOB, 0x80, 0x00);
    }
}

void LCD_Clear(void) {
    // This function clears the LCD and brings
    // the cursor to the top left position
    LCD_Write_INST(0x01);
    LCD_Write_INST(0x06);
}

void LCD_Off(void) {
    LCD_Write_INST(0x08);
    Delayms(1);
}

void LCD_PutString(char *s) {
    LCD_Clear();
    LCD_AppendString(s);
}

void LCD_AppendString(char *s) {
    while (*s) { // Outputs a string
        LCD_Write_DATA(*s++);
    }
}

void LCD_PutHex(unsigned char h) {
    // Outputs a four-bit value as hex
    h = (h & 0x0f) + '0';
    LCD_Write_DATA(h <= '9' ? h : h + 7);
}

void LCD_PutByte(unsigned char c) {
    // Outputs a byte as two-character hex
    LCD_PutHex(c >> 4);
    LCD_PutHex(c);
}

void LCD_PutWord(unsigned short w) {
    // Outputs a word as four-character hex
    LCD_PutByte((unsigned char) (w >> 8));
    LCD_PutByte((unsigned char) w);
}

extern void LCD_PutLong(unsigned long l) {
    // Outputs a long as eight-character hex
    LCD_PutWord((unsigned short) (l >> 16));
    LCD_PutWord((unsigned short) l);
}
