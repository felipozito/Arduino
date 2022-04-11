#include <openGLCD.h>
#include <Ultrasonic.h>
Ultrasonic ultrasonico1(52,53); //Trigger, Echo
Ultrasonic ultrasonico2(40,41); //Trigger, Echo
//Sensor A utiliza el M1
//Sensor B Utiliza el M2
//-----------PINES-----------------//
int pwm1 = 10;
int m1a = 9;
int m1b = 8;
int pwm2 = 11;
int m2a = 12;
int m2b = 13;
int btn = 19;
int bombaA=49;
int bombaB=48;
//----------Variables--------///
int sensorA = 0;
int sensorB = 0;
int Encendido = 0;
int cruze = 10; // Altura de elevacion para el cruze del canal
int canal = 11; // Altura del canal
int Vaciado = 0;
int var1,var2;
void setup() {
  Serial.begin(115200);
  pinMode(btn, INPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(bombaA, OUTPUT);
  pinMode(bombaB, OUTPUT);
  digitalWrite(bombaA,HIGH);
  digitalWrite(bombaB,HIGH);
  delay(500);
  digitalWrite(bombaA,LOW);
  digitalWrite(bombaB,LOW);
  Serial.print("CANAL DE PANAMA \n");
  delay(500);
  Encendido=1;
}
void loop() {
  while (1) { //Proceso de Encendido
    LlenarTanqueA();
    sensorA = ultrasonico1.distanceRead();
    sensorB = ultrasonico2.distanceRead();
    var1=abs(((sensorA-5)*5)-100);
    var2=abs(((sensorB-5)*5)-100);
    imprimirSensor();
    delay(100);
  }
}
void imprimirSensor() {
  Serial.print("Sensor 01:\t");
  Serial.print(sensorA);
  Serial.print("\t Sensor 02: \t");
  Serial.println(sensorB);
}
void LlenarTanqueA() {
  analogWrite(pwm1, 255);
  digitalWrite(bombaA,HIGH);
  digitalWrite(bombaB,HIGH);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
}
void LlenarTanqueB() {
  analogWrite(pwm2, 255);
  digitalWrite(bombaA,HIGH);
  digitalWrite(bombaB,HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}
void VaciarTanqueA() {
  analogWrite(pwm1, 255);
  digitalWrite(bombaA,HIGH);
  digitalWrite(bombaB,HIGH);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
}
void VaciarTanqueB() {
  analogWrite(pwm2, 255);
  digitalWrite(bombaA,HIGH);
  digitalWrite(bombaB,HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}
void PararTanqueA() {
  digitalWrite(bombaA,LOW);
  digitalWrite(bombaB,LOW);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
}
void PararTanqueB() {
  digitalWrite(bombaA,LOW);
  digitalWrite(bombaB,LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}
void interfaz(){
  GLCD.SelectFont(Wendy3x5);
  GLCD.DrawRect(0, 0, 127, 63, BLACK);
  GLCD.CursorToXY(30, 0);
  GLCD.print("CANAL DE PANAMA");
  GLCD.CursorToXY(5, 5);
  GLCD.print("O.PACIFICO"); 
  GLCD.CursorToXY(60, 5);
  GLCD.print("O.ATLANTICO"); 
  GLCD.CursorToXY(20, 9);
  GLCD.Printf("POR1:\f %d       POR2:%d  \f", var1, var2);
}
