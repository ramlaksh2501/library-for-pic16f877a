#ifndef SEVEN 
#define SEVEN

void config_sevenseg();//any port can be used except port a and port e 
void config_sevenseg_anode();//for common anode sevensegments
void sevenseg_L_();//for common anode
void sevenseg_L();//need to assign the return value to the desired port 
void mux_seven();//only works in port b and c
void mux_seven_digits();//only works in port b and c


#endif