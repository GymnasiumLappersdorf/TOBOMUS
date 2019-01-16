int MotorPin1 = 5;
int MotorPin2 = 6;
int MotorPin3 = 9;
int MotorPin4 = 10;
int MotorR = 180;
int MotorL = 180;
String Nummer;
void setup() {

  // put your setup code here, to run once:
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);
}

void loop() {
  Fahren(100, 0.5)
}
void Fahren(int Geschwindigkeit, double Richtung) {
  //Richtung ist ein wert zwischen 0 und 2. 1 neutral; >1 nach rechts <1 nach links
  //auf die motoren berechnen
  MotorR = Geschwindigkeit * Richtung;
  MotorL = Geschwindigkeit * (1 / Richtung);
  
  if (MotorR > 255) {
    MotorL = MotorL - (MotorR - 255);// das überschüssige vom anderen Motor abziehen
    MotorR = 255;//den motor auf das Maximum setzten
  }
  if (MotorL > 255) {
    MotorR = MotorR - (MotorL - 255);// das überschüssige vom anderen Motor abziehen
    MotorL = 255;//den motor auf das Maximum setzten
  }
  //Linker Motor
  if (MotorR > 0) {
    analogWrite(MotorPin2, 0);
    analogWrite(MotorPin1, MotorR);
  }
  if (MotorR < 0) {
    analogWrite(MotorPin1, 0);
    analogWrite(MotorPin2, (-MotorR));
  }
  if (MotorR == 0) {
    analogWrite(MotorPin2, 0);
    analogWrite(MotorPin1, 0);
  }
  //Linker Motor
  if (MotorL > 0) {
    analogWrite(MotorPin3, 0);
    analogWrite(MotorPin4, MotorL);
  }
  if (MotorL < 0) {
    analogWrite(MotorPin4, 0);
    analogWrite(MotorPin3, (-MotorL));
  }
  if (MotorL == 0) {
    analogWrite(MotorPin3, 0);
    analogWrite(MotorPin4, 0);
  }
}

