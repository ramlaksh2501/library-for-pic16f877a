#include"soft.h"




void soft_serial_begin(){
	TRISB=~((1<<0));
	TRISB|=(1<<1);

}


unsigned char soft_serial_read(){

	unsigned char message=0;
	unsigned char n=0;
	if(!(PORTB&(1<<1))){
		while(n<=7){
			L_delay_1ms();
			message|=((PORTB&(1<<1))<<n);
		}	
	}
	else return 0;
	return message;
}







void Soft_serial_write(unsigned char message){
	L_delay_1ms();
	PORTB&=~(0x01);
	L_delay_1ms();
	unsigned char n=0;
	while(n<=7){
		if(1&(message>>n))
			PORTB|=0x01;
		else
			PORTB&=~(0x01);
		L_delay_1ms();
		n++;
	}
	L_delay_1ms();
	PORTB|=0x01;
}
