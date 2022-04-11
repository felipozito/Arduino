/**
 * Proyecto: Sistema control de temperatura y humeadad
 *
 * Sitio Web: http://www.developer.netau.net/wp
 * 
 * Autor: Carlos R. Primorac (2015)
 * 
 * Este programa es software libre: puedes copiarlo y redistribuirlo modificado o 
 * sin modificar bajo los términos de la Licencia Pública General GNU v3 publicada 
 * por la Fundacion del Software Libre.
 * 
 */
// librerias requeridas
#include <LiquidCrystal.h>
#include <DHT.h>

const int dht11Pin = 8; // pin desde el sensor

int temperaturaControl = 0;
// variables medidas
float temperatura = 0;
float humedad = 0;
float indiceCalor = 0;




LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // objeto lcd
DHT dht11(dht11Pin, DHT11); // objeto DHT11

// caracteres personalizados
byte grados[8] = {
  B00110, 
  B01001,  
  B01001, 
  B00110, 
  B00000, 
  B00000, 
  B00000, 
  B00000,
};

byte flechas[8] = {
  B00100,
  B01110,
  B11111,
  B00000,
  B00000,
  B11111,
  B01110, 
  B00100,
};

byte fanOn[8] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00100,
  B00000,
};

byte fanOff[8] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
};

byte barra[8] {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,  
};

void setup() 
{
  //Serial.begin(9600);
  lcd.begin(16, 2); // inicializa el LCD
  lcd.clear();
  
  // configurar pines
  pinMode(dht11Pin, INPUT);
  
  
  // crear caracteres
  lcd.createChar(0, grados);
  lcd.createChar(1, flechas);
  lcd.createChar(2, fanOn);
  lcd.createChar(3, fanOff);
  lcd.createChar(4, barra);

  // barra de progreso inicializar da tiempo para que el sensor se estabilize
  lcd.setCursor(0,0);
  lcd.print("Inicializando...");
  for (int i = 0; i <= 15; i++) {
    lcd.setCursor(i, 1);
    lcd.write((byte)4);
    delay(250);  
  }
  delay(250);
  lcd.clear();
  delay(500);
  
  // obtener temperatura - humedad - indice de calor
  // pausa de dos segundos para estabilizar el DHT11
  temperatura = dht11.readTemperature(); // obtiene la temperatura ambiente en ºC
  humedad = dht11.readHumidity(); // obtiene la humedad ambiente
  indiceCalor = dht11.computeHeatIndex(dht11.readTemperature(true), humedad); // calcula el indice de calor
  // comprueba la lectura, si falla vuelve a intentar
  if (isnan(humedad) || isnan(temperatura)) {
    //debugging
    //Serial.println("Fallo la lectura del sensor...");
    return;
  }  
  // establece la temperatura de control
  temperaturaControl = temperatura + 1;
  desplegarInformacion();
}

void loop() 
{  
 
 
  lcd.setCursor(6,1);
  lcd.write((byte)1);   
  lcd.setCursor(7,1);
  lcd.print(temperaturaControl);
  lcd.setCursor(10,1);
  lcd.print("Fan");

    
    // obtener temperatura - humedad - indice de calor
    temperatura = dht11.readTemperature(); // obtiene la temperatura ambiente en ºC
    humedad = dht11.readHumidity(); // obtiene la humedad ambiente
    indiceCalor = dht11.computeHeatIndex(dht11.readTemperature(true), humedad); // calcula el indice de calor
    // comprueba la lectura, si falla vuelve a intentar
    if (isnan(humedad) || isnan(temperatura)) {
      //debugging
      //Serial.println("Fallo la lectura del sensor...");
      return;
    }  
    desplegarInformacion();
}

/**
 * desplegar informacion en el LCD
 */
 void desplegarInformacion()
{
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.setCursor(2, 0);
  lcd.print((int)temperatura); 
  lcd.setCursor(4, 0);
  lcd.write((byte)0);

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.setCursor(2, 1);
  lcd.print((int)humedad);
  lcd.setCursor(4, 1);  
  lcd.print("%");

  lcd.setCursor(6, 0);
  lcd.print("IC:");
  lcd.setCursor(9, 0);
  lcd.print(indiceCalor);    
}





 
  



