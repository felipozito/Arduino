// Librerías:
#include <Wire.h>
#include <LiquidCrystal.h>
#include <VirtualWire.h>

#include <openGLCD.h>
int dib;
int contador = 0;
int x = 0;
int y = 0;
int aux1;
int aux2;

///timepoleds
int led[] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
unsigned long time;
unsigned long t = 0;
int tiempo = 100;
int pin = HIGH;
int j = 0;
/// fin tiempos

//Variables de los datos recibidos
float dato1 = 0.0;
float dato2 = 0.0;


void setup()
{
  //leds salida
  for (int i = 0; i < 10; i++) {
    pinMode(led[i], OUTPUT);
  }

  // Se inicializa el RF
  vw_setup(2000);  // velocidad: Bits per segundo
  vw_rx_start();   // Se inicia como receptor

}

void loop() {
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  //verificamos si hay un dato valido en el RF
  if (vw_get_message((uint8_t *)buf, &buflen)) {
    int i;
    String  DatoCadena = "";
    if ((char)buf[0] == 'i') //verificamos el inicio de trama
    {
      for (i = 1; i < buflen; i++)
      {
        DatoCadena.concat((char)buf[i]);
      }
      dato1 = DatoCadena.toFloat();
      Serial.println(dato1);
     
    }
    
  }
}
