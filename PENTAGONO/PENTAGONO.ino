
#include "openGLCD.h"
#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"
int x1,x2,x3,x4,x5;
int y1,y2,y3,y4,y5,cx=61,cy=31;
int apota,radio,adc,cont=0,dibujo=0;
char text;
void calculos();
void pentagono();
void fuente() {
   GLCD.SelectFont(Arial14);
}
void setup() {
  GLCD.Init();
  fuente();
}
void loop() {
  calculos();
  pentagono();
  delay(1000);
  GLCD.ClearScreen();
}
void calculos(){
 adc=analogRead(A0);
 radio=(adc*31)/1023;
 apota=(sqrt(pow(radio,2)-pow(radio/2,2)));
 x1=61-(radio/2);
 x2=x1+radio;
 x3=61+sqrt(pow(radio,2)-pow((cos(30)*radio),2));
 x4=61;
 x5=61-sqrt(pow(radio,2)-pow((cos(30)*radio),2));
 ///////
 y1=31+apota;
 y2=y1;
 y3=31-(cos(30)*radio);
 y4=31-radio;
 y5=y3;
}
void pentagono(){
 GLCD.DrawLine(x1,y1,x2,y2,BLACK);  //Abajo izquierda
 GLCD.DrawLine(x2,y2,x3,y3,BLACK);  //abajo derecha
 GLCD.DrawLine(x3,y3,x4,y4,BLACK);  //arriba derecha
 GLCD.DrawLine(x4,y4,x5,y5,BLACK);  //arriba
 GLCD.DrawLine(x5,y5,x1,y1,BLACK);  //arriba izquierda
}


