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


#define  INPUT  1
#define  OUTPUT 0
#define  SETIN(n,port)  (port|=1<<(n))
#define  SETOUT(n,port) (port&=~(1<<(n)))
#define  SETPIN(n,port)  (port=0xff)
#define  SETPOUT(n,port) (port=0x00)
#define  HIGH  1
#define  LOW   0
#define  SETHIGH(n,port) (port|=1<<(n))
#define  SETLOW(n,port)  (port&=~(1<<(n)))
#define  SETPHIGH(n,port) (port=0xff)
#define  SETPLOW(n,port)  (port=0x00)
//input parameter for all the read,write and config functions : ('A'- 'E') ,(0-7) except port E for port E(0-2)
void pin_config(char a,gpio_mode x);
void port_config(char a,gpio_mode x);
void pin_write(char a,pin_mode x);
void port_write(char a,pin_mode x);
void pin_read(char a,pin_rd);
void port_read(char a);
void led_blink();//only in port b (entire port will blink)
void led_chase();//only in port b




#endif