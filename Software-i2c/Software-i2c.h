#ifndef SI2C
#define SI2C

 static inline void start_condition();
 static inline void end_condition();
 static inline void clk_high();
 static inline void clk_low();
 static inline void data_high();
 static inline void data_low();
 void soft_i2c_init();//makes b6->scl and b7->sda
 void soft_i2c_write(unsigned char address,char *message);//send a string (collection of bytes
 void Soft_i2c_write(unsigned char address,unsigned char message);//send only one byte





#endif
