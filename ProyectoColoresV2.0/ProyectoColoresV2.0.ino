//----------------------------Inluyo librerias-----------------------//
#include <EEPROM.h>//libreria para guarda en la memoria EEPROM
#include "Adafruit_TCS34725.h"// libreria sensor de color TCS 34725
#include <SoftwareSerial.h>// libreria para comunicacion Dfplayer mini
#include <DFRobotDFPlayerMini.h>// Libreria DFplayer mini
//----------------------------------------------------------------------//

//-------------------CONFIGURACION DEL SENSOR RGB---------------------//
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);
//----------------------------------------------------------------------//

//-------------------CONFIGURACION DEL REPRODUCTOR---------------------//
DFRobotDFPlayerMini myDFPlayer;
//----------------------------------------------------------------------//

//--------------------------Variables a Usar------------------------------//
int i = 1;
int address = 1;// Direccion de almacenamiento
int Color = 0;// Valor de cada color
int muestras = 25;// Numero de colores a guardar
int aux1, aux2, aux3;
//--------------------------ENTRDAS Y SALIDAS------------------------------//
int boton1 = 6 ;//Pin 3 boton1
int boton2 = 7 ;//Pin 4 boton2
int boton3 = 8 ;//Pin 5 boton3
int indicador = 3; //Led
int buzzer = 2; //Buzzer
//--------------------------Variables para Sensor
uint16_t clearcol, red, green, blue;// Creo variable clearcol-red-green-blue (ENTERO)
float average, r, g, b;// Creo variable average,r,g,b (FLOTANTE)
//-----------------------------------------------------------------//

void setup() {
  Serial.begin (115200);// Inicializo monitor serial
  //*****************INICIALIZO EL REPRODUCTOR****************************************//
  SoftwareSerial mySerial(10, 11);// Inicializo la comunicacion con MDplayer
  mySerial.begin(9600);
  if (!myDFPlayer.begin(mySerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("No Conectado"));
    Serial.println(F("1.Revise Conexiones"));
    Serial.println(F("2.Inserte SD card"));
    while (true);
  } else {
    Serial.println("\nMDPlayer Conectado");
  }
  //*************************INICIALIZO EL SENSOR RGB***********************************//
  if (tcs.begin()) {
    Serial.println("\nSensor Tcs34725 Conectado");
  } else {
    Serial.println("TCS34725 No detectado!");
    while (true);
  }
  //*********************************************************************************//
  // ---------------- Declaro las variables como entrada o salida---------------------//
  pinMode(boton1, INPUT);// Declaro como entrada
  pinMode(boton2, INPUT);// Declaro como entrada
  pinMode(boton3, INPUT);// Declaro como entrada
  pinMode(buzzer, OUTPUT);// Declaro como salida
  pinMode(indicador, OUTPUT);// Declaro como salida
  digitalWrite(buzzer, LOW);// Inicializo apagado
  digitalWrite(indicador, LOW);// Inicializo apagado
  Serial.println("INICIO");
  myDFPlayer.volume(10); //Indico el nivel de volumen(1-30)
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  Sonidos();
  //----------------------------------------------------------------------------------//
}

void loop() {
  //--------------------------Leo las entradas ---------------------------------------//
//  if (digitalRead(boton1) == 1) { // Leo la entrada del btn 1 verde 1 si pulso =1
//    while (digitalRead(boton1)); //antirebote
//    aux1 = 1;
//  }
  if (digitalRead(boton2) == 1) { // Leo la entrada del btn 2 Rojo 2 si pulso=1
    while (digitalRead(boton2)); //Antirebote
    aux2 = 1;
  }
  if (digitalRead(boton3) == 1) { // Leo la entrada del btn 2 Rojo 2 si pulso=1
    while (digitalRead(boton3)); //Antirebote
    aux3 = 1;
  }
  //----------------------------------------------------------------------------------//

  //--------------------------ESTADO DE LA BATERIA---------------------------------------//
  NivelBateria();
  //------------------------------PULSADORE----------------------------------------------------//
  if (aux1 == 1) { // Si se pulso el boton 1
    i = 1; // Inicializo la muestra en 1
    address = 1;// Inicializo la direccion en 1
    Serial.println("\n****ALMACENANDO****");// Imprimo Almacenando
    while (i <= muestras) {
      digitalWrite(indicador, HIGH); // Mientras lee el sensor se activa led
      LeerSensor();
      ImprimirSensor();
      GuardarColor(850);//Indico el tiempo deseado 500ms
      address++; i++; // Aumento la direccion de almacenamiento y muestra +1
      myDFPlayer.stop();//Detengo la cancion del color
      delay(100);
      digitalWrite(indicador, LOW); // Fin de lectura sensor
      delay(100);
    }
    Serial.println("****COLOR GUARDADO*****");
  }

  if (aux2 == 1) { // Si se pulso el boton2
    i = 1;
    Serial.println("\n****REPRODUCIENDO*****");// Imprimo Reproduciendo
    while (i <= muestras) {
      digitalWrite(indicador, HIGH); //Indica Inicio del proceso
      LeerMemoria();
      ColorGuardado(850);//Indico el tiempo deseado 500ms
      myDFPlayer.stop();//Detengo la cancion del color
      i++;// Aumento la direccion a leer +1
      delay(100);
      digitalWrite(indicador, LOW); //Finaliza deteccion y almacenamiento color
      delay(100);
    }
  }

  if (aux3 == 1) { // Si se pulso el boton2
    i = 1;
    Serial.println("\n****LEYENDO****");// Imprimo Leyendo
    while (i <= muestras) {
      digitalWrite(indicador, HIGH); //Indica Inicio del proceso
      LeerSensor();
      ImprimirSensor();
      ReconocerColor(850);//Indico el tiempo deseado 500ms
      i++;// Aumento la muestra +1
      myDFPlayer.stop();//Detengo la cancion del color
      delay(100);
      digitalWrite(indicador, LOW); //Finaliza deteccion y almacenamiento color
      delay(100);
    }
  }
  aux1 = 0;
  aux2 = 0;
  aux3 = 0;
}

