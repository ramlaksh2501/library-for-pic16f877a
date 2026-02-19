#include "timer.h"

void L_delay_ms(unsigned long t){
    OPTION_REG&=~(1<<3);//set the prescaler to TMR0
    OPTION_REG&=~(1<<5);//set TMR0 to count per instruction cycle
    OPTION_REG|=0x04;//assigning the prescaler as 1:16
    TMR0=0x65;//delay for 1 ms at 20 MHz 
    for(int i=0;i<=t){

        if(INTCON & (1<<2)){
            INTCON&=~(1<<2);
            TMR0=0x65;
            i++;}
    }

    
}