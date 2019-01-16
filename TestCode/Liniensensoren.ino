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
  /*
    if (digitalRead(LSensor[0]) == 0)
    {
      Serial.print("1");

    } else {
      Serial.print("0");

    }
    if (digitalRead(LSensor[1]) == 0)
    {
      Serial.print("1");

    } else {
      Serial.print("0");

    }
    if (digitalRead(LSensor[2]) == 0)
    {
      Serial.print("1");

    } else {
      Serial.print("0");

    }
    if (digitalRead(LSensor[3]) == 0)
    {
      Serial.println("1");

    } else {
      Serial.println("0");

    }
  */
}
