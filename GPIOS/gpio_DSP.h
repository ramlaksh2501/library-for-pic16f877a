#include "registers.h"


#ifndef GPIO
#define GPIO


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
#define  SETHIGH(n,port) (port=0xff)
#define  SETLOW(n,port)  (port=0x00)
void pin_config();
void port_config(char a,);
void pin_write();
void port_write(char a,);
void pin_read();
void port_read(char a,);
void led_blink();
void led_chase();




#endif