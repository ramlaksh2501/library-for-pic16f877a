#ifndef I2C 

#define I2C 



void i2c_begin();
void i2c_write(unsigned char address, char * message);
unsigned char * i2c_read(unsigned char address);












#endif
