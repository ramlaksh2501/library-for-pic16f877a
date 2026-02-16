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
        case'B':   SETPIN(TRISB);
        break;
        case 'c':
        case 'C' :   SETPIN(TRISC);
        break;
        case 'd' :
        case 'D' :   SETPIN(TRISD);
        break;
        case 'e' :
        case 'E' :   SETPIN(TRISE);
        break;  
    
    }}

   else{switch(a){
        case 'a':
        case 'A' : ADCON1=0x06;
        SETPOUT(TRISA);
        break;
        case 'b' :
        case'B':SETPOUT(TRISB);
        break;
        case 'c':
        case 'C' :SETPOUT(TRISC);
        break;
        case 'd' :
        case 'D' :SETPOUT(TRISD);
        break;
        case 'e' :
        case 'E' :  SETPOUT(TRISE);
        break;  
    
    }}
}
void pin_write(char a,pin_mode x,pin_rd p){
    if(x==HIGH){switch(a){
        case 'a':
        case 'A' :
        SETHIGH(p,PORTA);
        break;
        case 'b' :
        case'B':
        SETHIGH(p,PORTB);
        break;
        case 'c':
        case 'C' :
        SETHIGH(p,PORTC);
        break;
        case 'd' :
        case 'D' :
        SETHIGH(p,PORTD);
        break;
        case 'e' :
        case 'E' :  
        SETHIGH(p,PORTE);
        break;  
    
    }}

   else{switch(a){
        case 'a':
        case 'A' : 
        SETLOW(p,PORTA);
        break;
        case 'b' :
        case'B':
        SETLOW(p,PORTB);
        break;
        case 'c':
        case 'C' :
        SETLOW(p,PORTC);
        break;
        case 'd' :
        case 'D' :
        SETLOW(p,PORTD);
        break;
        case 'e' :
        case 'E' : 
        SETLOW(p,PORTE);
        break;  
    
    }}
}
void port_write(char a,char x){
    switch(a){
        case 'a':
        case 'A' : 
        PORTA=x;
        break;
        case 'b' :
        case'B':
        PORTB=x;
        break;
        case 'c':
        case 'C' :
       PORTC=x;
        break;
        case 'd' :
        case 'D' :PORTD=x;
        break;
        case 'e' :
        case 'E' :  PORTE=x;
        break;  
    
    }

}
char pin_read(char a,pin_rd p){
     switch(a){
        case 'a':
        case 'A' : 
       return (PORTA>>p) &1  ;
        break;
        case 'b' :
        case 'B' :
         return (PORTB>>p) &1  ;
        break;
        case 'c':
        case 'C':
        return (PORTC>>p) &1  ;
        break;
        case 'd' :
        case 'D' :
       return (PORTD>>p) &1  ;
        break;
        case 'e' :
        case 'E':
         return (PORTE>>p) &1  ;
        break;  
    
    }

}
char port_read(char a){
    switch(a){
        case 'a':
        case 'A' : 
       return PORTA;
        break;
        case 'b' :
        case 'B':
        return PORTB;
        break;
        case 'c':
        case 'C':
       return PORTC;
        break;
        case 'd' :
        case 'D' :
       return PORTD;
        break;
        case 'e' :
        case 'E' :
         return PORTE;
        break;  
    
    }
}
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
        PORTB=(char) 1<<a;
        for(unsigned long int i=0;i<70000;i++);
    }
}


void delayms_L(unsigned long int  x){
    for(unsigned long int i=0;i<=x;i++){
        for(unsigned long    int y=0;y<200;y++);
    }
}






#endif