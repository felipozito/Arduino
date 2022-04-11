
#include "openGLCD.h"
#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"       // all images in the bitmap dir 
int an0,an1,an2,an3;
int dato2;
int valorADC;
int bt1=3;
int bt2=2;
int bt3=18;
int var=0;

void fuente() {
   GLCD.SelectFont(Arial14);
}
void setup()
{
  Serial.begin(9600);  // Debugging only
  GLCD.Init();
  fuente();
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  attachInterrupt(digitalPinToInterrupt(bt1), interrupcion1, HIGH);
  attachInterrupt(digitalPinToInterrupt(bt2), interrupcion2, HIGH);
  attachInterrupt(digitalPinToInterrupt(bt3), interrupcion3, HIGH);
}

void loop(){
 ////CODIGO
 if(var==1){
   opcion1();
 }else if(var==2){
   opcion2();
 }else if(var==3){
   opcion3();
 }
}
void interrupcion1(){
 var=1;
 opcion1();
}
void opcion1(){
fuente();
GLCD.ClearScreen();
GLCD.CursorToXY(20, 10);
GLCD.println(("UNIVERSIDAD"));
GLCD.CursorToXY(20,30);
GLCD.println(("POLITECNICA"));
GLCD.CursorToXY(20, 50);
GLCD.println(("SALESIANA"));
}
void interrupcion2(){
var=2;
opcion2();
}
void opcion2(){
an0=analogRead(A0);
an1=analogRead(A1);
GLCD.ClearScreen();
GLCD.CursorToXY(3, 5);
GLCD.Printf("UC1=%d     UC2=%d ",an0,an1);
delay(50);
}
void interrupcion3(){
var=3;
opcion3();
}
void opcion3(){
an2=analogRead(A2);
an3=analogRead(A3);
GLCD.ClearScreen();
GLCD.CursorToXY(3, 5);
GLCD.Printf("UC2:%d      UC3:%d ",an2,an3);
delay(50); 
}

////////////////////////////////////////////////////////////////
//////////////////////////

