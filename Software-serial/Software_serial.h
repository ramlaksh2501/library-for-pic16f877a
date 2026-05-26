#ifndef SOFT_SERIAL


#define SOFT_SERIAL 



void soft_serial_begin();
void soft_serial_write(unsigned char * message);
void Soft_serial_write(unsigned char message);
unsigned char  soft_serial_read();

void L_delay_1ms(){
unsigned long t=1;
    OPTION_REG=0x04;
    INTCON=0x00;
    TMR0=0xf7;
    unsigned long i=0;
    while(i!=t){
        if(INTCON & (1<<2)){
              
        INTCON&=~(1<<2);
        i++;
        TMR0=0x65;
        }
}

}
#endif

