#include"i2c.h"


void i2c_begin(){
	TRISC|=(0x03<<3);
	TRISC|=(3<<3);
	SSPCON|=(1<<3);
}

void i2c_write(unsigned char address,char * message){
	SSPCON|=(1<<5);
	SSPCON2|=1;
	while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
	SSPBUF=address;
	while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
SEND : if(!*message) goto END;
	SSPBUF=*message;
	while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
	message+=1;
	goto SEND;
END :	SSPCON2|=1<<2;
	while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
}

