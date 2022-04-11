
#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 8   
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//--------PINES---------//
int foco = 12;
int ventilador=9;
//--------Variables-------//
int Temperatura,temp,Setpoint;
void setup() {
  pinMode(ventilador,OUTPUT);
  pinMode(foco,OUTPUT);
  Serial.begin(9600);
  dht.begin();lcd.begin(16, 2);
  digitalWrite(foco,HIGH); 
  digitalWrite(ventilador,HIGH); 
  lcd.setCursor(1, 0);lcd.print("--CONTROL DE-----");
  lcd.setCursor(2, 1);lcd.print("_TEMPERATURA-----");
  delay(1000);
  digitalWrite(foco,LOW); 
  digitalWrite(ventilador,LOW); 
  lcd.clear();
}

void loop() {
  lcd.clear();delay(1);
  Temperatura = dht.readTemperature();
  Setpoint = analogRead(A0);
  temp = map(Setpoint,0,1023,10,30);
  ImprimirLcd();
  ImprimirSerial();
  if(Temperatura < temp){
     digitalWrite(foco,HIGH); 
     digitalWrite(ventilador,LOW); 
  }
  if(Temperatura > temp){
     digitalWrite(foco,LOW); 
     digitalWrite(ventilador,HIGH);   
  }
  if(Temperatura == temp){
    digitalWrite(ventilador,LOW); 
    digitalWrite(foco,LOW);  
  }
}
void ImprimirLcd(){
  lcd.setCursor(0, 0);lcd.print("Setpoint:");
  lcd.setCursor(10, 0);lcd.print((int)temp); 
  lcd.setCursor(0, 1);lcd.print("Temp:");
  lcd.setCursor(6, 1);lcd.print((int)Temperatura);
}
void ImprimirSerial(){
  Serial.print("\n Setpoint: \t");
  Serial.print((int)temp); 
  Serial.print("\t Temp:\t");
  Serial.print((int)Temperatura);
}

