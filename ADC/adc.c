#ifndef ADCIN
#define ADCIN


#include "adc.h"


uint16_t analog_read(ADC_pin x){

    ADCON1|=1<<6;
    ADCON0|=(x<<3);
    ADCON1|=(1<<7);
    ADCON0|=1<<2;
    while(ADCON0 & 1<<2);
    uint16_t res=0;
    res=(uint16_t)ADRESH<<7 | ADRESL;
    return res;
}




#endif