#ifndef TIMERS
#define TIMERS
#define TMR_PRESCALE_1  0x00
#define TMR_PRESCALE_4  0x01
#define TMR_PRESCALE_16 0x03

//blocking
void L_delay_ms(unsigned long t);//all calculations are made in the 20MHz operation of the controller
void L_delay_s(unsigned long t);
void L_pwm();
void init_pwm(uint16_t duty);
void pwm_config(uint8_t pr2,uint8_t prescale ,uint16_t duty);
//void __interrupt() void  myhandler();
static inline void TMR1_ON  ();
static inline void TMR1_OFF ();
static inline void TMR2_ON  ();
static inline void TMR2_OFF ();
static inline void PWM_START();
static inline void PWM_STOP ();
//non blocking 
// a function to set time and a fucntions of the isr 
// for example timersISR(time_delay,funciton to run inside the isr after that time)
//a function to configure the isr 
// a function to start the isr
// a fucntion to stop using the timer interrupt

#endif