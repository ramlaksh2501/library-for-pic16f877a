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
unsigned short adc();//for pin A0
unsigned short analog_read(ADC_pin x);
unsigned short sleep_adc();//for pin A0
unsigned short analog_read(ADC_pin x){
    
}
#endif