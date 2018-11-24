//Pins der Bauteile
// Rote LED LROT
// Grüne LED LGRUEN
// Gelbe LED LGELB
// Weisse LED LWEISS
// Temperatursensor  TMP36 
// Versuch
// Versuch 2

#define LROT 10
#define LGRUEN 5
#define LGELB 6
#define LWEISS 3
#define TMP36 A0

//Der Sensor soll am analogen Pin A0 angeschlossen werden
int sensorwert;
int temperatur = 0; //Unter der Variablen "temperatur" wird später der Temperaturwert abgespeichert.
int t=500; //Der Wert für „t“ gibt im Code die zeitlichen Abstände zwischen den einzelnen Messungen vor.

void LEDan(int Pin);
void LEDaus (int Pin);
void Farbampel(int wert, int minimum, int maximum);

void setup() 
{
  pinMode(LROT,OUTPUT);
  pinMode(LGRUEN,OUTPUT);
  pinMode(LGELB,OUTPUT);
  pinMode(LWEISS,OUTPUT);
  //Analoger Pin TMP36 muss nicht deklariert werden
  Serial.begin(9600); //Im Setup beginnt die serielle Kommunikation, damit die Temperatur an den serial monitor übertragen wird. Über die serielle Kommunikation sendet das Board die Messwerte an den Computer. In der Arduino-Software kann man unter „Werkzeuge“ den „Seriellen Monitor“ starten um die Messwerte zu sehen.
}

void loop() 
{
  sensorwert=analogRead(TMP36); //Auslesen des Sensorwertes.
  temperatur= map(sensorwert, 0, 410, -50, 150); //Umwandeln des Sensorwertes mit Hilfe des "map" Befehls.
  delay(t); // Nach jeder Messung ist je eine kleine Pause mit der Dauer „t“ in Millisekunden.
  Serial.print(" ");
  Serial.print(temperatur); //Nun wird der Wert „temperatur“ über die serielle Kommunikation an den PC gesendet. Durch öffnen des seriellen Monitors in der Arduino-Software kann die Temperatur abgelesen werden.
  Farbampel(temperatur,24,30,LROT,LGELB,LGRUEN);
}



void LEDan(int Pin)
{
  digitalWrite(Pin,HIGH);
}

void LEDaus (int Pin)
{
  digitalWrite(Pin,LOW);
}

void Farbampel(int wert, int minimum, int maximum,int Lrot,int Lgelb, int Lgruen)
{
  int zwischenwert = 3*(wert-minimum)/(maximum-minimum);
  if (zwischenwert>=0)
  {
      LEDaus(Lrot);
      LEDaus(Lgelb);
      LEDan(Lgruen);
  }
  if (zwischenwert>1)
  {
      LEDaus(Lrot);
      LEDan(Lgelb);
      LEDaus(Lgruen);
  }
   if (zwischenwert>2)
  {
      LEDan(Lrot);
      LEDaus(Lgelb);
      LEDaus(Lgruen);
  }
  Serial.print(" ");
  Serial.println(zwischenwert);

}
