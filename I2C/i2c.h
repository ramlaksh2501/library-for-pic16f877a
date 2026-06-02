#ifndef I2C 

#define I2C 



void i2c_begin();
void i2c_write(unsigned char address, char * message);//7 bit address of the i2c device and the pointer to the message to be sent (must be null terminated)
unsigned char * i2c_read(unsigned char address,char *message,unsigned char size);//a pointer to the recived msg is returned 











#endif
