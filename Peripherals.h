/*
 * Prototype definitions for on-board peripherals
 */
#ifndef	__Peripherals_h
#define	__Peripherals_h

// Initializations
void Init(void);
void Init_shift(void);
void Init_RGB(void);
void Erase_VU(void);
void Init_mcp(void);
void Init_LCD(void);
void Init_timers(void);
void Init_timer_echo(void);
void Init_timer1(void);
void Init_UART(void);
void Init_buzzer(void);
void Init_ADC_pot(void);
void Init_ADC_sine(void);
void Init_DAC_sine(void);
void Init_ADC_echo(void);
void Init_DAC_echo(void);

// Peripherals
int ADC(int c);
void DAC(int left, int right);
void RGBfade(int r, int g, int b);
void setRGB(int r, int g, int b);
void Shiftleds(unsigned short i);
void VU_meter(unsigned short l,unsigned short r);

// Serial communication
void Putcharacter(char c);
void Putstr(char *s);
char Getcharacter(void);

// I2C 
#define gControlByte  0x40
#define WrtCmd  0
#define RdCmd   1

#define IODIRA      0x00
#define IODIRB      0x01
#define IPOLA       0x02
#define IPOLB       0x03
#define GPINTENA    0x04
#define GPINTENB    0x05
#define DEFVALA     0x06
#define DEFVALB     0x07
#define INTCONA     0x08
#define INTCONB     0x09
#define IOCONA      0x0A
#define IOCONB      0x0B
#define GPPUA       0x0C
#define GPPUB       0x0D
#define INTFA       0x0E
#define INTFB       0x0F
#define INTCAPA     0x10
#define INTCAPB     0x11
#define GPIOA       0x12
#define GPIOB       0x13
#define OLATA       0x14
#define OLATB       0x15

void Write23X08_17(unsigned char reg, unsigned char data, unsigned char gAddrPins);
unsigned char Read23X08_17(unsigned char reg, unsigned char gAddrPins);
void WaitForACK(void);
unsigned char Switches(void);
                                                
// LCD control bit setup                          R/S   E   R/W (N/A)
#define WRT_READ  0x60    // Read Data from LCD    0    1    1    0
#define WRT_INST  0x40    // Write Instr to LCD    0    1    0    0
#define WRT_DATA  0xC0    // Write DATA to LCD     1    1    0    0

// LCD
void Write_LCD(unsigned char * text);
void LCD_Write_INST(unsigned char display_value);
void LCD_Write_DATA(unsigned char display_value);
void LCD_Clear(void);
void LCD_Off(void);
void LCD_PutString(char *s);
void LCD_AppendString(char *s);
void LCD_PutHex(unsigned char h);
void LCD_PutByte(unsigned char c);
void LCD_PutWord(unsigned short w);
void LCD_PutLong(unsigned long l);

#endif	//__Peripherals__
