#include <xmotion.h> //Included XMotion Library
#define Sw1 5 // Dipswitch 1
#define Sw2 6 // Dipswitch 2 
#define Sw3 7 // Dipswitch 3 
#define SensorDerecho  A5 
#define SensorDerechoDiagonal  4 
#define SensorCentro  2
#define SensorIzquierdoDiagonal  1 
#define SensorIzquierdo  0
#define LineaIzquierda  A2 
#define LineaDerecha  A4 
#define Start  10
#define Led1  8
#define Led2  9
int izquierda = 0,derecha=0;int linea=300;
int s[] = {0, 0, 0, 0, 0};
int estrategia=0;int aux=0;
void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT); pinMode(Led2, OUTPUT);
  pinMode(SensorDerecho, INPUT);pinMode(Start, INPUT);
  pinMode(SensorIzquierdo, INPUT); pinMode(SensorIzquierdoDiagonal, INPUT);
  pinMode(SensorDerechoDiagonal, INPUT); pinMode(SensorCentro, INPUT);
  pinMode(Sw1, INPUT); pinMode(Sw2, INPUT); pinMode(Sw3, INPUT);
  estrategia=0;izquierda=0;derecha=0;aux=0;
  Serial.print("\nPrueba Sensores");
  PruebaSensores();
  digitalWrite(Led1,LOW);digitalWrite(Led2,LOW);
  delay(100);
  while(digitalRead(Start)==0){
    LeerEstrategia();
  }
  xmotion.CounterLeds(1000, 5);
}
void loop() {
  while(estrategia==0){////Basico
    xmotion.Forward(100,1);
    SensorDeLinea();
    LeerSensores();
    Basico();
  }
  while(estrategia==1){///Despacio Frontal
    xmotion.Forward(50,1);
    SensorDeLinea();
    LeerSensores();
    Basico(); 
  }
  while(estrategia==2){///Rodear Oponente
    SensorDeLinea();
    LeerSensores();
    Basico(); 
  }
  while(estrategia==4){//Diagonal y Vuelve
    SensorDeLinea();
    LeerSensores();
    Basico(); 
  }
  while(estrategia==4){//Empiezo Lateral | |
    SensorDeLinea();
    LeerSensores();
    Basico(); 
  }
}
void LeerSensores() {
  if (digitalRead(SensorDerecho) == 1) {
    s[4] = 1;
    digitalWrite(Led1, HIGH);
  } else {
    s[4] = 0;
    digitalWrite(Led1, LOW);
  }
  if (digitalRead(SensorDerechoDiagonal) == 1) {
    s[3] = 1;
    digitalWrite(Led2, HIGH);
  } else {
    s[3] = 0;
    digitalWrite(Led2, LOW);
  }
  if (digitalRead(SensorCentro) == 1) {
    s[2] = 1;
    digitalWrite(Led2, HIGH);
  } else {
    s[2] = 0;
    digitalWrite(Led2, LOW);
  }
  if (digitalRead(SensorIzquierdoDiagonal) == 1) {
    s[1] = 1;
    digitalWrite(Led2, HIGH);
  } else {
    s[1] = 0;
    digitalWrite(Led1, LOW);
  }
  if (digitalRead(SensorIzquierdo) == 1) {
    s[0] = 1;
    digitalWrite(Led1, HIGH);
  } else {
    s[0] = 0;
    digitalWrite(Led1, LOW);
  }
}
void SensorDeLinea() {
  if (analogRead(LineaIzquierda) < linea && analogRead(LineaDerecha) > linea ) { //Linea Izquierdo
    xmotion.Backward(100, 100); //Atras v 100% por 100 ms
    xmotion.Right0(100, 200); //Derecha v 100% por 200 ms
  } else if (analogRead(LineaIzquierda) > linea && analogRead(LineaDerecha) < linea ) { //Linea Derecho
    xmotion.Backward(100, 100); //Atras v 100% por 100 ms
    xmotion.Left0(100, 200); //Izquierda v 100% por 200 ms
  } else if (analogRead(LineaIzquierda) < linea && analogRead(LineaDerecha) < linea ) { //Ambos Linea
    xmotion.Backward(100, 200); //Atras v 100% por 200 ms
    xmotion.Right0(100, 300); //Derecha v 100% por 300 ms
  } 
}
void PruebaSensores() {
  while (digitalRead(Start) == 0) {
    if (digitalRead(SensorIzquierdo) == 1 || digitalRead(SensorCentro) == 1 || digitalRead(SensorDerecho) == 1 || digitalRead(SensorIzquierdoDiagonal) == 1 || digitalRead(SensorDerechoDiagonal) == 1) {
      digitalWrite(Led1, HIGH);
    } else {
      digitalWrite(Led1, LOW);
    }
  }
}
void LeerEstrategia(){
if(digitalRead(Sw1)==1){estrategia=+1;}else{estrategia=+0;} 
if(digitalRead(Sw2)==1){estrategia=+2;}else{estrategia=+0;} 
if(digitalRead(Sw3)==1){estrategia=+4;}else{estrategia=+0;} 
  Serial.print("\nESTRATEGIA: \t");Serial.print(estrategia);  
}
void Basico(){
  if (s[4] == 1 && s[3] == 0 && s[2] == 0 && s[1] == 0 && s[0] == 0 ) {
    xmotion.Left0(100,1);izquierda=1;derecha=0;
  }
  if (s[4] == 0 && s[3] == 1 && s[2] == 0 && s[1] == 0 && s[0] == 0 ) {
    xmotion.ArcTurn(80,100,1);izquierda=1;derecha=0;
  }
  if (s[4] == 0 && s[3] == 1 && s[2] == 1 && s[1] == 0 && s[0] == 0 ) {
    xmotion.ArcTurn(90,100,1);izquierda=1;derecha=0;
  }
  if (s[4] == 0 && s[3] == 0 && s[2] == 1 && s[1] == 0 && s[0] == 0 ) {
    xmotion.Forward(100,1);izquierda=0;derecha=0;
  }
  if (s[4] == 0 && s[3] == 1 && s[2] == 1 && s[1] == 1 && s[0] == 0 ) {
    xmotion.Forward(100,1);izquierda=0;derecha=0;
  }
  if (s[4] == 0 && s[3] == 0 && s[2] == 0 && s[1] == 1 && s[0] == 0 ) {
    xmotion.ArcTurn(100,80,1);izquierda=0;derecha=1;
  }
  if (s[4] == 0 && s[3] == 0 && s[2] == 1 && s[1] == 1 && s[0] == 0 ) {
    xmotion.ArcTurn(100,90,1);izquierda=0;derecha=1;
  }
  if (s[4] == 0 && s[3] == 0 && s[2] == 0 && s[1] == 0 && s[0] == 1 ) {
    xmotion.Right0(100,1);izquierda=0;derecha=1;
  }
  if (s[4] == 0 && s[3] == 0 && s[2] == 0 && s[1] == 0 && s[0] == 0 ) {
       if(izquierda==1){
         xmotion.Left0(100,1);
         izquierda=0;derecha=0;
       }else if (derecha==1){
         xmotion.Right0(100,1);
         izquierda=0;derecha=0;
      }
  }   
}
