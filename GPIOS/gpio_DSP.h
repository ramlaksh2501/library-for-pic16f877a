/* author : LAKSH */

#include "registers.h"


#ifndef GPIO
#define GPIO



typedef enum gpio{
    zero=0,
    one,
    two,
    three,
    four,
    five,
    six,
    seven=7
}pin_rd;

/*****chars are signed here so use hex or binary to pass arguments****/


//input parameter for all the read,write and config functions : ('A'- 'E') ,(0-7) except port E for port E(0-2)
void pin_config(char a,unsigned char x,unsigned char  p);//do not use port A
void port_config(char a,unsigned char  x);//do not use port A
void pin_write(char a,unsigned char  x,unsigned char p);
void port_write(char a,char x);
char pin_read(char a,unsigned char  p);//returns 0 or one
char port_read(char a);//returns the entire register of the port
void led_blink();//only in port b (entire port will blink)
void led_chase();//only in port b
void config_led();//enables portb 
void delayms_L(unsigned long int x);//close to one ms at 20 MHz


#endif
