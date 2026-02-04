#include<xc.h>
#include "/home/ramlaksh/learnings/pic-library/DSP.h"
void pinmode(int a,int b)
    {
        if(a>=33&&a<=40)
        {   if(b==0) 
            SETOUT(a-33,TRISB);
            else
            SETIN(a-33,TRISB);
        }
    }
void pinwrite(int a,int b)
    {
        if(a>=33&&a<=40)
        {   if(b==0) 
            SETLOW(a-33,PORTB);
            else
            SETHIGH(a-33,PORTB);
        }
    }
unsigned char sevenseg_L(unsigned char x){
    unsigned char digit[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,
        0x67,//+
        0x6d,//-
        0x46,//*
        0x5e,// /
        0x3e,//=
        0x39};//on/c
return digit[x];
}
void mux_seven(int x){//maximum three digits only 
// range:(000-999)
static char p;
if(p==0){
    TRISB=0x00;
    TRISC&=~(0x07);}
    char ones,tens,hundreds;
    ones=x%10;
    tens=(x/10)%10;
    hundreds=(x/100)%10;
    PORTB=0;
    PORTC=0;
    for(int i=0;i<10000;i++){
        PORTB=sevenseg_L(ones);
        PORTC=0x01;
//        __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(tens);
        PORTC=0x02;
  //      __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(hundreds);
        PORTC=0x04;
    //    __delay_ms(2);
        PORTC=0x00; }

}
void mux_seven_direct(char x,char y,char z){//maximum three digits only 
// range:(000-999)
//u must make the port b all output 
//and port c's three LSBs as input before using this function
    PORTB=0x00;
        PORTB=sevenseg_L(x);
        PORTC=0x01;
//        __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(y);
        PORTC=0x02;
  //      __delay_ms(2);
        PORTC=0x00;
        PORTB=sevenseg_L(y);
        PORTC=0x04;
   //     __delay_ms(2);
        PORTC=0x00; 

}
void general_mux_seven_direct(char x,char y,char z,volatile unsigned char *oport,volatile unsigned char *cport){//maximum three digits only 
//range:(000-999)
//oport is the sevensegment 
//cport is for selection (LSBs)
static char w;
if(!w){
    *(oport+80)=0x00;
     *(cport+80)&=~(0x07);}   
     for(int m=0;m<10000;m++){
    *oport=sevenseg_L(x);
        *cport=0x01;
 
        *cport=0x00;
     *oport=sevenseg_L(y);
        *cport=0x02;
 
        *cport=0x00;}
}
unsigned char keypadread(){
    //only use the keypad in port b for this function to work 
    //first four pins are for the output which turn on each row 
    //second four pins are for the input which reads the keypad
       char  i=0;
    while(i<4 ){
        //selects each row
        PORTB=(char)(1<<i);
        for(char j=1;j<=4;j++){
           
            if(PORTB & 1<<(3+j)){//checks each coulmn
                 if(i==0){
                if(j==1){//clear
                     return sevenseg_L(15);
                    
                }
                if(j==2){//0
                    return sevenseg_L(0);
                    
                }
                if(j==3){//=
                    return sevenseg_L(14);
                }
                if(j==4){//+
                    return sevenseg_L(10);
                }
            }
                 if(i>0){
}

                     if(j<=3){
                return  sevenseg_L(((i-1)*3)+(j));//logic to display the right number
                     }
                     if(j==4){
                         if(i==1){ // -
                             return sevenseg_L(11);
                 }
                         if(i==2){// *
                             return sevenseg_L(12);
            }
                         if(i==3){
                             // division 
                             return sevenseg_L(13);
                         }
      
    

                     }}}
                        i++;}
                        return 0;
    
}