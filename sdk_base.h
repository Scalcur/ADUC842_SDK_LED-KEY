//=====================================================
// Header File: sdk_base.h
// Version Date: 01 June 2019
//=====================================================
#define ADC_CON812 0x40
#define ADC_CON842 0x80
#define ADC_TSENS  0x08
#define ADC_DAT0    0
#define ADC_DAT1    4
#define ADC_DAT2    8
#define ADC_DAT3   12
#define ADUC812  0
#define ADUC842  1
#define C_IND    6
#define DAC_0    0
#define DAC_1    1
#define DATA_IND 1
#define EXT_LO   2
#define EXT_HI   3
#define ENA      4
#define KB       0
#define LCD_CLR  1
#define LCD_CR   2
#define LCD_BF 0x80
#define LCD_POS(pos) (pos | LCD_BF)
#define RTC_AM    0x00
#define RTC_12    0x80
#define RTC_24    0x00
#define RTC_HH    0x3F   // Remove 12/24 and AM/PM flags. 
#define RTC_PM    0x40
#define RTC_START (getmode() & 0x7F)
#define RTC_STOP  (getmode() | 0x80)
#define SV       7
#define uchar unsigned  char
#define uint  unsigned  int
extern void  putbyte(uchar, uchar);
extern void lputchar(uchar, uchar);
extern void   svdisp(uchar);
extern void uart_ini(uchar);
extern void put_uart(uchar);
extern void  put_lpt(uint);
extern void dac_ini (uchar);
extern void put_idata (uchar,uchar);
extern void dac_single(uint, uchar);
extern void adc_ini(uchar, uchar, uchar);
extern uchar   getkey(void);
extern uchar get_uart(void);
extern uchar lgetchar(void);
extern uchar get_idata(uchar);
extern uchar   getbyte(uchar);
extern uchar   getmode(void);
extern uint    get_lpt(void);
extern uint adc_single(void);
extern bit       getack(uchar);
extern bit      gettime(uchar);
extern bit      puttime(uchar);
extern bit receiveblock(uint,uchar,uchar); 
extern bit    sendblock(uint,uchar,uchar);
extern bit     putmode (uchar);
//=====================================================
// End of File sdk_base.h
//=====================================================
