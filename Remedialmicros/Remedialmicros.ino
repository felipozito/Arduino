
#include <openGLCD.h>
#include <fonts/allFonts.h>         // system and arial14 fonts are used
#include <bitmaps/allBitmaps.h>      // all images in the bitmap dir 
////Pines a usar
int led[] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};
int bt1 = 3, bt2 = 2, bt3 = 17, bt4 = 18, m1 = 8, m2 = 9, pwm = 11;;
///Varaibles
int an0, an1, an2, an3, opciones;
int vel, leds, valor, pot, radio, aux;
int aux1 = 0, aux2 = 0, tiempo1, tiempo2;
int encendido = 0;
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
  ////ENCENDIDO
  while (encendido == 1) {
    GLCD.ClearScreen();
    GLCD.CursorToXY(40, 31);//Seleccion posicion
    GLCD.SelectFont(Callibri15);
    GLCD.println(("ENCENDIDO"));//Escribo
    luces();
  }
  //APAGADO
  while (encendido == 2) {
    GLCD.CursorToXY(40, 31);
    GLCD.SelectFont(Callibri15);
    GLCD.println("APAGADO");
  }
}
void interrupcion1() {
  while (digitalRead(bt1) == 1);
  GLCD.ClearScreen();
  encendido = 1;
  if (encendido == 3) {
    encendido = 0;
  }
  GLCD.CursorToXY(40, 31);//Seleccion posicion
  GLCD.SelectFont(Callibri15);
  GLCD.println(("ENCENDIDO"));//Escribo
  delay(200);
}
void interrupcion2() {
  while (digitalRead(bt2) == 1);
  GLCD.ClearScreen();//Limpio
  GLCD.CursorToXY(40, 31);//Seleccion posicion
  GLCD.SelectFont(Callibri15);
  GLCD.println(("APAGADO"));//Escribo
  encendido = 2; //Habilito la opcion encendido
}
void leoanalogicos() {
  an0 = analogRead(A0);
  an1 = analogRead(A1);
  an2 = analogRead(A2);
  an3 = analogRead(A3);
}
void luces(){
  for (int i = 0; i <= 12; i++) {
    operaciones();
    if (encendido == 2) {
      GLCD.ClearScreen();
      GLCD.CursorToXY(40, 31);
      GLCD.SelectFont(Callibri15);
      GLCD.println("APAGADO");
      GLCD.DrawRect(0, 0, 127, 63, BLACK);
    }
    if (encendido != 2) {
      digitalWrite(led[i], HIGH);
      delay(tiempo1);
      digitalWrite(led[i], LOW);
      delay(tiempo2);
    }
  }
}
void operaciones() {
  leoanalogicos();
  GLCD.CursorTo(0, 0);
  tiempo1 = map(an0, 0, 1023, 0, 2000);
  tiempo2 = map(an1, 0, 1010, 0, 2000);
  t2=tiempo2/1000;
  GLCD.SelectFont(Wendy3x5);
  GLCD.Printf("\f Ton:%d INTERVALO:%d [Ms] \f ", tiempo1, an0);
  GLCD.CursorTo(0, 2);
  GLCD.SelectFont(Wendy3x5);
  GLCD.Printf("\f Ton: %d INTERVALO:%1,4f [S] \f", t2, an1);
  if (tiempo2 == 0) {
    tiempo2 = 1;
  }
  if (tiempo1 == 0) {
    tiempo1 = 1;
  }
}


