#ifndef ADCIN
#define ADCIN


#include "adc.h"


uint16_t analog_read(ADC_pin x){

    ADCON1|=1<<6; //initializing analog pins
    ADCON0|=(x<<3);//selecting the input pin
    ADCON1|=(1<<7);//making the result left justified
    ADCON0|=1;//turning on the adc
    ADCON0|=1<<2;//starting the conversion
    while(ADCON0 & 1<<2);//checking if the conversion completed
    uint16_t res=0;
    res=(uint16_t)ADRESH<<7 | ADRESL;//storing the result
    return res;
}




#endif