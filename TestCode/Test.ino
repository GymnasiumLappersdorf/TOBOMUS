int trigger1=2; //Trigger-Pin des Ultraschallsensors an Pin7 des Arduino-Boards 
int echo1=3; // Echo-Pim des Ultraschallsensors an Pin6 des Arduino-Boards
 
int trigger2=4;
int echo2=5;

int trigger4=6;
int echo4=7;

long dauer1=0; // Das Wort dauer ist jetzt eine Variable, unter der die Zeit gespeichert wird, die eine Schallwelle bis zur Reflektion und zurück benötigt. Startwert ist hier 0.
long dauer2=0;
long dauer4=0;

long entfernung1=0; // Das Wort „entfernung“ ist jetzt die variable, unter der die berechnete Entfernung gespeichert wird. Info: Anstelle von „int“ steht hier vor den beiden Variablen „long“. Das hat den Vorteil, dass eine größere Zahl gespeichert werden kann. Nachteil: Die Variable benötigt mehr Platz im Speicher.
long entfernung2=0;
long entfernung4=0;
void setup() {
 pinMode(trigger1, OUTPUT);
 pinMode(echo1, INPUT);
 pinMode(trigger2, OUTPUT);
 pinMode(echo2, INPUT);
 pinMode(trigger4, OUTPUT);
 pinMode(echo4, INPUT);
 Serial.begin(9600);
}

void loop() {
 Serial.println(Messen1());
 Serial.println(Messen2());
 Serial.println(Messen4());
 delay(1000);
 Serial.println();
}

boolean Messen1() {
  boolean Messung = false;
  digitalWrite(trigger1, LOW);
  delay(5);
  digitalWrite(trigger1, HIGH);
  delay(10);
  digitalWrite(trigger1, LOW);
  dauer1 = pulseIn(echo1, HIGH);
  entfernung1 = (dauer1/2)*0.03432;
  if(entfernung1 >= 125 || entfernung1 <= 0) {
   Messung = false; 
  }
  else Messung = true;
  return Messung;
}
boolean Messen2() {
  boolean Messung = false;
  digitalWrite(trigger2, LOW);
  delay(5);
  digitalWrite(trigger2, HIGH);
  delay(10);
  digitalWrite(trigger2, LOW);
  dauer2 = pulseIn(echo2, HIGH);
  entfernung2 = (dauer2/2)*0.03432;
  if(entfernung2 >= 125 || entfernung2 <= 0) {
   Messung = false; 
  }
  else Messung = true;
  return Messung;
}
boolean Messen4() {
  boolean Messung = false;
  digitalWrite(trigger4, LOW);
  delay(5);
  digitalWrite(trigger4, HIGH);
  delay(10);
  digitalWrite(trigger4, LOW);
  dauer4 = pulseIn(echo4, HIGH);
  entfernung4 = (dauer4/2)*0.03432;
  if(entfernung4 >= 125 || entfernung4 <= 0) {
   Messung = false; 
  }
  else Messung = true;
  return Messung;
}
