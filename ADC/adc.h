#ifndef ADC
#define ADC
typedef enum {
    zero=0,
    one ,
    two,
    three,
    four,
    five,
    six,
    seven=7
}ADC_pin;
void adc_on();
void adc_off();

uint16_t analog_read(ADC_pin x); // the return value will be in the range 0-1023 
// analog value is (return value/1024)*(ref voltage ) V
//by default the ref is 5 V (for more info refer datasheet)


#endif