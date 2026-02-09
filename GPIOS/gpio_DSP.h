#include "registers.h"


#ifndef GPIO
#define GPIO

typedef enum {
    output=0,
    input
}gpio_mode;


typedef enum {
   low=0,
   high
}pin_mode;


typedef enum gpio{
    zero=0,
    one,
    two,
    three,
    four,
    five,
    six,
    seven
}pin_rd;



//input parameter for all the read,write and config functions : ('A'- 'E') ,(0-7) except port E for port E(0-2)
void pin_config(char a,gpio_mode x,pin_rd p);//do not use port A
void port_config(char a,gpio_mode x);//do not use port A
void pin_write(char a,pin_mode x,pin_rd p);
void port_write(char a,pin_mode x);
void pin_read(char a,pin_rd p);
void port_read(char a);
void led_blink();//only in port b (entire port will blink)
void led_chase();//only in port b
void config_led();



#endif