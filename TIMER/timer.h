#ifndef TIMERS
#define TIMERS

//blocking
void L_delay_ms(unsigned long t);
void L_delay_s(unsigned long t);

//non blocking 
// a function to set time and a fucntions of the isr 
// for example timersISR(time_delay,funciton to run inside the isr after that time)
//a function to configure the isr 
// a function to start the isr
// a fucntion to stop using the timer interrupt

#endif