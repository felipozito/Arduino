#include <glcd_Config.h>
#include <glcd_Buildinfo.h>
#include <glcd.h>

#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);    
    Serial.println("Emisor RF");

    // Se inicializa el RF
    vw_setup(2000); // velocidad: Bits per segundo
    vw_set_tx_pin(2); //Pin 2 como salida para el RF 
}

void loop()
{

    
    while (Serial.available() > 0) 
    {
      char dato='a';
      //Enviamos el carácter recibido al RF
      vw_send((uint8_t*)dato,sizeof(dato));
      vw_wait_tx();         
    }
    delay(200);
}
