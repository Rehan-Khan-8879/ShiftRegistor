#define data PB0
#define clock PB1
#define latch PB2

void delay_ms(unsigned long ms);
void digiWrite(int pin,bool state);
void clockPulse();
void latchPulse();


int main(){
  DDRB = 0xff;
  PORTB = 0x00;
  while(true){

    //set all the led to HIGH one by one
    digiWrite(data,HIGH);
    delay_ms(200);
    for(int i =0;i<8;i++){
      clockPulse();
      latchPulse();
      delay_ms(2000);
    }
    //set all the led to LOW one by one
    digiWrite(data,LOW);
    delay_ms(200);
    for(int i=0;i<8;i++){
      clockPulse();
      latchPulse();
      delay_ms(2000);
    }
    //to set alternating led state
    for(int i=0;i<4;i++){
      //Set to high and pulse 
      digiWrite(data,HIGH);
      delay_ms(200);
      clockPulse();
      latchPulse();
      delay_ms(2000);
      //set to low and pulse
      digiWrite(data,LOW);
      delay_ms(200);
      clockPulse();
      latchPulse();
      delay_ms(2000);     
    }
  }
}

void clockPulse(){
  digiWrite(clock,HIGH);
  delay_ms(200);
  digiWrite(clock,LOW);
  delay_ms(200);
}

void latchPulse(){
  digiWrite(latch,HIGH);
  delay_ms(200);
  digiWrite(latch,LOW);
  delay_ms(200);
}

void digiWrite(int pin,bool state){
  if(state == HIGH){
    PORTB |= (1<<pin);
  }else if(state == LOW){
    PORTB &= ~(1<<pin);
  }
}

void delay_ms(unsigned long ms){
  for(unsigned long i = 0;i<ms;i++){
    for(unsigned long j=0;j<1000;j++){
      asm("");
    }
  }
}