#include <Servo.h>

int degree = 15;
int hoch = 1;

unsigned long oldMillis = millis + 2000;

Servo myServo;

const int trigPin = 10;
const int echoPin = 11;
unsigned long timespan;
float distance;

void setup() {
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  unsigned long currMillis = millis;

  if ((hoch == 1) && (oldMillis >= currMillis)) {
    degree++;
    if (degree > 165) {
      hoch = 0;
    }
  } else {
    degree--;
    if (degree < 15) {
      hoch = 1;
    }
  }
  myServo.write(degree);
    Serial.print(degree);
    Serial.print(" , ");
    Serial.println(calculateDistance());
    Serial.println(timespan);
  oldMillis = currMillis + 10;
}

float calculateDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  timespan = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = timespan * 0.034 / 2;
  return distance;
}
