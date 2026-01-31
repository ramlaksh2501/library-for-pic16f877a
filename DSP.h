/* 
author:LAKSH
started date:19/01/2026
info: library for pic16f877a 

*/
#ifndef DSP_H
#define DSP_H
#define  INPUT  1
#define  OUTPUT 0
#define  SETIN(n,port)  (port|=1<<(n))
#define  SETOUT(n,port) (port&=~(1<<(n)))
#define  HIGH  1
#define  LOW   0
#define  SETHIGH(n,port) (port|=1<<(n))
#define  SETLOW(n,port)  (port&=~(1<<(n)))

#ifndef PORTA
#define PORTA (*((volatile char *) 0X05))
#define TRISA (*((volatile char *) 0X85))
#define PORTB (*((volatile char *) 0X06))
#define TRISB (*((volatile char *) 0X86))
#define PORTC (*((volatile char *) 0X07))
#define TRISC (*((volatile char *) 0X87))
#define PORTD (*((volatile char *) 0X08))
#define TRISD (*((volatile char *) 0X88))
#define PORTE (*((volatile char *) 0X09))
#define TRISE (*((volatile char *) 0X89))
#endif

//we dont need to care about the bankswitching 
void pinmode(int a,int b);
void pinwrite(int a,int b);
char sevenseg_L(unsigned char x);
void mux_seven(int x);
void mux_seven_direct(char x,char y,char z);
void general_mux_seven_direct(char x,char y,char z,volatile char *oport,volatile char *cport);
void keypad_display();
void keypad_display_2digit();
void keypad_sdigit_operation();
void keypad_4digit_display();
void keypad_4digit_calc();

#endif

