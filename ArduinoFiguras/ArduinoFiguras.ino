/*Cuadrado rombo circulo cuadrado 
 * Variar con adc 
 * Correo:
 * chris_andrey.9602@hotmail.com
 */
#include "openGLCD.h"
#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"
int x1,x2,x3,x4,x5;
int y1,y2,y3,y4,y5,cx=61,cy=31;
int apota,radio,adc,cont=0,dibujo=0;
int in1=10,in2=11;
void setup() {
  GLCD.Init();
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
}
void loop() {
  if(digitalRead(in1)==0 && digitalRead(in2)==0){// 0 0
    CalculosPentagono();
    Pentagono();
    delay(10);
    GLCD.ClearScreen();
  }
  if(digitalRead(in1)==0 && digitalRead(in2)==1){// 0 1
    Circulo();
    delay(10);
    GLCD.ClearScreen();
  }
  if(digitalRead(in1)==1 && digitalRead(in2)==1){// 1 1
    Triangulo();
    delay(10);
    GLCD.ClearScreen();
  }
  if(digitalRead(in1)==1 && digitalRead(in2)==0){// 0 0
    Cuadrado();
    delay(10);
    GLCD.ClearScreen();
  }
}
void CalculosPentagono(){
 adc=analogRead(A0);//Leo ADC
 radio=map(adc,0,1023,0,31);//MAP(variable,entrada minimo, entrada maximo, salida minimo,salida maximo)
 apota=(sqrt(pow(radio,2)-pow(radio/2,2)));//hallo apota
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
void Pentagono(){
 GLCD.DrawLine(x1,y1,x2,y2,BLACK);  //Abajo izquierda
 GLCD.DrawLine(x2,y2,x3,y3,BLACK);  //abajo derecha
 GLCD.DrawLine(x3,y3,x4,y4,BLACK);  //arriba derecha
 GLCD.DrawLine(x4,y4,x5,y5,BLACK);  //arriba
 GLCD.DrawLine(x5,y5,x1,y1,BLACK);  //arriba izquierda
}
void Circulo(){
  adc=analogRead(A0);//Leo ADC  
  radio=map(adc,0,1023,0,31);//MAP(variable,entrada minimo, entrada maximo, salida minimo,salida maximo)
  GLCD.DrawCircle(63,31,radio,BLACK);
  }
void Triangulo(){
  adc=analogRead(A0);//Leo ADC  
  radio=map(adc,0,1023,0,31);//MAP(variable,entrada minimo, entrada maximo, salida minimo,salida maximo)
  GLCD.DrawTriangle(63-radio,31+radio,63,31-radio,63+radio,31+radio,BLACK);
}
void Cuadrado(){
  adc=analogRead(A0);//Leo ADC  
  radio=map(adc,0,1023,0,31);//MAP(variable,entrada minimo, entrada maximo, salida minimo,salida maximo)
  GLCD.DrawRect(63-radio,31-radio,63+radio,31+radio,BLACK); 
}
