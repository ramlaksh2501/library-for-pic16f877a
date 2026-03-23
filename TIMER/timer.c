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

void init_pwm_default(){//the frequency is fixed in here 1.2khz ,the time period is aroud 800uS .
// if you want to control the time period use the pwm config fuction
//need to define the DUTY macro to use this fuciton 
//DUTY must be below 1024 (0-1023)  duty cycle percentage = (DUTY/1024)*100
//#define DUTY (value from 0 to 1023) 
//this fucntion used ccp1 so the output will be in the pin C2
    PR2=0xff;
    CCP1CON|=0x0F;
    TMR2_OFF();
    TRISC&=~(1<<2);
    #ifdef DUTY
    if(DUTY >=0 && DUTY<=1023){
        CCPR1L=DUTY>>2;
        CCP1CON|=(unsigned char)(DUTY&0x03)<<4;
    }
    #endif
   
    TMR2CON_BITS->PRESCALE=0x3;
}

void pwm_config(){
    //give the prescale 
    //value for the pr2
    //DUTY macro must be defined 
    //#define DUTY (value from 0 to 1023) 

}



void L_pwm(){



}


