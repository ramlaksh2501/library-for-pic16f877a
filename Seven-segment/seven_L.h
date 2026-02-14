#ifndef SEVEN 
#define SEVEN

void config_sevenseg();//any port can be used except port a and port e **for single digit 
unsigned sevenseg_L(unsigned char x);//need to assign the return value to the desired port ***input range : 0-9***
unsigned char sevenseg_AL_(unsigned char x);// for common anode
void config_sevenmux();//use port b for sevensegment connect from A of sevensegment  from lsb of portb and the 
//common cathode pins of each sevensegment from port C lsb ***refer example code for more details***
void config_sevenmux();
void mux_seven(unsigned int x);//only works in port b and c **four digits**



#endif