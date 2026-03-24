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

void init_pwm(uint16_t duty){//the frequency is fixed in here 1.2khz ,the time period is aroud 800uS .
// if you want to control the time period use the pwm config fuction
//the parameter duty denotes the duty cycle of the pwm 
//DUTY must be below 1024 (0-1023)  duty cycle percentage = (DUTY/1024)*100
//this fucntion used ccp1 so the output will be in the pin C2
    PR2=0xff;
    CCP1CON|=0x0F;
    TMR2_OFF();
    TMR2CON_BITS->PRESCALE=0x3;  
    TRISC&=~(1<<2);
    if(duty<=1023){
        CCPR1L=(unsigned char)duty>>2;
        CCP1CON|=(unsigned char)(duty&0x03)<<4;
    }
    TMR2_ON();
    
   
   
}

void pwm_config(uint8_t pr2,uint8_t prescale ,uint16_t duty){
    //parameters: 
    //value for the pr2
    //prescale value of tmr2 (must be one of these : TMR_PRESCALE_1 or TMR_PRESCALE_4 or TMR_PRESCALE_16 macros)
    //duty  in the range 0-1023
    //duty cycle percentage =(duty/1023)*100
    //refer the formula for time period in datasheet 
    //#define DUTY (value from 0 to 1023) 
    TMR2_OFF();
    TRISC&=~(1<<2);
    if( duty<=1023){
        CCPR1L=(unsigned char)duty>>2;
        CCP1CON|=(unsigned char)(duty&0x03)<<4;
    }
    TMR2CON_BITS->prescale=prescale;
    PR2=pr2;
    TMR2_ON();

    
}


static inline void PWM_START(){
    TMR2_ON();}
static inline void PWM_STOP (){
    TMR2_OFF();}