void NivelBateria() {
  int voltaje = analogRead(A0);// Leo valor analogico (Bateria)
  if (voltaje <= 670) { // Alerta de Bateria 660==3.2v
    digitalWrite(buzzer, HIGH);// Prendo led
    delay(200);// Espero200ms
    digitalWrite(buzzer, LOW);// Apago led
    delay(200);// Espero200ms
  }
}
void LeerSensor() {
  delay(50);
  tcs.getRawData(&red, &green, &blue, &clearcol);// Lee el sensor y almancena red-green-blue-clearcol
  average = (red + green + blue) / 3;// calculo un promedio
  r = red / average;// leo el valor promedio de rojo
  g = green / average;// leo el valor promedio de verde
  b = blue / average;// leo el valor promedio de azul
}
void ImprimirSensor() { //Unicamente para pruebas Calibracion
  Serial.print("\nClear: "); Serial.print(clearcol);
  Serial.print("\tMuestra: "); Serial.print(i);
  Serial.print("\tRed: "); Serial.print(r);
  Serial.print("\tGreen: "); Serial.print(g);
  Serial.print("\tBlue: "); Serial.print(b);
  Serial.print("\tColor:");
}
void GuardarColor(int tiempo) {
   if ((r > 0.92) && (r < 1.24) && (g > 1.28) && (g < 1.46) && (b > 0.45) && (b < 0.55)){// Valores para color Amarillo
    Serial.print("\tamarillo"); // Imprimo que es el color amarrillo
    EEPROM.write(address, 1);// Almaceno en la memoria direccion x espacio 1
    myDFPlayer.play(1);// Play sonido 1
    delay(tiempo);
  }
  else if ((r > 1.20) && (r < 1.95) && (g > 0.6) && (g < 1.05) && (b > 0.45) && (b < 1.2)) {// Valores para color Rojo
    Serial.print("\trojo");// Color es rojo
    EEPROM.write(address, 2);// Almaceno en la memoria direccion x espacio 2
    myDFPlayer.play(2);// Play sonido 2
    delay(tiempo);
  }
  else  if ((r > 0.68) && (r < 0.8) && (g > 1.23) && (g < 1.54) && (b > 0.72) && (b < 1.06)) {// Valores para color Verde
    Serial.print("\tverde");// Color es verde
    EEPROM.write(address, 3);// Almaceno en la memoria direccion x espacio 3
    myDFPlayer.play(3);// Play sonido 3
    delay(tiempo);
  }
  else if ((r > 0.55) && (r < 0.85) && (g > 0.9) && (g < 1.05) && (b > 1.15) && (b < 1.50)) {// Valores para color Azul
    Serial.print("\tazul");// Color es Azul
    EEPROM.write(address, 4);// Almaceno en la memoria direccion x espacio 4
    myDFPlayer.play(4);// Play sonido 4
    delay(tiempo);
  }
  else if ((r > 0.7) && (r < 1.1) && (g > 0.8) && (g < 1.05) && (b > 1) && (b < 1.3)) {// Valores para color Morado
    Serial.print("\tmorado");// Color es morado
    EEPROM.write(address, 5);// Almaceno en la memoria direccion x espacio 5
    myDFPlayer.play(5);// Play sonido 5
    delay(tiempo);
  }
  else if ((r > 0.40) && (r < 0.65) && (b > 1.08) && (b < 1.40)) {// Valores para color Celeste
    Serial.print("\tceleste");// Color Celeste
    EEPROM.write(address, 6);// Almaceno en memoria direccion x - espacio 6
    myDFPlayer.play(6);// Play sonido 6
    delay(tiempo);
  }
  else if ((r > 0.8) && (r < 1.2) && (g > 0.98) && (g < 1.37) && (b > 0.65) && (b < 1)) {// Valores para color Blanco
    Serial.print("\tblanco");// Color Blanco
    EEPROM.write(address, 7);// Almaceno en memoria direccion xespacio 7
    myDFPlayer.play(7);// Play sonido 7
    delay(tiempo);
  }else {
    Serial.print("\tSin color");// Error
    EEPROM.write(address, 0);// Almaceno en memoria direccion xespacio 0
    delay(tiempo);
  }
}
void ColorGuardado(int tiempo) {
  if (Color == 1) {// si p =1
    Serial.print("\tamarillo"); // Imprimo amarillo
    myDFPlayer.play(1);// Play sonido 1
    delay(tiempo);// tiempo
  }
  if (Color == 2)  {// Si p=2
    Serial.print("\trojo"); // Imprimo rojo
    myDFPlayer.play(2);// Play sonido 2
    delay(tiempo);
  }
  if (Color == 3) {
    Serial.print("\tverde");// Imprimo verde
    myDFPlayer.play(3);// Play sonido 3
    delay(tiempo);
  }
  if (Color == 4) {
    Serial.print("\tazul");//Imprimo azul
    myDFPlayer.play(4);// Play sonido 4
    delay(tiempo);
  }
  if (Color == 5) {
    Serial.print("\tnegro");// Imprimo negro
    myDFPlayer.play(5);// Play sonido 5
    delay(tiempo);

  }
  if (Color == 6 ) {
    Serial.print("\ttomate");// Imprimo tomate
    myDFPlayer.play(6);// Play sonido 6
    delay(tiempo);
  }
  if (Color == 7) {
    Serial.print("\tmorado");// Imprimo morado
    myDFPlayer.play(7);// Play sonido 7
    delay(tiempo);
  }
  if (Color == 8) {
    Serial.print("\tblanco");// Imprimo blanco
    myDFPlayer.play(8);//P lay sonido 8
    delay(tiempo);
  } else {
    Serial.print("\tSin color");// Error
    delay(tiempo);
  }
}
void LeerMemoria() {
  Color = EEPROM.read(i);// Leo la memoria y guardo en Color desde 1
  Serial.print("\nValor de Color: "); Serial.print(Color);
  Serial.print("\tDireccion: "); Serial.print(i);
  Serial.print("\tColor: ");
}
void ReconocerColor(int tiempo) {
  if ((r > 0.92) && (r < 1.24) && (g > 1.28) && (g < 1.46) && (b > 0.45) && (b < 0.55)) { // Valores para color Amarillo
    Serial.print("\tamarillo"); // Imprimo que es el color amarrillo
    myDFPlayer.play(1);// Play sonido 1
    delay(tiempo);
  }
  else if ((r > 1.20) && (r < 1.95) && (g > 0.6) && (g < 1.05) && (b > 0.45) && (b < 1.2)) {// Valores para color Rojo
    Serial.print("\trojo");// Color es rojo
    myDFPlayer.play(2);// Play sonido 2
    delay(tiempo);
  }
  else  if ((r > 0.68) && (r < 0.8) && (g > 1.23) && (g < 1.54) && (b > 0.72) && (b < 1.06)) {// Valores para color Verde
    Serial.print("\tverde");// Color es verde
    myDFPlayer.play(3);// Play sonido 3
    delay(tiempo);
  }
  else if ((r > 0.55) && (r < 0.85) && (g > 0.9) && (g < 1.05) && (b > 1.15) && (b < 1.50)) {// Valores para color Azul
    Serial.print("\tazul");// Color es Azul
    myDFPlayer.play(4);// Play sonido 4
    delay(tiempo);
  }
  else if ((r > 0.7) && (r < 1.1) && (g > 0.8) && (g < 1.05) && (b > 1) && (b < 1.3)) {// Valores para color Morado
    Serial.print("\tmorado");// Color es morado
    myDFPlayer.play(5);// Play sonido 5
    delay(tiempo);
  }
  else if ((r > 0.40) && (r < 0.65) && (b > 1.08) && (b < 1.40)) {// Valores para color Celeste
    Serial.print("\tceleste");// Color Celeste
    myDFPlayer.play(6);// Play sonido 6
    delay(tiempo);
  }
  else if ((r > 0.8) && (r < 1.2) && (g > 0.98) && (g < 1.37) && (b > 0.65) && (b < 1))  {// Valores para color Blanco
    Serial.print("\tblanco");// Color Blanco
    myDFPlayer.play(7);// Play sonido 7
    delay(tiempo);
  } else {
    Serial.print("\tSin color");// Error
    delay(tiempo);
  }
}
void Sonidos(){
  for(int i=1;i<=8;i++){
      myDFPlayer.play(i);//P lay sonido 8
      delay(500);
      myDFPlayer.stop();
    }
}
