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


void pinmode(int a,int b)
    {
        if(a>=33&&a<=40)
        {   if(b==0) 
            SETOUT(a-33,TRISB);
            else
            SETIN(a-33,TRISB);
        }
    }
void pinwrite(int a,int b)
    {
        if(a>=33&&a<=40)
        {   if(b==0) 
            SETLOW(a-33,PORTB);
            else
            SETHIGH(a-33,PORTB);
        }
    }
char sevenseg_L(unsigned char x){
    char digit[11]={0b11111100,0b01100000,
        0b11011010,0b11110010,0b01100110,0b10110110,0b10111110,0b11100100,0b11111110,0b11110110,0};
return digit[x];
}
void mux_seven(int x){//maximum three digits only 
// range:(000-999)
static char x;
if(x==0){
    TRISB=0x00;
    TRISC&=~(0x07);}
    char ones,tens,hundreds;
    ones=x%10;
    tens=(x/10)%10;
    hundreds=(x/100)%10;
    PORTB=0;
    PORTC=0;
    for(int i;i<10000;i++){
        PORTB=sevenseg_L(ones);
        PORTC=0x01;
        __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(tens);
        PORTC=0x02;
        __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(hundreds);
        PORTC=0x04;
        __delay_ms(2);
        PORTC=0x00; }

}
void mux_seven_direct(char x,char y,char z){//maximum three digits only 
// range:(000-999)
//u must make the port b all output 
//and port c's three LSBs as input before using this function
    PORTB=0x00;
        PORTB=sevenseg_L(x);
        PORTC=0x01;
        __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(y);
        PORTC=0x02;
        __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(y);
        PORTC=0x04;
        __delay_ms(2);
        PORTC=0x00; 

}
void general_mux_seven_direct(char x,char y,char z,volatile char *oport,volatile char *cport){//maximum three digits only 
//range:(000-999)
//oport is the sevensegment 
//cport is for selection (LSBs)
static char x;
if(x==0){
    *(oport+80)=0x00;
     *(cport+80)&=~(0x07);}   
     for(int m=0;m<10000;i++){
    *oport=sevenseg_L(x);
        *cport=0x01;
        __delay_ms(2);
        *cport=0x00;
     *oport=sevenseg_L(y);
        *cport=0x02;
        __delay_ms(2);
        *cport=0x00;
        *oport=sevenseg_L(y);
        *cport=0x04;
        __delay_ms(2);
        *cport=0x00;}
}
void keypad_display()
void keypad_display_2digit()
void keypad_sdigit_operation()
void keypad_4digit_display()
void keypad_4digit_calc()

#endif

