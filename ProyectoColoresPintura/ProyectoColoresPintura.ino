//----------------------------Inluyo librerias-----------------------//
#include <EEPROM.h>
#include "Wire.h"
#include "Adafruit_TCS34725.h"
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
//----------------------------------------------------------------------//

//-------------------CONFIGURACION DEL SENSOR RGB---------------------//
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);
//----------------------------------------------------------------------//

//-------------------CONFIGURACION DEL REPRODUCTOR---------------------//
 DFRobotDFPlayerMini myDFPlayer;
 //----------------------------------------------------------------------//
 
//****************Declaro variables a utilizar **********************//
int i = 1;
int f = 1;
int j = 1;
int T = 1;
int p = 0;
int tiempo = 700; 
int tiempo1 = 700; 
int capa = 25;
//--------------------------PULSADORES------------------------------//
int pulG = 3 ;//Pin 3 boton1 VERDE
int pulR = 4 ;//Pin 4 boton2 ROJO
int pulL = 5 ;//Pin 5 boton3
//-----------------------------------------------------------------//

void setup(){ 
  Serial.begin (115200);//Inicializo monitor serial//
  //*****************INICIALIZO EL REPRODUCTOR****************************************//
  SoftwareSerial mySerial(10, 11);
  mySerial.begin(9600);
  if (!myDFPlayer.begin(mySerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  myDFPlayer.pause();//Paro el reproductor
  //*********************************************************************************//
   
  //*************************INICIALIZO EL SENSOR RGB***********************************//
  if (tcs.begin()) {
    Serial.println("Sensor gefunden");
  } else {
    Serial.println("TCS34725 nicht gefunden ... Ablauf gestoppt!");
    while (1); // Halt!
  }
  //*********************************************************************************//
  
  // ---------------- Declaro las variables como entrada o salida---------------------//
  pinMode(pulG, INPUT);// Declaro como entrada
  pinMode(pulR, INPUT);// Declaro como entrada
  pinMode(pulL, INPUT);// Declaro como entrada
  pinMode(13, OUTPUT);// Declaro como salida
  digitalWrite(13, LOW);// Inicializo apagado
  digitalWrite(pulG, HIGH);// Pulsador 1 verde entrada empieza 1
  digitalWrite(pulR, HIGH);// Pulsador 2 rojo entrada empieza 1
  digitalWrite(pulL, HIGH);// Pulsador 3 entrada empieza 1
  delay(100);
  //----------------------------------------------------------------------------------//
}

void loop() {
  //--------------------------Leo las entradas ---------------------------------------//
  int vG = digitalRead(pulG);// Leo la entrada del btn 1 verde 1 si pulso =0
  int vR = digitalRead(pulR);// Leo la entrada del btn 2 Rojo 2 si pulso=0
  int vL = digitalRead(pulL);// Leo la entrada del btn 3 si pulso=0
  //----------------------------------------------------------------------------------//
  
 //--------------------------ESTADO DE LA BATERIA---------------------------------------//
  int voltaje = analogRead(A0);// Leo valor analogico (Bateria) 
  if (voltaje <= 660){// Alerta de Bateria 
    alerta();// Voy a la funcion alerta
  }
//----------------------------------------------------------------------------------//
  
  if (vG == 0){// Si pulso el boton 1
    f = 1;
    T = 1;
    Serial.println("GUARDANDO...");
    while (f <= capa){
      //*******************************LECTURA RGB**********************************//
      uint16_t clearcol, red, green, blue;// Creo variable clearcol-red-green-blue (ENTERO)
      float average, r, g, b;// Creo variable average,r,g,b (FLOTANTE)
      delay(10); // Espero 10ms
      tcs.getRawData(&red, &green, &blue, &clearcol);// Lee el sensor y almancena red-green-blue-clearcol
      average = (red + green + blue) / 3;// calculo un promedio
      r = red / average;// leo el valor promedio de rojo
      g = green / average;// leo el valor promedio de verde
      b = blue / average;// leo el valor promedio de azul
      //*****************I***************************************************************//
      
      ////-----------------------Imprimo en el monitor serial----------------------------//
      Serial.print("Clear:"); Serial.print(clearcol);
      Serial.print("  Red:"); Serial.print(r);
      Serial.print("  Green:"); Serial.print(g);
      Serial.print("  Blue:"); Serial.println(b);
      //----------------------------------------------------------------------------------//
      
      //****************** COMPARACION DEL RGB Y CAMBIO A VALORES DE NUMEROS DE CANCIONES********************************************
      
      if ((r > 1.09) && (r < 1.23)) {// Si valor promedio de rojo>1.09 && rojo<1.23
        Serial.print("\tamarillo"); // Imprimo que es el color amarrillo
        EEPROM.write(T, 1);// Almaceno en la memoria direccion 1
        myDFPlayer.play(1);// Reprodusco el sonido 1
        delay(tiempo);
      }
      else if ((r > 1.24) && (g < 1.33) ) {// Si el valor rojo >1.24 & verde <1.33
        Serial.print("\trojo");// Color es rojo
        EEPROM.write(T, 2);// Almaceno en la memoria direccion 2
        myDFPlayer.play(2);// Reprodusco el sonido 2
        delay(tiempo);
      }
      else  if ((b > 0.78) && (b < 0.82) && (g > 1.30) && (g < 1.37)) {// Si azul esta entre 078-0.82 & verde es > 1.37
        Serial.print("\tverde");// Color es verde
        EEPROM.write(T, 3);// Almaceno en la memoria direccion 3
        myDFPlayer.play(3);// Reprodusco sonido 3
        delay(tiempo);
      }
      else if ((b > 0.90) && (b < 0.98) && (r > 0.79) && (r < 0.84)) {// Si azul esta entre 0.90-0.98 & rojo entre 0.79-0.84
        Serial.print("\tazul");// Color es Azul
        EEPROM.write(T, 4);// Almaceno en la memoria direccion 4 
        myDFPlayer.play(4);// Reprodusco sonido 4
        delay(tiempo);
      }
      else if ((g > 1.20) && (g < 1.30 ) && (b > 0.80) && (b < 0.87)) {// Si rojo entre 1.20-1.30 & azul entre 0.80-0.87
        Serial.print("\tmorado");// Color es morado
        EEPROM.write(T, 5);// Almaceno en la memoria direcion 5
        myDFPlayer.play(5);
        delay(tiempo);
      }
      else if ((r > 0.74) && (r < 0.79) && (b > 0.98) && (b < 1.03)) {// Si rojo entre 0.74-0.79 & azul entre 0.98-1.03
        Serial.print("\tceleste");// Color Celeste
        EEPROM.write(T, 6);// Almaceno en memoria direccion 6
        myDFPlayer.play(6);// Reprodusco sonido 6
        delay(tiempo);
      }
      else if ((r > 0.98) && (r < 1.03) && (b > 0.75) && (b < 0.81)) {// Si rojo entre 0.98-1.03 & azul entre 0.75-0.81
        Serial.print("\tblanco");// Color Blanco
        EEPROM.write(T, 7);// Almaceno en memoria direccion 7
        myDFPlayer.play(7);// Reprodusco sonido 7
        delay(tiempo);
      }
      //************************************************************************************************//
      
      Serial.println("****PREPARADO*****");// Imprimo monitor serial
      delay(100);// Espero 100ms
      Serial.println("****COLOR GUARDADO*****");
      Serial.print("VALOR DE i  ");
      Serial.print("pos");
      Serial.print(T);
      Serial.print("  ");
      Serial.print(EEPROM.read(T));
      T = T + 1;
      f = f + 1;
    }
  }
  
  if (vR == 0){// Si pulso el boton2
    i = 1;
    Serial.println("REPRODUCIENDO");// Imprimo Reproduciendo
    while (i <= capa){
      //------------Leo memoria---------------///
      int p = EEPROM.read(i);// Leo la memoria y guardo en p desde 1
      Serial.print("valor de p");// Imprimo en el monitor serial
      Serial.print(i);// Imprimo direccion
      Serial.print("  ");//
      Serial.println(p);// Imprimo el resutado de p
      //--------------------------------------//
      
      //----------------------compara los colores guardados y los reroduce-----------------------------//
      if (p == 1) {// si p =1 
        Serial.print("\tamarillo"); // Imprimo amarillo
        myDFPlayer.play(1);// Play sonido 1
        delay(tiempo);// tiempo
      }
      if (p == 2)  {// Si p=2
        Serial.print("\trojo"); // Imprimo rojo
        myDFPlayer.play(2);// Play sonido 2
        delay(tiempo);
      }
      if (p == 3) {
        Serial.print("\tverde");// Imprimo verde
        myDFPlayer.play(3);// Play sonido 3
        delay(tiempo);
      }
      if (p == 4) {
        Serial.print("\tazul");//Imprimo azul
        myDFPlayer.play(4);// Play sonido 4
        delay(tiempo);
      }
      if (p == 5) {
        Serial.print("\tnegro");// Imprimo negro
        myDFPlayer.play(5);// Play sonido 5
        delay(tiempo);
      }
      if (p == 6 ) {
        Serial.print("\ttomate");// Imprimo tomate
        myDFPlayer.play(6);// Play sonido 6
        delay(tiempo);
      }
      if (p == 7) {
        Serial.print("\tmorado");// Imprimo morado
        myDFPlayer.play(7);// Play sonido 7
        delay(tiempo);
      }
      if (p == 8) {
        Serial.print("\tblanco");// Imprimo blanco
        myDFPlayer.play(8);//P lay sonido 8
        delay(tiempo);
      }
      i = i + 1;// Sumo 1 a i y repito el bucle 
    }
  }
  
  if (vL == 0){// Si pulso el boton 3
    p = 1;
    while (p < capa){
      //***************LECTURA RGB**********************************///
       uint16_t clearcol2, red2, green2, blue2;// Creo variables clearcol2, red2,green2, blue2 (ENTERO)
      float average2, r2, g2, b2;// Creo variables averages2,r2,g2,b2 (FLOTANTE)
      delay(100); //Espero 100ms
      tcs.getRawData(&red2, &green2, &blue2, &clearcol2);// Lee el sensor
      average2 = (red2 + green2 + blue2) / 3;// Calculo el promedio
      r2 = red2 / average2; // Promedio de color rojo 2
      g2 = green2 / average2;// Promedio color verde 2
      b2 = blue2 / average2;// Promedio color Azul 2
      //*********************************************************//
      
      //-------------Imprimo en el monitor Serial----------------//
      Serial.print("Clear:"); Serial.print(clearcol2);
      Serial.print("  Red:"); Serial.print(r2);
      Serial.print("  Green:"); Serial.print(g2);
      Serial.print("  Blue:"); Serial.println(b2);
      Serial.print("*********");
     //-------------------------------------------------------------//
     
      if ((r2 > 1.09) && (r2 < 1.23) && (g2 > 1.23) && (g2 < 1.30)) {// Si valor promedio de rojo entre 1.09-1.23 && verde entre 1.23-1.30
        Serial.print("\tamarillo");
        myDFPlayer.play(1);
        delay(tiempo1);
      }
      if ((r2 > 1.24) && (g2 < 1.33) && (b2 > 0.65) && (b2 < 0.75) ) {// Si el valor rojo >1.24 & verde <1.33 && azul entre 0.65-0.75
        Serial.print("\trojo");
        myDFPlayer.play(2);
        delay(tiempo1);
      }
      if ((b2 > 0.78) && (b2 < 0.82) && (g2 > 1.30) && (g2 < 1.37)) {// Si azul esta entre 078-0.82 & verde es > 1.37
        Serial.print("\tverde");
        myDFPlayer.play(3);
        delay(tiempo1);
      }
      if ((b2 > 0.90) && (b2 < 0.98) && (r2 > 0.79) && (r2 < 0.84)) {// Si azul esta entre 0.90-0.98 & rojo entre 0.79-0.84
        Serial.print("\tazul");
        myDFPlayer.play(4);
        delay(tiempo1);
      }
      if ((g2 > 1.20) && (g2 < 1.30 ) && (b2 > 0.80) && (b2 < 0.87)) {// Si rojo entre 1.20-1.30 & azul entre 0.80-0.87
        Serial.print("\tmorado");
        myDFPlayer.play(5);
        delay(tiempo1);
      }
      if ((r2 > 0.74) && (r2 < 0.79) && (b2 > 0.98) && (b2 < 1.03)) {// Si rojo entre 0.74-0.79 & azul entre 0.98-1.03
        Serial.print("\tceleste");
        myDFPlayer.play(6);
        delay(tiempo1);
      }

      if ((r2 > 0.98) && (r2 < 1.03) && (b2 > 0.75) && (b2 < 0.81)) {// Si rojo entre 0.98-1.03 & azul entre 0.75-0.81
        Serial.print("\tblanco");
        myDFPlayer.play(7);
        delay(tiempo1);
      }
      p = p + 1;
      Serial.print("----------");
      Serial.println(p);
      delay(100);
    }
  }
}

///******************************Funcion Alerta Bateria************************************************//
void alerta(){
  digitalWrite(13, HIGH);// Prendo led
  delay(200);// Espero200ms
  digitalWrite(13, LOW);// Apago led
  delay(200);// Espero200ms 
}



