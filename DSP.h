/* 
author:LAKSH
started date:19/01/2026
info: library for pic16f877a 

*/

#define  INPUT  1
#define  OUTPUT 0
#define  SETIN(n,port)  (port|=1<<(n))
#define  SETOUT(n,port) (port&=~(1<<(n)))
#define  HIGH  1
#define  LOW 0
#define  SETHIGH(n,port) (port|=1<<(n))
#define  SETLOW(n,port)  (port&=~(1<<(n)))


#define PORTA (*(volatile char * 0X05 ))
#define TRISA (*(volatile char * 0X85 ))
#define PORTB (*(volatile char * 0X06 ))
#define TRISB (*(volatile char * 0X86 ))
#define PORTC (*(volatile char * 0X07 ))
#define TRISC (*(volatile char * 0X87 ))
#define PORTD (*(volatile char * 0X08 ))
#define TRISD (*(volatile char * 0X88 ))
#define PORTE (*(volatile char * 0X09 ))
#define TRISE (*(volatile char * 0X89 ))




char sevenseg_L(unsigned char x){
    char digit[11]={0b11111100,0b01100000,
        0b11011010,0b11110010,0b01100110,0b10110110,0b10111110,0b11100100,0b11111110,0b11110110,0};
return digit[x];
}