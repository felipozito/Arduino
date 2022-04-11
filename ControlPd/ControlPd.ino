#include <openGLCD.h>
#include <Ultrasonic.h>
Ultrasonic sensor1(40, 41); //Trigger, Echo
Ultrasonic sensor2(52, 53); //Trigger, Echo
//Sensor A utiliza el M1
//Sensor B Utiliza el M2
//-----------PINES-----------------//
int pwm1 = 8; int m1a = 9; int m1b = 10;
int pwm2 = 13; int m2a = 12; int m2b = 11;
int btn = 19;
int bomba1A = 47; int bomba2A = 49;
int bomba1B = 48; int bomba2B = 50;
//----------Variables--------///
float sensorA = 0; float sensorB = 0; int Encendido = 0;
int cruze = 10; // Altura de elevacion para el cruze del canal
int canal = 11; // Altura del canal
int Vaciado = 0; int var1, var2;
void setup() {
  Serial.begin(9600);
  GLCD.Init();
  pinMode(btn, INPUT); pinMode(m1a, OUTPUT); pinMode(m1b, OUTPUT);
  pinMode(pwm1, OUTPUT); pinMode(m2a, OUTPUT); pinMode(m2b, OUTPUT);
  pinMode(pwm2, OUTPUT); pinMode(bomba1A, OUTPUT); pinMode(bomba1B, OUTPUT);
  pinMode(bomba2B, OUTPUT); pinMode(bomba2B, OUTPUT);
  GLCD.ClearScreen();
  GLCD.DrawBitmap(ups, 1, 1, BLACK); ///Dibujo
  delay(2000);
  GLCD.ClearScreen();
  interfaz();
  Serial.print("\f CANAL DE PANAMA \n");
}
void loop() {
  if (digitalRead(btn) == 1) {
    while (digitalRead(btn));
    Encendido = 1;
  }
  while (Encendido) { //Proceso de Encendido
    sensorA = sensor1.distanceRead();
    sensorB = sensor2.distanceRead();
    var1 = abs(((sensorA - 5) * 5) - 100);
    var2 = abs(((sensorB - 5) * 5) - 100);
    GLCD.ClearScreen();
    interfaz();
    niveles();
    imprimirSensor();
    delay(250);
    if(sensorA == sensorB){
       PararTanqueA();
       Serial.println("EXITO MOTOR A1 ");
    }
    else if(sensorA > sensorB){
       LlenarTanqueA();
       Serial.println("LLENAR ");  
    }
    else if(sensorA < sensorB){
       VaciarTanqueA();
       Serial.println("Vaciar");
    }
  }
}
void imprimirSensor() {
  Serial.print("Sensor 01:\t ");
  Serial.print(sensorA);
  Serial.print("\tSensor 02: \t ");
  Serial.print(sensorB);
  Serial.println("");
}
void LlenarTanqueA() {
  analogWrite(pwm1, 100);
  digitalWrite(bomba1A, HIGH);
  digitalWrite(bomba1B, LOW);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
}
void LlenarTanqueB() {
  analogWrite(pwm2, 100);
  digitalWrite(bomba2A, HIGH);
  digitalWrite(bomba2B, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}
void VaciarTanqueA() {
  analogWrite(pwm1, 100);
  digitalWrite(bomba1A, LOW);
  digitalWrite(bomba1B, HIGH);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
}
void VaciarTanqueB() {
  analogWrite(pwm2, 100);
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
void niveles() {
  GLCD.DrawVBarGraph(10, 63, 40, -40, 1, 0, 100, var1); ///(x,y,largo,ancho,grosorLineas,minimo,maximo)
  GLCD.DrawVBarGraph(64, 63, 40, -40, 1, 0, 100, var2); ///(x,y,largo,ancho,grosorLineas,minimo,maximo)
  GLCD.CursorToXY(20, 9); GLCD.Printf("POR1:\f %d       POR2:%d  \f", var1, var2);

}
