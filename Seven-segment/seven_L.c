#include<gpio_DSP.h>
void config_sevenseg(){
       portconfig('b',OUTPUT);
       }
 

unsigned char sevenseg_L(unsigned char x){
       unsigned char digit[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}
       return digit[x];
}
unsigned char sevenseg_AL_(unsigned char x){
       unsigned char digit[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}
       return ~(digit[x]);
}
void config_sevenmux(){
 TRISB=0x00;
    TRISC&=~(0x015);
}
void mux_seven(){
   
   unsigned char ones,tens,hundreds,thousands;
    ones=x%10;
    tens=(x/10)%10;
    hundreds=(x/100)%10;
    thousands=(x/1000)%10;
    PORTB=0;
    PORTC=0;
    for(int i=0;i<10000;i++){
        PORTB=sevenseg_L(ones);
        PORTC=0x01;
        PORTC=0x00;
        PORTB=sevenseg_L(tens);
        PORTC=0x02;
        PORTC=0x00;
        PORTB=sevenseg_L(hundreds);
        PORTC=0x04;
        PORTC=0x00;
        PORTB=sevenseg_L(thousands);
        PORTC=0x08;
        PORTC=0x00;
        }

}