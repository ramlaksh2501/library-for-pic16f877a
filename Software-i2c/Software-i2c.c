#include"Software-i2c.h"

static inline void start_condition(){
data_low();
clk_low();}
static inline void stop_condition(){
	 data_low();
	 clk_high();
data_high();
}
static inline void data_high(){
	PORTB|=(1<<7);}
static inline void clk_low(){
	PORTB&=~(1<<6);}
static inline void clk_high(){
	PORTB|=(1<<6);}
static inline void data_low(){
	PORTB&=~(1<<7);}



void soft_i2c_init(){
	PORTB|=(0xC0);
	TRISB&=~(0xC0);
   //b6 ->scl
   //b7->sda 
PORTB|=(0xC0);
}

void Soft_i2c_write(unsigned char address,unsigned char message){
int bit=0x07;
address*=2;
start_condition();
while(bit>=0){
if(address&(1<<bit)) data_high();
else data_low();
clk_high();
clk_low();
bit--;
}
clk_high();
clk_low();

bit=0x07;
while(bit>=0){
if(message&(1<<bit)) data_high();
else data_low();
clk_high();
clk_low();
bit--;
}
clk_high();
clk_low();


stop_condition();
}






