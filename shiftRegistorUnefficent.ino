#define data PB0
#define clock PB1
#define latch PB2

int main(){
  DDRB = 0xff;
  PORTB = 0x00;
    /*PORTB |= (1<<PB0);
      delay_ms(100);
    PORTB |= (1<<PB1);
      delay_ms(100);
    PORTB &= ~(1<<PB1);
      delay_ms(100);
    PORTB |= (1<<PB2);
      delay_ms(100);*/
    while(true){
      digiWrite(data,HIGH);
        delay_ms(200);
      for(int i =0;i<=8;i++){
        digiWrite(clock,HIGH);
        delay_ms(200);
        digiWrite(clock,LOW);
          digiWrite(latch,HIGH);
          delay_ms(200);
          digiWrite(latch,LOW);
          delay_ms(200);
      }
      digiWrite(latch,HIGH);
      delay_ms(200);
      digiWrite(latch,LOW);
      delay_ms(200);
      
      digiWrite(data,LOW);
        delay_ms(200);
      for(int i =0;i<=8;i++){
        digiWrite(clock,HIGH);
        delay_ms(200);
        digiWrite(clock,LOW);
          digiWrite(latch,HIGH);
          delay_ms(200);
          digiWrite(latch,LOW);
          delay_ms(200);
      }
      digiWrite(latch,HIGH);
      delay_ms(200);
      digiWrite(latch,LOW);
      delay_ms(200);
//      digiWrite(data,LOW);
      delay_ms(200);
      digiWrite(data,HIGH);
        delay_ms(200);
      digiWrite(clock,HIGH);
        delay_ms(200);
      digiWrite(clock,LOW);
        delay_ms(200);
      digiWrite(data,LOW);
        delay_ms(200);
      digiWrite(clock,HIGH);
        delay_ms(200);
      digiWrite(clock,LOW);
        delay_ms(200);
      digiWrite(latch,HIGH);
        delay_ms(200);
      digiWrite(latch,LOW);
        delay_ms(3000);
    }
}

int digiWrite(int pin,bool state){
  if(state == HIGH){
    PORTB |= (1<<pin);
  }else if(state == LOW){
    PORTB &= ~(1<<pin);
  }
}


void delay_ms(unsigned int ms){
  for(unsigned long i = 0;i<ms;i++){
    for(unsigned long j = 0;j<1000;j++){
      asm("");
    }
  }
}




/*
void setup(){
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(100);


    digitalWrite(8,HIGH);
  delay(100);
  digitalWrite(9,HIGH);
  delay(100);
  digitalWrite(9,LOW);
  delay(100);
    digitalWrite(9,HIGH);
  delay(100);
  digitalWrite(9,LOW);
  delay(100);
  digitalWrite(10,HIGH);
  delay(100);
}
void loop(){

}*/