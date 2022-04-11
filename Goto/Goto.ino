
#include <openGLCD.h>
#include <fonts/allFonts.h>         // system and arial14 fonts are used
#include <bitmaps/allBitmaps.h>      // all images in the bitmap dir 
////Pines a usar
int led[] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};
int bt1 = 3, bt2 = 2, bt3 = 17, bt4 = 18, m1 = 8, m2 = 9, pwm = 11;;
///Varaibles
int an0, an1, an2, an3, opciones;
int tiempo1, tiempo2;
int encendido = 0, aux;
float t2;

void setup() {
  Serial.begin(9600);  // Debugging only
  GLCD.Init();
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  pinMode(bt4, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  for (int i = 0; i <= 13; i++) {
    pinMode(led[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(bt1), interrupcion1, RISING);
  attachInterrupt(digitalPinToInterrupt(bt2), interrupcion2, FALLING);
  GLCD.ClearScreen();
  delay(1000);
  GLCD.ClearScreen();
  GLCD.CursorToXY(40, 31);
  GLCD.SelectFont(Callibri15);
  GLCD.println("APAGADO");
}
void loop() {
Inicio:
  aux = 0;
  while (encendido == 1) {
    GLCD.ClearScreen();
    GLCD.CursorToXY(40, 31);//Seleccion posicion
    GLCD.SelectFont(Callibri15);
    GLCD.println(("ENCENDIDO"));//Escribo
    for (int i = 0; i <= 12; i++) {
      operaciones();
      if (aux == 1) {
        goto Inicio;
      }
      digitalWrite(led[i], HIGH);
      delay(tiempo1);
      digitalWrite(led[i], LOW);
      delay(tiempo2);
    }
  }
  while (encendido == 0) {
    GLCD.CursorToXY(40, 31);
    GLCD.SelectFont(Callibri15);
    GLCD.println("APAGADO");
    lucesapagadas();
    if (aux == 1) {
      goto Inicio;
    }
  }
}
void interrupcion1() { //Variables encendido
  while (digitalRead(bt1) == HIGH);
  GLCD.ClearScreen();//Limpio
  encendido = 1; //Habilito la opcion Encendido
  aux = 1;
}
void interrupcion2() { //Varaibles apagado
  while (digitalRead(bt2) == HIGH);
  GLCD.ClearScreen();//Limpio
  encendido = 0; //Habilito la opcion Apagado
  aux = 1;
}
void leoanalogicos() { //Leo analogicos
  an0 = analogRead(A0);
  an1 = analogRead(A1);
  an2 = analogRead(A2);
  an3 = analogRead(A3);
}
void lucesencendidas() {//No uso la funcion Directo en void loop
  for (int i = 0; i <= 12; i++) {
    operaciones();
    digitalWrite(led[i], HIGH);
    delay(tiempo1);
    digitalWrite(led[i], LOW);
    delay(tiempo2);
  }
}
void lucesapagadas() {  //Apagado los led
  for (int i = 0; i <= 12; i++) {
    digitalWrite(led[i], LOW);
  }
}
void operaciones() {    //Calcula, Imprime Tiempos
  leoanalogicos();
  tiempo1 = map(an0, 0, 1023, 0, 2000);// a 2000 por 2s
  tiempo2 = map(an1, 0, 1023, 0, 2000);// a 200 por 2s
  t2 = tiempo2 / 1000;// para imprimir en segundos
  GLCD.CursorTo(0, 0);
  GLCD.SelectFont(Wendy3x5);
  GLCD.Printf("\f Ton1: %d INTERVALO1: %d [Ms] \n Ton2: %d INTERVALO2: %1,4f [S] \f", tiempo1, an0, t2, an1);
  if (tiempo2 == 0) {
    tiempo2 = 1;
  }
  if (tiempo1 == 0) {
    tiempo1 = 1;
  }
}

