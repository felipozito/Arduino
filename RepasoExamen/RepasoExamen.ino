#include <LiquidCrystal.h>
const int rs = 53, en = 51, d4 = 43, d5 = 45, d6 = 47, d7 = 49;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int an3;
int valorADC;
int led[] = {30, 31, 32, 33, 34, 35, 36, 37};
int bt1 = 3;
int bt2 = 2;
int m1 = 11;
int m2 = 12;
int pwm = 13;
int Sentido = 1; int estado = 17;
int encendido = 0; int vel; int aux; int v;
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(8, 0);
  lcd.print("UPS:");
  lcd.setCursor(3, 1);
  lcd.print("DIEGO ROMERO");
  delay(10);
  lcd.clear();
  attachInterrupt(digitalPinToInterrupt(bt1), interrupcion1, FALLING);
  attachInterrupt(digitalPinToInterrupt(bt2), interrupcion2, FALLING);
  pinMode(bt1, INPUT); pinMode(bt2, INPUT);
  pinMode(m1, OUTPUT); pinMode(m2, OUTPUT);
  pinMode(estado, OUTPUT);
  for (int i = 0; i <= 7; i++) {
    pinMode(led[i], OUTPUT);
  }
  for (int i = 0; i <= 7; i++) {
    digitalWrite(led[i], HIGH);
  }
}
void loop() {
  ////ENCENDIDO
  while (encendido == 1) {
    ////CODIGO////
    INICIO:
    digitalWrite(estado, LOW);
    valorADC = analogRead(A3);
    vel = map(valorADC, 0, 1023, 0, 255);
    vel = abs(vel - 255);
    if (Sentido == 1) {
      giroizquierda(vel);
      aux = map(vel, 0, 255, 0, 100);
      imprimir1();
      ///////// LUCEs ////////////
      for (int i = 0; i <= 7; i++) {
        digitalWrite(led[i], LOW);
        delay(aux*10);
        if(encendido != 1){goto INICIO;}
        digitalWrite(led[i], HIGH);
        delay(aux*10);
        if(encendido != 1){goto INICIO;}
      }
 
      ///////// LUCEs ////////////
    } else if (Sentido == 2) {
      giroderecha(vel);
      aux = map(vel, 0, 255, 0, 100);
      imprimir2();
      ///////// LUCEs ////////////
      for (int i = 7; i >= 0; i--) {///NCIENDE LED
        digitalWrite(led[i], LOW);
        delay(aux*10);
        if(encendido != 1){goto INICIO;}
        digitalWrite(led[i], HIGH);
        delay(aux*10);
      }
      ///////// LUCEs ////////////
    }
  }
  ////APAGADO
  while (encendido == 0) {
    lcd.clear();
    digitalWrite(estado, HIGH);
    paromotor();
  }
}
void interrupcion1() {
  while (digitalRead(bt1) == 1);
  encendido++;
  if (encendido == 2) {
    encendido = 0;
  }
}
void interrupcion2() {
  while (digitalRead(bt2) == 1);
  Sentido++;
  if (Sentido == 3) {
    Sentido = 1;
  }
}

void giroderecha(int vel) {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(pwm, vel);
}
void giroizquierda(int vel) {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  analogWrite(pwm, vel);
}
void paromotor() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
}
void imprimir1() {
  lcd.setCursor(1, 0);
  lcd.print("velocidad:");
  lcd.setCursor(11, 0);
  lcd.print(aux);
  lcd.setCursor(1, 1);
  lcd.print("Direccion:");
  lcd.setCursor(12, 1);
  lcd.print("IZQ");
}
void imprimir2() {
  lcd.setCursor(1, 0);
  lcd.print("velocidad:");
  lcd.setCursor(11, 0);
  lcd.print(aux);
  lcd.setCursor(1, 1);
  lcd.print("Direccion:");
  lcd.setCursor(12, 1);
  lcd.print("DER");
}

