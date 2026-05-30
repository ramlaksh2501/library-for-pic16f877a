#include"Software_serial.h"


void soft_serial_begin(){
	TRISB=~((1<<0));
	TRISB|=(1<<1);
	PORTB|=0x01;
}
void bit_delay(){
	unsigned long t=1;
	OPTION_REG=0x04;
	INTCON=0x00;
	TMR0=0xf4;
	unsigned long i=0;
	while(i!=t){
		if(INTCON & (1<<2)){

			INTCON&=~(1<<2);
			i++;
			TMR0=0x65;
		}

	}
}

unsigned char soft_serial_read(){
	unsigned char message=0;
	unsigned char n=0;
	if(!(PORTB&(1<<1))){
		while(n<=7){
			bit_delay();
			message|=((PORTB&(1<<1))<<n);
			n++;
		}	
	}
	else return 0;
	return message;
}


void Soft_serial_write(unsigned char message){
	bit_delay();
	PORTB&=~(0x01);
	bit_delay();
	unsigned char n=0;
	while(n<=7){
		if(1&(message>>n))
			PORTB|=0x01;
		else
			PORTB&=~(0x01);
		bit_delay();
		n++;
	}
	PORTB|=0x01;
}


void soft_serial_write(unsigned char* message){
	int i=0;
	for(i;message[i]!=0;i++){
		Soft_serial_write(message[i]);
	}
}
