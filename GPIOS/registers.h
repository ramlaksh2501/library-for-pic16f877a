#ifndef REGISTERS
#define REGISTERS


#define ADCON1       (*((volatile char *) 0x9f))
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



/* need bitfield for 
T1 con-
t2con -
ccp1con-
ccp2con -
pie 1 2 
pir 1 2  
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


#define TMR2CON_BITS ((volatile t2_con *)0x12);
#define TMR1CON_BITS ((volatile t1_con *)0x10);
#define CCP1_CON     ((volatile ccp_con*)0x17);
#define CCP2_CON     ((volatile ccp_con*)0x1D);
#define PIE_1        ((volatile pie_1  *)0x8C);


















#endif