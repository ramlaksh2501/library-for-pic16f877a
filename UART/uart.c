#include "uart.h"


serial_begin(){
    //for the sender (TX)
    TRISC=(1<<6);
    TRISC=(1<<7);
    TXSTA=(1<<2);
    TXSTA=(1<<5);   
    SPBRG=(unsigned char)129;
    RCSTA=(unsigned char)(1<<7);
    //for the receiver (RX)
    //need to figure out how to configure it 
}


serial_write(char * send){
	unsigned char i=0;
	while(send[i]!=0){
		TXREG=send[i];
	}
}
