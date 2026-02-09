#include "gpio_DSP.h"

#ifndef GPC

#define GPC

#define  INPUT  1
#define  OUTPUT 0
#define  SETIN(n,port)  (port|=1<<(n))
#define  SETOUT(n,port) (port&=~(1<<(n)))
#define  SETPIN(port)  (port=0xff)
#define  SETPOUT(port) (port=0x00)
#define  HIGH  1
#define  LOW   0
#define  SETHIGH(n,port) (port|=1<<(n))
#define  SETLOW(n,port)  (port&=~(1<<(n)))
#define  SETPHIGH(port) (port=0xff)
#define  SETPLOW(port)  (port=0x00)

void pin_config(char a,gpio_mode x,pin_rd p){
    if(x==INPUT){switch(a){
        case 'a':
        case 'A' : ADCON1=0x06;
        SETIN(p,TRISA);
        break;
        case 'b' :
        case'B':SETIN(p,TRISB);
        break;
        case 'c':
        case 'C' :SETIN(p,TRISC);
        break;
        case 'd' :
        case 'D' :SETIN(p,TRISA);
        break;
        case 'e' :
        case 'E' :  SETIN(p,TRISA);
        break;  
    
    }}

   else{switch(a){
        case 'a':
        case 'A' : ADCON1=0x06;
        SETOUT(p,TRISA);
        break;
        case 'b' :
        case'B':SETOUT(p,TRISB);
        break;
        case 'c':
        case 'C' :SETOUT(p,TRISC);
        break;
        case 'd' :
        case 'D' :SETOUT(p,TRISA);
        break;
        case 'e' :
        case 'E' :  SETOUT(p,TRISA);
        break;  
    
    }}
}
void port_config(char a,gpio_mode x){
    if(x==INPUT){switch(a){
        case 'a':
        case 'A' : ADCON1=0x06;
        SETPIN(TRISA);
        break;
        case 'b' :
        case'B':   SETPIN(TRISA);
        break;
        case 'c':
        case 'C' :   SETPIN(TRISA);
        break;
        case 'd' :
        case 'D' :   SETPIN(TRISA);
        break;
        case 'e' :
        case 'E' :   SETPIN(TRISA);
        break;  
    
    }}

   else{switch(a){
        case 'a':
        case 'A' : ADCON1=0x06;
        SETOUT(p,TRISA);
        break;
        case 'b' :
        case'B':SETOUT(p,TRISB);
        break;
        case 'c':
        case 'C' :SETOUT(p,TRISC);
        break;
        case 'd' :
        case 'D' :SETOUT(p,TRISA);
        break;
        case 'e' :
        case 'E' :  SETOUT(p,TRISA);
        break;  
    
    }}
}
void pin_write(char a,pin_mode x,pin_rd p){
    if(x==HIGH){switch(a){
        case 'a':
        case 'A' :SETHIGH(p,PORTA);
        break;
        case 'b' :
        case'B':SETHIGH(p,PORTB);
        break;
        case 'c':
        case 'C' :SETHIGH(p,PORTC);
        break;
        case 'd' :
        case 'D' :SETHIGH(p,PORTD);
        break;
        case 'e' :
        case 'E' :  SETHIGH(p,PORTE);
        break;  
    
    }}

   else{switch(a){
        case 'a':
        case 'A' : 
        SETLOW(p,PORTA);
        break;
        case 'b' :
        case'B':SETLOW(p,PORTB);
        break;
        case 'c':
        case 'C' :SETLOW(p,PORTC);
        break;
        case 'd' :
        case 'D' :SETLOW(p,PORTD);
        break;
        case 'e' :
        case 'E' :  SETLOW(p,PORTE);
        break;  
    
    }}
}
void port_write(char a,pin_mode x);
void pin_read(char a,pin_rd);
void port_read(char a);
void config_led(){
    SETPOUT(TRISB);
}
void led_blink(){//only in port b (entire port will blink)
  
       SETPHIGH(PORTB);
        for(unsigned long int i=0;i<70000;i++);
        SETPLOW(PORTB);
        for(unsigned long int i=0;i<70000;i++);
    

}
void led_chase(){
    for(char a=0;a<8;a++){
        PORTB=(char) x<<a;
        for(unsigned long int i=0;i<70000;i++);
    }
}








#endif