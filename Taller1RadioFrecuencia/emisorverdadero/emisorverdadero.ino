//Librerias

#include <VirtualWire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(10, 11, 5, 4, 3, 2);
int pot1 = A0;
int pot2 = A1;
int aux1, aux2;

void setup(){
  // Se inicializa el RF
  vw_setup(2000); // velocidad: Bits per segundo
  lcd.begin(16, 2);
}

void loop(){
  lcd.clear();
  float humedad = analogRead(pot1); //Se lee la humedad
  float temperatura = analogRead(pot2); //Se lee la temperatura
  lcd.setCursor(0, 0);
  lcd.print("POT1");
  lcd.setCursor(5, 0);
  lcd.print(humedad, 2);
  lcd.setCursor(0, 1);
  lcd.print("POT2");
  lcd.setCursor(5, 1);
  lcd.print(temperatura, 2);
  char buf[VW_MAX_MESSAGE_LEN]; // Cadena para enviar
  String str = "";
  str = "i" + String(humedad); //convertimos el float a String y agregamos un inicio de trama
  str.toCharArray(buf, sizeof(buf)); //convertimos el String en un array
  vw_send((uint8_t *)buf, strlen(buf)); //Enviamos el array
  vw_wait_tx(); //Esperamos hasta que el mensaje se envie
  
  str = "f" + String(temperatura); //convertimos el float a String y agramos un inicio de trama
  str.toCharArray(buf, sizeof(buf)); //convertimos el String en un array
  vw_send((uint8_t *)buf, strlen(buf)); ////Enviamos el array
  vw_wait_tx(); //Esperamos hasta que el mensaje se envie
  delay(20);
}
