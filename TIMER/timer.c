#include "timer.h"

void L_delay_ms(unsigned long t){
    OPTION_REG=0x04;
    INTCON=0x00;
    TMR0=0x65;
    unsigned long i=0;
    while(i!=t){
        if(INTCON & (1<<2)){
              
        INTCON&=~(1<<2);
        i++;
        TMR0=0x65;
        }
}

}

void L_delay_s(unsigned long t){
    OPTION_REG=0x04;
    INTCON=0x00;
    TMR0=0x65;
    unsigned long x=t*1000;
    unsigned long i=0;
    while(i!=x){
        if(INTCON & (1<<2)){
              
        INTCON&=~(1<<2);
        i++;
        TMR0=0x65;
        }
}

}
static inline void TMR1_ON  (){  TMR1CON_BITS->STATUS=1;}
static inline void TMR1_OFF (){  TMR1CON_BITS->STATUS=0;}
static inline void TMR2_ON  (){  TMR2CON_BITS->STATUS=1;}
static inline void TMR2_OFF (){  TMR2CON_BITS->STATUS=0;}

void init_pwm(){
    TRISC=(1<<2);
    CCP1CON|=0x0F;
    TMR2_OFF();
    TMR2CON_BITS->PRESCALE=0x2;
    
    

}



void L_pwm(unsigned long long dutycycle ,unsigned long period){

PR2=0xFF;
CCPCON1|=(0x03)<<4;
CCPR1L=0x7F;

}


