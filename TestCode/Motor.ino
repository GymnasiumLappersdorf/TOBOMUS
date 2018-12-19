
int MotorPin1 = 5;
int MotorPin2 = 6;
int MotorPin3 = 9;
int MotorPin4 = 10;
int MotorR =200;
int MotorL=200;
String Nummer;
void setup() {
  
  // put your setup code here, to run once:
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);
}

void loop() {
  //Rechter Motor
  if(MotorR>0){
    analogWrite(MotorPin2,0);
    analogWrite(MotorPin1,MotorR);
    }
  if(MotorR<0){
    analogWrite(MotorPin1,0);
    analogWrite(MotorPin2,(-MotorR));
    }
  if(MotorR==0){
    analogWrite(MotorPin2,0);
    analogWrite(MotorPin1,0);
    }
    //Linker Motor
 if(MotorL>0){
    analogWrite(MotorPin3,0);
    analogWrite(MotorPin4,MotorL);
    }
  if(MotorL<0){
    analogWrite(MotorPin4,0);
    analogWrite(MotorPin3,(-MotorL));
    }
  if(MotorL==0){
    analogWrite(MotorPin3,0);
    analogWrite(MotorPin4,0);
    }
}
