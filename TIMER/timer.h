#ifndef TIMERS
#define TIMERS
#define TMR1_ON  TMR1CON_BITS->STATUS=1;
#define TMR1_OFF TMR1CON_BITS->STATUS=0;
#define TMR2_ON  TMR2CON_BITS->STATUS=1;
#define TMR2_OFF TMR2CON_BITS->STATUS=0; 
//blocking
void L_delay_ms(unsigned long t);//all calculations are made in the 20MHz operation of the controller
void L_delay_s(unsigned long t);
void L_pwm(unsigned long long t);

void __interrupt() void  myhandler();

//non blocking 
// a function to set time and a fucntions of the isr 
// for example timersISR(time_delay,funciton to run inside the isr after that time)
//a function to configure the isr 
// a function to start the isr
// a fucntion to stop using the timer interrupt

#endif