
#include <VirtualWire.h>
#include "openGLCD.h"
#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"       // all images in the bitmap dir 
#define BARMAXVAL 100
#define DELAY 900 // delay between "demos"
#define SDELAY DELAY/6
int dato1;
int dato2;
int valorADC;
void IntroScreen() {
  GLCD.SelectFont(System5x7);
  //GLCD.DrawBitmap(icon, 32,0); //draw the bitmap at the given x,y position
}
void setup()
{
  Serial.begin(9600);  // Debugging only
  Serial.println("Receptor: setup");

  // Se inicializa el RF
  vw_setup(2000);  // velocidad: Bits per segundo
  vw_set_rx_pin(2);    //Pin 2 como entrada del RF
  vw_set_tx_pin(3); //Pin 2 como salida para el RF
  vw_rx_start();       // Se inicia como receptor
  GLCD.Init();
  for (int i = 6; i <= 10; i++) { //indicamos los pines de salida
    pinMode(i, OUTPUT);
  }
}

void loop()
{

  valorADC = analogRead(A1);
  //////////////////////////////////recepcion de datos////////////////////
  Serial.println(valorADC);
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  int rev1, rev2;
  //verificamos si hay un dato valido en el RF
  if (vw_get_message((uint8_t *)buf, &buflen))
  {
    int i;
    ///digitalWrite(led,HIGH);
    String  DatoCadena = "";
    //digitalWrite(rec,HIGH);
    if ((char)buf[0] == 'i') //verificamos el inicio de trama
    {
      for (i = 1; i < buflen; i++)
      {
        DatoCadena.concat((char)buf[i]);
      }
      dato1 = DatoCadena.toInt();
      Serial.print("Dato1 recibido: ");
      Serial.println(dato1);
    }

    else if ((char)buf[0] == 'i') //verificamos el inicio de trama
    {
      for (i = 1; i < buflen; i++)
      {
        DatoCadena.concat((char)buf[i]);
      }
      dato1 = DatoCadena.toInt();
      Serial.print("Dato1 recibido: ");
      Serial.println(dato1);
    }
  }
  ////////////////envio de datos/////////////
  char buf1[VW_MAX_MESSAGE_LEN]; // Cadena para enviar
  int dato2 = valorADC; //variable con el tiempo en segundos
  String str = "";
  str = "j" + String(dato2); //convertimos el entero a String y agramos un inicio de trama
  str.toCharArray(buf1, sizeof(buf1)); //convertimos el String en un array
  vw_send((uint8_t *)buf1, strlen(buf1)); //Enviamos el array
  vw_wait_tx(); //Esperamos hasta que el mensaje se envie
  str = "j" + String(dato2); //convertimos el entero a String y agramos un inicio de trama
  str.toCharArray(buf1, sizeof(buf1)); //convertimos el String en un array
  Serial.println(str);
  vw_send((uint8_t *)buf1, strlen(buf1)); //Enviamos el array
  vw_wait_tx(); //Esperamos hasta que el mensaje se envie
  delay(200);



  /////////////////////////////////////////////////7
  int var2 = (dato1) / (10.23);

  GLCD.ClearScreen();
  IntroScreen();
  GLCD.CursorToXY(3, 5);
  GLCD.print("LDP1: ");
  GLCD.CursorToXY(35, 5);
  GLCD.print(dato1);
  /////GLCD.print("             ");
  GLCD.CursorToXY(65, 5);
  GLCD.print("UC ");
  GLCD.CursorToXY(85, 5);
  GLCD.print(var2);
  GLCD.CursorToXY(115, 5);
  GLCD.print("%");
  ///

  // circulos
  ///dato2=1020;
  GLCD.DrawCircle(25, 32, 10, BLACK);
  GLCD.DrawCircle(64, 32, 10, BLACK);
  GLCD.DrawCircle(95, 32, 10, BLACK);

  if (dato1 <= 307) {
    GLCD.FillCircle(25, 32, 10, BLACK );
    GLCD.DrawRect(5, 50, 100, 5, BLACK); // rounded rectangle around text area
    GLCD.FillRect( 5, 50, var2, 5, BLACK);
    digitalWrite(6, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  }

  if (dato1 > 307 && dato1 <= 615) {
    GLCD.FillCircle(25, 32, 9, WHITE );
    GLCD.FillCircle(64, 32, 10, BLACK );
    GLCD.DrawRect(5, 50, 100, 5, BLACK); // rounded rectangle around text area
    GLCD.FillRect( 5, 50, var2, 5, BLACK);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
  }

  if (dato1 > 615 && dato1 <= 922) {
    GLCD.FillCircle(25, 32, 9, WHITE );
    GLCD.FillCircle(95, 32, 10, BLACK );
    GLCD.DrawRect(5, 50, 100, 5, BLACK); // rounded rectangle around text area
    GLCD.FillRect( 5, 50, var2, 5, BLACK);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, HIGH);
  }

  if ( dato1 > 922) {
    GLCD.FillCircle(25, 32, 9, WHITE );
    GLCD.DrawRect(5, 50, 100, 5, BLACK); // rounded rectangle around text area
    GLCD.FillRect( 5, 50, var2, 5, BLACK);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    GLCD.FillCircle(25, 32, 10, BLACK );
    delay(200);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    GLCD.FillCircle(95, 32, 9, WHITE );
    GLCD.FillCircle(25, 32, 9, WHITE );
    GLCD.FillCircle(64, 32, 10, BLACK );
    delay(200);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    GLCD.FillCircle(25, 32, 9, WHITE );
    GLCD.FillCircle(64, 32, 9, WHITE );
    GLCD.FillCircle(95, 32, 10, BLACK );
  }
}
////////////////////////////////////////////////////////////////
//////////////////////////

