int ledPins[6] = {2, 3, 4, 5, 6, 7};
int numberOfLeds = 6;

int trigPin = 10;
int echoPin = 11;
int buzzerPin = 9;
// buzzer + pin 9 , - GND  , and add 220 Ohms  
int travelTime;
int distance;

void setup() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  sendSoundWave();
  travelTime = pulseIn(echoPin, HIGH);
  distance = travelTime * 0.034 / 2;

  if (distance <= 20) {

    int n = map(distance, 0, 20, numberOfLeds, 0);

    for (int i = 0; i < numberOfLeds; i++) {
      if (i < n) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
 
    if (distance <= 3) {
      digitalWrite(buzzerPin, HIGH);   
            
    } else {
      digitalWrite(buzzerPin, LOW);
      
    }

  } else {
     
    for (int i = 0; i < numberOfLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    digitalWrite(buzzerPin, LOW);
     
  }

  delay(10);
}

void sendSoundWave() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}
