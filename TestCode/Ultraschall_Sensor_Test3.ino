int trigger[] = {2, 3, 4};
int echo[] = {6, 7, 8};

long dauer[] = {0, 0, 0};

long entfernung[3] = {0, 0, 0,};

void setup() {
  pinMode(trigger[0], OUTPUT);
  pinMode(echo[0], INPUT);
  pinMode(trigger[1], OUTPUT);
  pinMode(echo[1], INPUT);
  pinMode(trigger[2], OUTPUT);
  pinMode(echo[2], INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(Messen(0));
  Serial.println(Messen(1));
  Serial.println(Messen(2));
  delay(1000);
  Serial.println();
}

boolean Messen(int Sensor) {
  boolean Messung = false;
  digitalWrite(trigger[Sensor], LOW);
  delay(5);
  digitalWrite(trigger[Sensor], HIGH);
  delay(10);
  digitalWrite(trigger[Sensor], LOW);
  dauer[Sensor] = pulseIn(echo[Sensor], HIGH);
  entfernung[Sensor] = (dauer[Sensor] / 2) * 0.03432;
  if (entfernung[Sensor] >= 125 || entfernung[Sensor] <= 0) {
    Messung = false;
  }
  else Messung = true;
  return Messung;
}
