int LSensor[4] = {3, 4, 5, 6};

boolean Linie(int Sensor) //Funktion zum Auslesen der Sensoren, In die Klammern muss der Sensor der ausglesen werden soll (0-3)
{
  if (digitalRead(LSensor[Sensor]) == 0) //Überprüft welchen Status der Sensor hat
  {
    Serial.print("1");
    return 1;
  } else {
    Serial.print("0");
    return 0;
  }

}
void setup() {
  Serial.begin(9600);
  pinMode(LSensor, INPUT);

}
void loop() {
  Linie(0);
  Linie(1);
  Linie(2);
  Linie(3);
  Serial.println("");
  
}
