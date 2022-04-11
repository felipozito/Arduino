
#include <openGLCD.h>
#include <fonts/allFonts.h>         // system and arial14 fonts are used
#include <bitmaps/allBitmaps.h>      // all images in the bitmap dir 

int an0, an1, an2, an3;
int dato2, x1, x2, x3, x4;
int valorADC;
int bt1 = 3;
int bt2 = 2;
int bt3 = 18;
int var = 0;
int ejex, ejey, lado1, lado2;
int encendido = 0;

void fuente() {
  GLCD.SelectFont(Wendy3x5);
}
void setup()
{
  Serial.begin(9600);  // Debugging only
  GLCD.Init();
  fuente();
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  attachInterrupt(digitalPinToInterrupt(bt1), interrupcion1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(bt2), interrupcion2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(bt3), interrupcion3, CHANGE);
  GLCD.ClearScreen();
  GLCD.DrawBitmap(Prueba,1,1,BLACK);///Dibujo
  GLCD.DrawRect(0, 0, 127, 63, BLACK);
  GLCD.CursorToXY(63, 0);
  GLCD.println("OFF");
  GLCD.SetDot(63,32,BLACK);
  GLCD.SetDot(13,32,BLACK);///Creo Puntos
  GLCD.SetDot(103,32,BLACK);
}

void loop() {
  ////ENCENDIDO
  while (encendido == 1) {
    GLCD.CursorToXY(63, 0);
    GLCD.println(("ON"));
    GLCD.DrawRect(0, 0, 127, 63, BLACK);
    ////CODIGO ENCENDIDO
    if (var == 1) {
      operaciones();
      delay(100);
      grafico();
    }
  } 
  while (encendido == 2) {
    GLCD.CursorToXY(63, 0);
    GLCD.println("OFF");
    GLCD.DrawRect(0, 0, 127, 63, BLACK);
    var = 0;
  }
}

void interrupcion1() {
  GLCD.ClearScreen();
  while(bt1==1);
  encendido++;
  if (encendido == 3) {
    encendido = 0;
  }
}
void interrupcion2() {
  ///Muestras adc y luego rombo
  var = 1;
}
void interrupcion3() {
  ///BORRA TODO
  while(bt3==1);
  GLCD.ClearScreen();
  var = 0;
}
////////////////////////////////////////////////////////////////
//////////////////////////
void operaciones() {
  an0 = analogRead(A0);
  ejex = map(an0, 0, 1023, 0, 127);
  an1 = analogRead(A1);
  ejey = map(an1, 0, 1023, 0, 63);
  an2 = analogRead(A2);
  x1 = map(an2, 0, 1023, 0, 63);
  x2 = map(an2, 0, 1023, 0, 31);
  an3 = analogRead(A3);
  x3 = map(an3, 0, 1023, 0, 63);
  x4 = map(an3, 0, 1023, 0, 31);
  fuente();
  GLCD.CursorToXY(3, 5);
  GLCD.Printf("%d ", an0);
  GLCD.CursorToXY(100, 5);
  GLCD.Printf("%d ", an1);
  GLCD.CursorToXY(3, 55);
  GLCD.Printf("%d ", an2);
  GLCD.CursorToXY(100, 55);
  GLCD.Printf("%d ", an3);
  delay(100);
}
void grafico() {
  ///EJEX
  GLCD.DrawLine(63, 31, 63 + ejex, 31, BLACK);
  GLCD.DrawLine(63, 31, 63 - ejex, 31, BLACK);
  
  //EJEY
  GLCD.DrawLine(63, 31, 63 + ejey, 31, BLACK);
  GLCD.DrawLine(63, 31, 63 - ejey, 31, BLACK);
  //Diagonal1
  GLCD.DrawLine(63, 31, 63 + x1, 31 - x2, BLACK);
  GLCD.DrawLine(63, 31, 63 - x1, 31 + x2, BLACK);
  ///Diagonal2
  GLCD.DrawLine(63, 31, 63 - x1, 31 - x2, BLACK);
  GLCD.DrawLine(63, 31, 63 + x1, 31 + x2, BLACK);
  ///GRAFICO
  delay(100);
  GLCD.ClearScreen();
}
