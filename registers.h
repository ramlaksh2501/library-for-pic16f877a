#ifndef REGISTERS

#define REGISTERS


#define ADCON1 (*((volatile char *) 0x9f))
#define PORTA  (*((volatile char *) 0X05))
#define TRISA  (*((volatile char *) 0X85))
#define PORTB  (*((volatile char *) 0X06))
#define TRISB  (*((volatile char *) 0X86))
#define PORTC  (*((volatile char *) 0X07))
#define TRISC  (*((volatile char *) 0X87))
#define PORTD  (*((volatile char *) 0X08))
#define TRISD  (*((volatile char *) 0X88))
#define PORTE  (*((volatile char *) 0X09))
#define TRISE  (*((volatile char *) 0X89))
#define INTCON (*((volatile char *) 0X0b)) 
#define TMR0   (*((volatile char *) 0X01))
#define OPTION_REG (*((volatile char *) 0X81))


#endif