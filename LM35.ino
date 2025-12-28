 
const int lm35 = A1;
const int led = 9 ;
const int buzzer = 10 ;

float sensorVolage ;
float voltage ;
float temp ;

void setup() {
 pinMode(led, OUTPUT);
 pinMode(buzzer,OUTPUT);
}

void loop(){
  sensorVolage = analogRead(lm35);
  voltage = sensorVolage * (5.0 / 1023.0);
  temp = voltage * 100 ;

  if (temp > 30 ){

    digitalWrite(led , HIGH);
    digitalWrite(buzzer, HIGH);

  }
  else {
    digitalWrite(led , LOW);
    digitalWrite(buzzer,LOW);
  }



}
