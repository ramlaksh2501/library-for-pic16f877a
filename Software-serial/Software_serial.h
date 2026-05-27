#ifndef SOFT_SERIAL


#define SOFT_SERIAL 



void soft_serial_begin(); //initialize the softserial ( B0->Tx , B1->Rx ) at 9600 baudrate
void soft_serial_write(unsigned char * message);//write a string via the serial one after another 
void Soft_serial_write(unsigned char message);//write a single byte via the serial (one byte)
unsigned char  soft_serial_read();// read a byte from the serial receiver 
void bit_delay();// delay for each bit at 9600 baudrate
#endif

