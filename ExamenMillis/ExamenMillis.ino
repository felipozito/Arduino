
#include <openGLCD.h>
#include <fonts/allFonts.h>         // system and arial14 fonts are used
#include <bitmaps/allBitmaps.h>      // all images in the bitmap dir 
////Pines a usar
int led[] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};
int bt1 = 3, bt2 = 2, bt3 = 17, bt4 = 18, m1 = 8, m2 = 9, pwm = 11;;
///Varaibles
int an0, an1, an2, an3, opciones;
int tiempoOn, tiempoOff;
int encendido = 0, aux;
float t2;
////Tiempo
unsigned long tiempopasado = 0;
int dt = 1000;

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
  if (encendido == 1) {
    //GLCD.ClearScreen();
    GLCD.CursorToXY(40, 31);//Seleccion posicion
    GLCD.SelectFont(Callibri15);
    GLCD.println(("ENCENDIDO"));//Escribo
    int i=0;
    while (i <= 12) { //13 Leds
      operaciones(); //Calculo tiempo con Pot
      if (aux == 1) goto Inicio; //si se habilita ir a Inicio:
      if (millis() - tiempopasado < tiempoOn) { ///mientras el millis() se menor Ton
        digitalWrite(led[i], HIGH);
      } else if (millis() - tiempopasado > tiempoOn && millis() - tiempopasado <=tiempoOn+tiempoOff) {//Mientras millis() mayor Ton y menor Toff
        digitalWrite(led[i], LOW);
      } else if (millis() - tiempopasado > tiempoOn+tiempoOff) {//Si cumple el tiempo encendido y apagado reinicia y se enciende otro led
        tiempopasado=millis();//Almaceno el ultimo valor millis() Reseteo
        i++;//Cambio led
      }
    }
  }
  if (encendido == 0) {
    GLCD.ClearScreen();//Limpio
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
  GLCD.ClearScreen();//Limpio
  encendido = 1; //Habilito la opcion Encendido
  aux = 1;
}
void interrupcion2() { //Varaibles apagado
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
void lucesapagadas() {  //Apagado los led
  for (int i = 0; i <= 12; i++) {
    digitalWrite(led[i], LOW);
  }
}
void operaciones() {    //Calcula, Imprime Tiempos
  leoanalogicos();
  tiempoOn = map(an0, 0, 1023, 0, 2000);// a 2000 por 2s
  tiempoOff = map(an1, 0, 1023, 0, 2000);// a 200 por 2s
  t2 = tiempoOff / 1000;// para imprimir en segundos
  GLCD.CursorTo(0, 0);
  GLCD.SelectFont(Wendy3x5);
  GLCD.Printf("\f Ton1: %d INTERVALO1: %d [Ms] \n Ton2: %d INTERVALO2: %1,4f [S] \f", tiempoOn, an0, t2, an1);
  if (tiempoOff == 0) {
    tiempoOff = 1;
  }
  if (tiempoOn == 0) {
    tiempoOn = 1;
  }
}

