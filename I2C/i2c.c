#include"i2c.h"


void i2c_begin(){
	TRISC|=(3<<3);
	SSPCON|=(1<<3);//making master firmware mode
	SSPADD=0x0A;//making the communication 400khz
}

void i2c_write(unsigned char address, char * message){
	//     SSPCON|=(1<<5);
	//	SSPCON2|=1;
	//	while(!(PIR1&(1<<3)));
	//	PIR1&=~(1<<3);
	//	SSPBUF=address;
	//	while(!(PIR1&(1<<3)));
	//	PIR1&=~(1<<3);
	//SEND : if(!*message) goto END;
	//	SSPBUF=*message;
	//	while(!(PIR1&(1<<3)));
	//	PIR1&=~(1<<3);
	//	message+=1;
	//	goto SEND;
	//END :	SSPCON2|=1<<2;
	//	while(!(PIR1&(1<<3)));
	//	PIR1&=~(1<<3);
	if(*message==0) return ;
	SSPCON|=(1<<5); //enable serial communication making the pin 3 and 4 of portc as SCL and SDA
	SSPCON2|=1;//sending the start condition 
	while(!(PIR1&(1<<3)));//waiting for the start condition to finish  
	PIR1&=~(1<<3);
	SSPBUF=address<<1;//sending the address with write mode
	while(!(PIR1&(1<<3)));// waiting for ack bit 
	PIR1&=~(1<<3);
	while(*message){//checking for the valid message

		SSPBUF=*message;//sending the message
		while(!(PIR1&(1<<3)));//waiting for the ack
		PIR1&=~(1<<3);
		message+=1;//moving to the next character of the message
	}
	SSPCON2|=(1<<2);//sending the end condition 
	while(!(PIR1&(1<<3)));//waiting for the end condition to finish 
	PIR1&=~(1<<3);


}

unsigned char * i2c_read(unsigned char address,char *message,unsigned char size){
	address*=2;
	address|=1;//making the read bit one and shifting the address towards the msb
	unsigned char i=0;
	SSPCON|=(1<<3);//master mode
	SSPCON|=(1<<5);//enable serial port
	SSPCON2|=1;//start bit
	while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
	SSPBUF=address;//sending address with read bit as high
	while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
	while(1){
	SSPCON2|=(1<<3);//enable reciever mode as master
	  while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
    while(!(SSPSTAT&1));// waiting for the message to be loaded to sspbuf 	
	SSPCON2&=~(1<<5);//ack bit set
    *(message+i)=SSPBUF;
    //SSPBUF&=0;//clearing the buffer so the next byte will be shifted here(it must be done )
	SSPCON2|=(1<<4);//enable ack
	while(!(PIR1&(1<<3)));
	PIR1&=~(1<<3);
	i++;
    if(i<size) {}
    else break;} SSPBUF&=0;
    while(!(PIR1&(1<<3)));
PIR1&=~(1<<3);
	SSPCON2|=(1<<2);
	while(!(PIR1&(1<<3)));
PIR1&=~(1<<3);
    return message;

}

