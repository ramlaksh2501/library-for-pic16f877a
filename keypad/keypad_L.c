void config_keypad(){
    TRISD=0xf0;
}
void scan_keypad(){

 while(1){char  i=0;
    while(i<4 ){
        //selects each row
        PORTD=(char)(1<<i);
        for(char j=1;j<=4;j++){
           
            if(PORTD & 1<<(3+j)){//checks each coulmn
                 if(i==0){
                if(j==1){//clear
                     return 14;
                    
                }
                if(j==2){//0
                    return 0;
                    
                }
                if(j==3){//=
                    return 15;
                }
                if(j==4){//+
                    return 10;
                }
            }
                 if(i>0){
}

                     if(j<=3){
                return  ((i-1)*3)+(j);//logic to display the right number
                     }
                     if(j==4){
                         if(i==1){ // -
                             return 11;
                 }
                         if(i==2){// *
                             return 12;
            }
                         if(i==3){
                             // division 
                             return 13;
                         }
      
    

                     }}}
                        i++;}
                    }     
    
}