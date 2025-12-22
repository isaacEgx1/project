int ledPins[6] = {2, 3, 4, 5, 6, 7};
int numberOfLeds = 6;

int trigPin = 10;
int echoPin = 11;
int travelTime;
int distance;

void setup() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  sendSoundWave();                       // Send sound wave
  travelTime = pulseIn(echoPin, HIGH);   // Get travel time
  distance = travelTime * 0.034 / 2;     // Distance in cm

  if (distance <= 20) {
    // عدد الليدات اللي هتنور حسب المسافة
    int n = map(distance, 0, 20, numberOfLeds, 0);

    for (int i = 0; i < numberOfLeds; i++) {
      if (i < n) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }

  } else {
    // إطفاء كل الليدات
    for (int i = 0; i < numberOfLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(500);
}

void sendSoundWave() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}
