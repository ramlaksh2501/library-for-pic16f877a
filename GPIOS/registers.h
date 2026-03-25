#ifndef REGISTERS
#define REGISTERS
#include<stdint.h>


#define PORTA        (*((volatile char *) 0X05))
#define TRISA        (*((volatile char *) 0X85))
#define PORTB        (*((volatile char *) 0X06))
#define TRISB        (*((volatile char *) 0X86))
#define PORTC        (*((volatile char *) 0X07))
#define TRISC        (*((volatile char *) 0X87))
#define PORTD        (*((volatile char *) 0X08))
#define TRISD        (*((volatile char *) 0X88))
#define PORTE        (*((volatile char *) 0X09))
#define TRISE        (*((volatile char *) 0X89))
#define INTCON       (*((volatile char *) 0X0b)) 
#define TMR0         (*((volatile char *) 0X01))
#define OPTION_REG   (*((volatile char *) 0X81))
#define TMR1L        (*((volatile char *) 0x0E))
#define TMR1H        (*((volatile char *) 0x0F))  
#define T1CON        (*((volatile char *) 0x10))
#define TMR2         (*((volatile char *) 0x11))    
#define T2CON        (*((volatile char *) 0x12))    
#define PR2          (*((volatile char *) 0x92))
#define PIR1         (*((volatile char *) 0x0C))
#define PIE1         (*((volatile char *) 0x8C)) 
#define PIR2         (*((volatile char *) 0x0D))
#define PIE2         (*((volatile char *) 0x8D))
#define CCPR1L       (*((volatile char *) 0x15))
#define CCPR1H       (*((volatile char *) 0x16))
#define CCP1CON      (*((volatile char *) 0x17))
#define CCPR2L       (*((volatile char *) 0x1B))
#define CCPR2H       (*((volatile char *) 0x1C))
#define CCP2CON      (*((volatile char *) 0x1D))
#define ADCON0       (*((volatile char *) 0x1f))
#define ADCON1       (*((volatile char *) 0x9f))
#define ADRESH       (*((volatile char *) 0x1e))
#define ADRESL       (*((volatile char *) 0x9E))


/* need bitfield for 
T1 con-
t2con -
ccp1con-
ccp2con -
pie 1 2 -
pir 1 2 -
*/
typedef struct {
    unsigned int PRESCALE   :2;
    unsigned int STATUS     :1;
    unsigned int POSTSCALE  :4;
    unsigned int unassigned :1;
}t2_con ;

typedef struct { 
    unsigned int STATUS     :1;
    unsigned int SOURCE     :1;
    unsigned int SYNC       :1;
    unsigned int OSCEN      :1;
    unsigned int PRESCALE   :2;
    unsigned int unassigned :2;
}t1_con;

typedef struct {
    unsigned int MODE       :4;
    unsigned int PWM        :2;
    unsigned int unassigned :2;
}ccp_con;

typedef struct {
    unsigned int TMR1IE     :1;
    unsigned int TMR2IE     :1;
    unsigned int CCP1IE     :1;
    unsigned int SSPIE      :1;
    unsigned int TXIE       :1;
    unsigned int RCIE       :1;
    unsigned int ADIE       :1;
    unsigned int PSIE       :1;
}pie_1;

typedef struct {
    unsigned int CCP2IE     :1;
    unsigned int unassigned :2;
    unsigned int BCLIE      :1;
    unsigned int unsa       :1;
    unsigned int CMIE       :1;
    unsigned int unss       :1;
}pie_2;

typedef struct {
    unsigned int TMR1IF     :1;
    unsigned int TMR2IF     :1;
    unsigned int CCP1IF     :1;
    unsigned int SSPIF      :1;
    unsigned int TXIF       :1;
    unsigned int RCIF       :1;
    unsigned int ADIF       :1;
    unsigned int PSPIF      :1;
}pir_1;

typedef struct {
    unsigned int CCP2IF     :1;
    unsigned int unassigned :2;
    unsigned int BLCIF      :1;
    unsigned int EEIF       :1;
    unsigned int notused    :1;
    unsigned int CMIF       :1;
    unsigned int na         :1;
}pir_2;



typedef struct {
    unsigned int ADON       :1;
    unsigned int unassigned :1;
    unsigned int DONE       :1;
    unsigned int CHS0       :1;
    unsigned int CHS1       :1;
    unsigned int CHS2       :1;
    unsigned int ADCS0      :1;
    unsigned int ADCS1      :1;

}adcon_0;
typedef struct {
    unsigned int PCFG0      :1;
    unsigned int PCFG1      :1;
    unsigned int PCFG2      :1;
    unsigned int PCFG3      :1;
    unsigned int unassigned :2;
    unsigned int ADCS2      :1;
    unsigned int ADFM       :1;
}adcon_1;





#define TMR2CON_BITS ((volatile t2_con *)0x12)
#define TMR1CON_BITS ((volatile t1_con *)0x10)
#define CCP1CON_BITS ((volatile ccp_con*)0x17)
#define CCP2CON_BITS ((volatile ccp_con*)0x1D)
#define PIE_1_BITS   ((volatile pie_1  *)0x8C)
#define PIR_2_BITS   ((volatile pir_2  *)0x0C)
#define ADCON0_BITS  ((volatile adcon_0*)0x1f)
#define ADCON1_BITS  ((volatile adcon_1*)0x9f)



















#endif