#include "timer.h"

void L_delay_ms(unsigned long t){
   
    // OPTION_REG&=~(1<<3);//set the prescaler to TMR0
    // OPTION_REG&=~(1<<5);//set TMR0 to count per instruction cycle
    // INTCON|=(1<<7);//enable global interrupt
    // OPTION_REG|=(1<<2);//assigning the prescaler as 1:16
    // INTCON&=~(1<<2);
    OPTION_REG=0x04;
    INTCON=0x00;
    TMR0=0x65;//delay for 1 ms at 20 MHz 
    
    unsigned long i=0;
    while(i!=t){
        if(INTCON & (1<<2)){
              
        INTCON&=~(1<<2);
        i++;
        TMR0=0x65;
        }
}

}