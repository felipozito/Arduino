#include <LiquidCrystal.h>/
int analog_pin = A1;
float lectura;
float voltaje;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);// pines de conexion del lcd
void setup () {
  pinMode(5, OUTPUT);//Derecha
  pinMode(4, OUTPUT);//Izquierda
  pinMode(6, OUTPUT);//ALTO
  Serial.begin(9600);
  lcd.begin(16, 2);//Inicializo el lcd
}
void loop() {
  lectura = analogRead(analog_pin);
  voltaje= (lectura*5)/1023;
  lcd.setCursor(3, 0);
  lcd.print("EMISOR XBEE");
  lcd.setCursor(1, 1);
  lcd.print(lectura);
  lcd.clear();
  Serial.print('X');// SE MARCA INICIO ENVIO

  Serial.print(voltaje);
  Serial.print('V');
  Serial.print(' ');
  Serial.print(' ');
  Serial.print(' ');
  Serial.print(' ');
  
  if(voltaje>=0.5 && voltaje <=2.5){
   Serial.print('D');
   digitalWrite(5, HIGH);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
    } 
   if(voltaje>2.5 && voltaje <=4.5){
   Serial.print('I');
   digitalWrite(5, LOW);
   digitalWrite(4, HIGH);
   digitalWrite(6, LOW);
    } 
   if(voltaje <0.5){
   Serial.print('P');
   digitalWrite(5, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, HIGH);
    } 
   if(voltaje>4.5){
   Serial.print('A');
   digitalWrite(5, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, HIGH);
    } 
  Serial.print('Y');// SE MARCA FINAL ENVIO
  delay(100);
}
