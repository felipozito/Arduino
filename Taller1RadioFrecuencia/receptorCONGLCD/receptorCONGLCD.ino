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

// Instanciacion del LCD i2c:
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

// definicion de nuevos caracter
#define CIRCLE 0
#define BLANK 1
#define TEMP 2
#define HUM 3

byte customChar[8] = {
  B00100,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte customChar1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte customChar2[8] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B01110,
  B11101,
  B11101,
  B01110
};

byte customChar3[8] = {
  B00100,
  B00100,
  B01110,
  B01010,
  B10001,
  B10001,
  B01110,
  B00000
};

//Variables de los datos recibidos
float dato1 = 0.0;
float dato2 = 0.0;


void setup()
{
  //leds salida
  for (int i = 0; i < 10; i++) {
    pinMode(led[i], OUTPUT);
  }
  //Inicializacion del LCD
  lcd.begin(16, 2);
  GLCD.Init();
  lcd.setCursor(0, 0);  // Se pone el cursor en la primera posición de la pantalla.
  lcd.print("Iniciando...");
  delay(1000);
  lcd.createChar(CIRCLE, customChar);
  lcd.createChar(BLANK, customChar1);
  lcd.createChar(TEMP, customChar2);
  lcd.createChar(HUM, customChar3);
  lcd.clear();

  // Se inicializa el RF
  vw_setup(2000);  // velocidad: Bits per segundo
  vw_rx_start();   // Se inicia como receptor

  //glcd
  GLCD.SelectFont(System5x7);
  GLCD.DrawRect(0, 55, 127, 6);
}

void loop() {
  time = millis();
  int tiempo = dato2 / 4;


  if (time - t > tiempo) {
    t = time;

    Serial.print("tiempo:  ");
    Serial.println(millis());
    digitalWrite(led[j], 1);
    j++;
    if (j > 10) {
      for (int i = 0; i <= 10; i++) {
        digitalWrite(led[i], 0);
      }
      j = 0;
    }

  }

  GLCD.GotoXY(0, 0);
  GLCD.print("MICROPROCESADORES 2");
  GLCD.GotoXY(0, 30);
  GLCD.print("Pot1:");
  GLCD.GotoXY(30, 30);
  GLCD.print(dato1);
  GLCD.GotoXY(0, 40);
  GLCD.print("Pot2:");
  GLCD.GotoXY(30, 40);
  GLCD.print(dato2);
  dib = dato1 / 8;

  if (dib > aux1) {
    GLCD.FillRect(0, 55, dib, 5, BLACK);
    GLCD.DrawRect(0, 55, 127, 6);
  }

  if (dib < aux1) {
    GLCD.FillRect(dib, 55, dib + 55, 5, WHITE);
    GLCD.DrawRect(0, 55, 127, 6);
  }
  aux1 = dib;
  //finglcd

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
      Serial.print("Humedad recibido: ");
      Serial.println(dato1);
      lcd.setCursor(0, 0);  // Se pone el cursor en la primera posición de la pantalla.
      lcd.print("POT1: "); lcd.print(dato1);

    }
    else if ((char)buf[0] == 'f') //verificamos el inicio de trama
    {
      for (i = 1; i < buflen; i++)
      {
        DatoCadena.concat((char)buf[i]);
      }
      dato2 = DatoCadena.toFloat();
      Serial.print("Temp recibido: ");
      Serial.println(dato2);
      lcd.setCursor(0, 1);  // Se pone el cursor en la primera posición de la pantalla.
      lcd.print("POT2: "); lcd.print(dato2);
    }
  }
}
