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