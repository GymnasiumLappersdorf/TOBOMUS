int MotorPin1 = 5;
int MotorPin2 = 6;
int MotorPin3 = 9;
int MotorPin4 = 10;
int MotorR = 180;
int MotorL = 180;
String Nummer;

int color = 0; //Die standart farbe für das blatt

//Sensor 1 => 13 Pin
//Sensor 2 => 12 Pin
//Sensor 3 => 22 Pin
//Sensor 4 => 24 Pin


int LSensor[4] = {13, 12, 22, 24};
int wert[4] = {0, 0, 0, 0};

void setup() {

  // put your setup code here, to run once:
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);
  Serial.begin(9600);
  pinMode(LSensor, INPUT);
}

void loop() {
  for (int i = 0; i < 4; i++) { // update der lignien sensoren
    wert[i] = Linie(i);
  }

  if (wert[1] == color) {
    Fahren(-50, 1.5);
    for (int del; del < 50; del++) {
      delay(1);
      if (wert[3] == color) {
        del = 0;
      }
    }
    Fahren(100, 1);
  }

  if (wert[2] == color) {
    Fahren(-50, 0.5); 
    for (int del; del < 50; del++) {
      delay(1);
      if (wert[4] == color) {
        del = 0;
      }
    }
    Fahren(100, 1);
  }




}
void Fahren(int Geschwindigkeit, double Richtung) {
  //Richtung ist ein wert zwischen 0 und 2. 1 neutral; >1 nach rechts <1 nach links
  //auf die motoren berechnen
  MotorR = Geschwindigkeit * Richtung;
  MotorL = Geschwindigkeit * (1 / Richtung);
  Serial.println("Ich fahre mit " + Geschwindigkeit);
  Serial.println("Motor Rechts " + MotorR);
  Serial.println("Motor Links " + MotorL);
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

boolean Linie(int Sensor) //Funktion zum Auslesen der Sensoren, In die Klammern muss der Sensor der ausglesen werden soll (0-3)
{
  if (digitalRead(LSensor[Sensor]) == 0) //Überprüft welchen Status der Sensor hat
  {
    Serial.print("1");
    return true;
  } else {
    Serial.print("0");
    return false;
  }

}
