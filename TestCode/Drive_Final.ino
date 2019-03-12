int MotorPin1 = 9;
int MotorPin2 = 10;
int MotorPin3 = 5;
int MotorPin4 = 6;
int MotorR = 180;
int MotorL = 180;
String Nummer;

int color = 0; //Die standart farbe für das blatt

//Sensor 1 => 13 Pin    hinten links
//Sensor 2 => 12 Pin    hinten rechts   
//Sensor 3 => 22 Pin    vorne links
//Sensor 4 => 24 Pin    vorne rechts


int LSensor[4] = {22, 24, 13, 12};
int wert[4] = {0, 0, 0, 0};
int driveMode = 0;// was gerade angesgtist für fahrmodi
int del = 0;
void setup() {

  // put your setup code here, to run once:
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);
  Serial.begin(9600);
  pinMode(LSensor[0], INPUT);
  pinMode(LSensor[1], INPUT);
  pinMode(LSensor[2], INPUT);
  pinMode(LSensor[3], INPUT);
  
  
}

void loop() {
Linie(1);
Linie(2);
Linie(3);
Linie(4);
  switch (driveMode) {
    case -1:
      Fahren(-150, -0.5);
      delay(1);
      del-=1;
      if (Linie(3) == color) {
        del = -1;
      }
      if(del<0){
        driveMode=0;
        }


      break;
    case 0:
      if (Linie(1) == color) {
        del = 4000;
        driveMode=-1;
      }
      else if (Linie(2) == color) {
        del = 4000;
        driveMode=1;
      }
      else {
      Fahren(255, 1);  
        
      }


      break;
    case 1:
      Fahren(-150, 0.5);
      delay(1);
      del-=1;
      if (Linie(4) == color) {
        del = -1;
      }
      if(del<0){
        driveMode=0;
        }

      break;
  }
}
void Fahren(int Geschwindigkeit, double Richtung) {
  //Richtung ist ein wert zwischen 0 und 2. 0 neutral; >0 nach rechts <0 nach links
  //auf die motoren berechnen
  MotorR = Geschwindigkeit * (Richtung + 1);
  MotorL = Geschwindigkeit * (1 / (Richtung + 1));
  //Serial.println("Ich fahre mit " + Geschwindigkeit);
  //Serial.println("Motor Rechts " + MotorR);
  //Serial.println("Motor Links " + MotorL);
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

int Linie(int Sensor) //Funktion zum Auslesen der Sensoren, In die Klammern muss der Sensor der ausglesen werden soll (0-3)
{
  if (digitalRead(LSensor[(Sensor-1)]) == 0) //Überprüft welchen Status der Sensor hat
  {
    Serial.println(Sensor);
    return 1;
  } else {
    //Serial.println();
    return 0;
  }

}
