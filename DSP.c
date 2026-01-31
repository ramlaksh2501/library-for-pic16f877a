//#include<xc8.h>
#include "/home/ramlaksh/learnings/pic-library/DSP.h"
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
static char p;
if(p==0){
    TRISB=0x00;
    TRISC&=~(0x07);}
    char ones,tens,hundreds;
    ones=x%10;
    tens=(x/10)%10;
    hundreds=(x/100)%10;
    PORTB=0;
    PORTC=0;
    for(int i=0;i<10000;i++){
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
static char w;
if(w==0){
    *(oport+80)=0x00;
     *(cport+80)&=~(0x07);}   
     for(int m=0;m<10000;m++){
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