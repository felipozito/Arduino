#include <openGLCD.h>
#include <Ultrasonic.h>
Ultrasonic sensor1(40, 41); //Trigger, Echo
Ultrasonic sensor2(52, 53); //Trigger, Echo
//Sensor A utiliza el M1
//Sensor B Utiliza el M2
//-----------PINES-----------------//
int pwm1 = 8; int m1a = 9; int m1b = 10;
int pwm2 = 13; int m2a = 12; int m2b = 11;
int btn = 19;int adc=A0;
int bomba1A = 47; int bomba2A = 49;
int bomba1B = 48; int bomba2B = 50;
//----------Variables--------///
int sensorA = 0; int sensorB = 0; int Encendido = 0;
int cruze = 10; // Altura de elevacion para el cruze del canal
int canal = 11; // Altura del canal
int Vaciado = 0; int var1, var2;int Setpoint;
void setup() {
  Serial.begin(9600);
  GLCD.Init();
  pinMode(btn, INPUT); pinMode(m1a, OUTPUT); pinMode(m1b, OUTPUT);
  pinMode(pwm1, OUTPUT); pinMode(m2a, OUTPUT); pinMode(m2b, OUTPUT);
  pinMode(pwm2, OUTPUT); pinMode(bomba1A, OUTPUT); pinMode(bomba1B, OUTPUT);
  pinMode(bomba2B, OUTPUT); pinMode(bomba2B, OUTPUT);
  GLCD.ClearScreen();
  GLCD.DrawBitmap(ups, 1, 1, BLACK); ///Dibujo
  delay(1000);
  GLCD.ClearScreen();
  interfaz();
  Serial.print("\f CANAL DE PANAMA \n");
}
void loop() {
  if (digitalRead(btn) == 1) {
    while (digitalRead(btn));
    Encendido = 1;
  }
  while (1) { //Proceso de Encendido
    int nivel=analogRead(adc);
    Setpoint=map(nivel,0,1023,0,100);
    sensorA = sensor1.distanceRead();
    sensorB = sensor2.distanceRead();
    var1 = abs(((sensorA - 5) * 5) - 100);
    var2 = abs(((sensorB - 5) * 5) - 100);
    GLCD.ClearScreen();
    interfaz();
    imprimirSensor();
    if(Setpoint>sensorA){
      LlenarTanqueA();  
    }else if(Setpoint<sensorA){
      VaciarTanqueA();
    }else if(Setpoint=sensorA){
      PararTanqueA();  
    }
    if(sensorA>sensorB){
      LlenarTanqueB();  
    }else if(sensorA<sensorB){
      VaciarTanqueB();
    }else if(sensorA=sensorB){
      PararTanqueB();  
    }
  }
}
void imprimirSensor() {
  Serial.print("Sensor 01:\t ");
  Serial.print(var1);
  Serial.print("\tSensor 02: \t ");
  Serial.print(var2);
  Serial.println("");
}
void LlenarTanqueA() {
  analogWrite(pwm1, 255);
  digitalWrite(bomba1A, HIGH);
  digitalWrite(bomba1B, LOW);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
}
void LlenarTanqueB() {
  analogWrite(pwm2, 255);
  digitalWrite(bomba2A, HIGH);
  digitalWrite(bomba2B, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}
void VaciarTanqueA() {
  analogWrite(pwm1, 255);
  digitalWrite(bomba1A, LOW);
  digitalWrite(bomba1B, HIGH);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
}
void VaciarTanqueB() {
  analogWrite(pwm2, 255);
  digitalWrite(bomba2A, LOW);
  digitalWrite(bomba2B, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}
void PararTanqueA() {
  digitalWrite(bomba1A, LOW);
  digitalWrite(bomba1B, LOW);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
}
void PararTanqueB() {
  digitalWrite(bomba2A, LOW);
  digitalWrite(bomba2B, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}
void interfaz() {
  GLCD.SelectFont(Wendy3x5);
  GLCD.CursorToXY(30, 0);GLCD.print("CANAL DE PANAMA");
  GLCD.CursorToXY(5, 5);GLCD.print("O.PACIFICO");
  GLCD.CursorToXY(60, 5);GLCD.print("O.ATLANTICO");
  GLCD.CursorToXY(35, 30);GLCD.Printf("CANAL1:");
  GLCD.CursorToXY(35, 40);GLCD.Printf("%d",var1);
  GLCD.CursorToXY(90, 30);GLCD.Printf("CANAL2:");
  GLCD.CursorToXY(90, 40);GLCD.Printf("%d",var2);
  GLCD.DrawVBarGraph(10, 63, 20, -40, 1, 0, 100, var1); ///(x,y,largo,ancho,grosorLineas,minimo,maximo)
  GLCD.DrawVBarGraph(64, 63, 20, -40, 1, 0, 100, var2); ///(x,y,largo,ancho,grosorLineas,minimo,maximo)
  GLCD.CursorToXY(55, 9);GLCD.Printf("SP:\f %d", Setpoint);
}

