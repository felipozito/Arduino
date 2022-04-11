#include <openGLCD.h>
#include <VirtualWire.h>



// DATA 12

int P1 = 0; // variable to store the value coming from the sensor
int P2 = 0;
byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;
int dataInt;
int porcent;

void setup()
{
  //Iniciamos el Serial y la comunicacion por radio
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  Serial.begin(9600);
  //Serial.write("Sistema encendido\n");
  GLCD.Init();

  // Select the font for the default text area
  GLCD.SelectFont(System5x7);
  GLCD.CursorTo(5, 0);
  GLCD.print("Micros II");
  GLCD.CursorTo(0, 2);
  GLCD.print("LDR2:");
  GLCD.CursorTo(12, 2);
  GLCD.print("UC ");
  GLCD.CursorTo(20, 2);
  GLCD.print("% ");
  GLCD.DrawCircle(20, 40, 5);
  GLCD.DrawCircle(50, 40, 5);
  GLCD.DrawCircle(80, 40, 5);
}
void loop()
{

  P1 = analogRead(A0);
  delay(100);
  Serial.println(P1);
  porcent = map(P1,0,1023,0,100);
  GLCD.CursorTo(5, 2);
  GLCD.print(P1);
  delay(50);
  GLCD.print("   ");
  GLCD.CursorTo(15, 2);
  GLCD.print(porcent);
  delay(50);
  GLCD.print("  ");

  if ( porcent > 0 && porcent <= 30) {
    GLCD.FillCircle(20, 40, 4);
    GLCD.FillCircle(50, 40, 4, 0);
    GLCD.FillCircle(80, 40, 4, 0);
    digitalWrite(51, HIGH);
    digitalWrite(52, LOW);
    digitalWrite(53, LOW);

  }
  if ( porcent > 30 && porcent <= 60) {

    GLCD.FillCircle(20, 40, 3, 0);
    GLCD.FillCircle(50, 40, 3);
    GLCD.FillCircle(80, 40, 3, 0);
    digitalWrite(51, LOW);
    digitalWrite(52, HIGH);
    digitalWrite(53, LOW);
  }
  if ( porcent > 60 && porcent <= 90) {

    GLCD.FillCircle(20, 40, 3, 0);
    GLCD.FillCircle(50, 40, 3, 0);
    GLCD.FillCircle(80, 40, 3);
    digitalWrite(51, LOW);
    digitalWrite(52, LOW);
    digitalWrite(53, HIGH);
  }

  if ( porcent > 90 && porcent <= 100) {

    GLCD.FillCircle(20, 40, 3);
    GLCD.FillCircle(50, 40, 3);
    GLCD.FillCircle(80, 40, 3);
    digitalWrite(51, HIGH);
    digitalWrite(52, HIGH);
    digitalWrite(53, HIGH);
    delay(500);
    GLCD.FillCircle(20, 40, 3, 0);
    GLCD.FillCircle(50, 40, 3, 0);
    GLCD.FillCircle(80, 40, 3, 0);
    digitalWrite(51, LOW);
    digitalWrite(52, LOW);
    digitalWrite(53, LOW);
  }
  GLCD.DrawHBarGraph(0, 50, 120, 10, 1, 0, 100, porcent);
}

