#ifndef KEY 
#define KEY

void config_keypad();
unsigned char scan_keypad();//only use the keypad in port D no other ports are configured for keypad  
//start by connecting the row pins from lsb of portd from the bottom row to the top and then connect the columns from left to right 


#endif