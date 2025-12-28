const int trag = 10 ;
const int echo = 11 ; 
long duration ;
int distance ;
const int led1 = 2 ;
const int led2 = 3 ;
const int led3 = 4 ;

void setup() {
   pinMode(trag,OUTPUT);
   pinMode(echo,INPUT);
   pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
     pinMode(led3,OUTPUT);
}

void loop(){
  digitalWrite(trag,LOW);
  delayMicroseconds(2);
  digitalWrite(trag,HIGH);
   delayMicroseconds(10);
   digitalWrite(trag,LOW);

   duration = pulseIn(echo,HIGH);
   distance = duration * 0.034 / 2 ; 


   if (distance <= 30) {
    digitalWrite(led3,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
   }
   else if ( distance <= 50 && distance > 30 ){
     digitalWrite(led3,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
   }
   else {
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
   }

}
