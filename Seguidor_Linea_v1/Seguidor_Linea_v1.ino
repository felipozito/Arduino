#include <QTRSensors.h>
#define NUM_SENSORS   8       // Numero de sensores
#define TIMEOUT       2500   // tiempo de iniciazion
#define EMITTER_PIN   10    // pin de activacion ledon
QTRSensorsRC qtrrc((unsigned char[]) {
  19, 18, 17, 16, 15, 14, 13, 12
},
NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
unsigned int position = 0; //Posicion inicia en 0
//BOTONES//
const int btn1 = 1;
int cruzero = 110;   //velocidad Linea recta/////
/////PUENTE H AL ARDUINO/////////
int pwma = 3;
int ain2 = 4;
int ain1 = 5;
int stanby = 6;
int bin1 = 7;
int bin2 = 8;
int pwmb = 9;
/////// constantes PID///////
int P = 0; /// valor proporcional
int I = 0; /// valor integrativo
int D = 0; /// valor derivatico
int error = 0;
///Led Indicador/////
int calibracion = 0;
///velocidad///
float vel;
float kp=0.025;
float kd=0.095;
float ki=0;
void setup() {
  DeclaroPines();
  Serial.begin(9600);
  delay(1500);
  Calibracion();
  ActivoMotores();
}
void loop() {
  if (digitalRead(btn1) == 1) {
    while (1) {
      qtrrc.read(sensorValues);
      position = qtrrc.readLine(sensorValues, QTR_EMITTERS_ON, 0);//0= pista blanca linea negra
      P = ((position) - (3500));
      ///p=ERROR para configurar sensores (-3500 -2500 -1500 -500 500 1500 2500 3500)
      if (P < -3500) {
        FrenoIzquierdo();
      } else if (P > 3500) {
        FrenoDerecho();
      }
      else {
        D = (P - error); /// ERROR MENOS EL ERROR ANTERIOR , DERIVATIVO
        I = (P + error); //INTEGRAL
        vel = (P * kp) + (D * kd) + (I * ki); ///formula del PID
        if (vel > cruzero) {
          vel = cruzero;
        }
        if (vel < -cruzero) {
          vel = -cruzero;
        }
        SeguirLinea();
        error = P;
      }
    }
  }
}

void FrenoIzquierdo() {
  analogWrite(pwma, 120); ////VELOCIDAD PARA EL MOTOR DERECHO
  analogWrite(pwmb, 180); ////VELOCIDAD PARA EL MOTOR IZQUIERDO
  digitalWrite(ain1, LOW); /////FRENTE
  digitalWrite(ain2, HIGH);
  digitalWrite(bin1, LOW); ///RETROCEDE
  digitalWrite(bin2, HIGH);
}
void FrenoDerecho() {
  analogWrite(pwma, 180); //   VELOCIDAD PARA EL MOTOR DERECHO
  analogWrite(pwmb, 120); //   VELOCIDAD PARA EL MOTOR IZQUIERDO
  digitalWrite(ain1, HIGH); ///RETROCEDE
  digitalWrite(ain2, LOW);
  digitalWrite(bin1, HIGH); ///FRENTE
  digitalWrite(bin2, LOW);
}
void SeguirLinea() {
  analogWrite(pwma, cruzero - vel); ////VELOCIDAD PARA EL MOTOR DERECHO
  analogWrite(pwmb, cruzero + vel); ////VELOCIDAD PARA EL MOTOR IZQUIERDO
  digitalWrite(ain1, LOW); ///FRENTE
  digitalWrite(ain2, HIGH);
  digitalWrite(bin1, HIGH); ///FRENTE
  digitalWrite(bin2, LOW);
}
void DeclaroPines() {
  pinMode(btn1, INPUT);
  pinMode(pwma, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(stanby, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(calibracion, OUTPUT);
}
void ActivoMotores() {
  digitalWrite(ain1, LOW);
  digitalWrite(ain2, HIGH);
  digitalWrite(bin1, HIGH);
  digitalWrite(bin2, LOW);
  digitalWrite(stanby, HIGH);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
}
void Calibracion() {
  digitalWrite(calibracion, HIGH);
  for (int j = 0; j < 200; j++)  {
    qtrrc.calibrate();
  }
  digitalWrite(calibracion, LOW);
}
