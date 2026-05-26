#define UART_INC
#ifndef UART_INC 


//need a funciton for write and read 
//need a function for configuring the read and write baud_rate or give a default serial begin funciton 

void serial_begin();//default for 9600 baud rate if you want a custom baudrate change the respective registers (refer datasheet)
void serial_write(char * send);
char  serial_read();



#endif
