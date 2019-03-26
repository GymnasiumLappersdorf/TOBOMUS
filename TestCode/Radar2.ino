#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int degree = 15;
int hoch = 1;
int list[200];

unsigned long oldMillis = millis + 2000;

Servo myServo;

const int trigPin = 10;
const int echoPin = 11;
float distance;


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  unsigned long currMillis = millis;
  
  if ((hoch == 1) && (oldMillis >= currMillis)) {
    degree+=10;
    if (degree > 165) {
      hoch = 0;
    }
  } else {
    degree-=10;
    if (degree < 15) {
      hoch = 1;
    }
  }
  myServo.write(degree);
  distance=calculateDistance();
    list[degree]=distance;
  oldMillis = currMillis + 10;
}

float calculateDistance() {

  int distance=sonar.ping_cm();
  if(distance>0){
  Serial.println(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  
  }else{
    distance=500;
    }
  delay(35);
  return distance;
}
