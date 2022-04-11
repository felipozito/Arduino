//----------------------------Inluyo librerias-----------------------//
#include <EEPROM.h>//libreria para guarda en la memoria EEPROM
#include "Adafruit_TCS34725.h"// libreria sensor de color TCS 34725
#include <SoftwareSerial.h>// libreria para comunicacion Dfplayer mini
#include <DFRobotDFPlayerMini.h>// Libreria DFplayer mini
//----------------------------------------------------------------------//

//-------------------CONFIGURACION DEL SENSOR RGB---------------------//
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);
//----------------------------------------------------------------------//
//--------------------------Variables a Usar------------------------------//
int i = 1;
int address = 1;// Direccion de almacenamiento
int Color = 0;// Valor de cada color
int muestras = 25;// Numero de colores a guardar
int aux1, aux2, aux3;
float promedioR,promedioB,promedioG;
float promediorojo=0,promedioazul=0,promedioverde=0;
//--------------------------ENTRDAS Y SALIDAS------------------------------//
int boton1 = 6 ;//Pin 3 boton1 
int boton2 = 7 ;//Pin 4 boton2 
int boton3 = 8 ;//Pin 5 boton3 
int indicador=3;//Led 
int buzzer=2;//Buzzer 
//--------------------------Variables para Sensor
uint16_t clearcol, red, green, blue;// Creo variable clearcol-red-green-blue (ENTERO)
float average, r, g, b;// Creo variable average,r,g,b (FLOTANTE)
//-----------------------------------------------------------------//

void setup() {
  Serial.begin (115200);// Inicializo monitor serial
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
  //----------------------------------------------------------------------------------//
}

void loop() {
  //--------------------------Leo las entradas ---------------------------------------//
  if (digitalRead(boton1) == 1) { // Leo la entrada del btn 1 verde 1 si pulso =1
    while(digitalRead(boton1));//antirebote
    aux1 = 1;
  }
  if (digitalRead(boton2) == 1) { // Leo la entrada del btn 2 Rojo 2 si pulso=1
    while(digitalRead(boton2));//Antirebote
    aux2 = 1;
  }
  if (digitalRead(boton3) == 1) { // Leo la entrada del btn 2 Rojo 2 si pulso=1
    while(digitalRead(boton3));//Antirebote
    aux3 = 1;
  }
  //----------------------------------------------------------------------------------//

  //------------------------------PULSADORE----------------------------------------------------//
  if (aux1 == 1) { // Si se pulso el boton 1
    i = 1; // Inicializo la muestra en 1
    address = 1;// Inicializo la direccion en 1
    Serial.println("\n****ALMACENANDO****");// Imprimo Almacenando
    while (i <= muestras) {
        digitalWrite(indicador,HIGH);// Mientras lee el sensor se activa led
        LeerSensor();
        ImprimirSensor();
        GuardarColor(500);//Indico el tiempo deseado 500ms
        address++;i++;// Aumento la direccion de almacenamiento y muestra +1
        delay(100);
        digitalWrite(indicador,LOW);// Fin de lectura sensor 
        delay(100);
        Calibrar();
    }
    Serial.println("****COLOR GUARDADO*****");
    ImprimirCalibracion("ROJO");//Color k esta Calibrando
  }

  if (aux2 == 1) { // Si se pulso el boton2
    i = 1;
    Serial.println("\n****REPRODUCIENDO*****");// Imprimo Reproduciendo
    while (i <= muestras) {
      digitalWrite(indicador,HIGH);//Indica Inicio del proceso
      LeerMemoria();
      ColorGuardado(500);//Indico el tiempo deseado 500ms
      i++;// Aumento la direccion a leer +1
      delay(100);
      digitalWrite(indicador,LOW);//Finaliza deteccion y almacenamiento color
      delay(100);
    }
  }

  if (aux3 == 1) { // Si se pulso el boton2
    i = 1;
    Serial.println("\n****LEYENDO****");// Imprimo Leyendo
    while (i <= muestras) {
      digitalWrite(indicador,HIGH);//Indica Inicio del proceso
      LeerSensor();
      ImprimirSensor();
      ReconocerColor(500);//Indico el tiempo deseado 500ms
      i++;// Aumento la muestra +1 
      delay(100);
      digitalWrite(indicador,LOW);//Finaliza deteccion y almacenamiento color
      delay(100);
    }
  }
  aux1 = 0;
  aux2 = 0;
  aux3 = 0;
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
  Serial.print("\tMuestra: ");Serial.print(i);
  Serial.print("\tRed: "); Serial.print(r);
  Serial.print("\tGreen: "); Serial.print(g);
  Serial.print("\tBlue: "); Serial.print(b);
  Serial.print("\tColor:");
}
void GuardarColor(int tiempo) {
  if ((r > 1.09) && (r < 1.23) && (g>1.05) && (b<0.7)){// Si valor promedio de rojo>1.09 && rojo<1.23
    Serial.print("\tamarillo"); // Imprimo que es el color amarrillo
    EEPROM.write(address, 1);// Almaceno en la memoria direccion x espacio 1
    delay(tiempo);
  }
  else if ((r > 1.24) && (g < 1.33) ) {// Si el valor rojo >1.24 & verde <1.33
    Serial.print("\trojo");// Color es rojo
    EEPROM.write(address, 2);// Almaceno en la memoria direccion x espacio 2
    delay(tiempo);
  }
  else  if ((b > 0.78) && (b < 0.82) && (g > 1.30) && (g < 1.37)) {// Si azul esta entre 078-0.82 & verde es > 1.37
    Serial.print("\tverde");// Color es verde
    EEPROM.write(address, 3);// Almaceno en la memoria direccion x espacio 3
    delay(tiempo);
  }
  else if ((b > 0.90) && (b < 0.98) && (r > 0.79) && (r < 0.84)) {// Si azul esta entre 0.90-0.98 & rojo entre 0.79-0.84
    Serial.print("\tazul");// Color es Azul
    EEPROM.write(address, 4);// Almaceno en la memoria direccion x espacio 4
    delay(tiempo);
  }
  else if ((g > 1.20) && (g < 1.30 ) && (b > 0.80) && (b < 0.87)) {// Si rojo entre 1.20-1.30 & azul entre 0.80-0.87
    Serial.print("\tmorado");// Color es morado
    EEPROM.write(address, 5);// Almaceno en la memoria direccion x espacio 5
    delay(tiempo);
  }
  else if ((r > 0.74) && (r < 0.79) && (b > 0.98) && (b < 1.03)) {// Si rojo entre 0.74-0.79 & azul entre 0.98-1.03
    Serial.print("\tceleste");// Color Celeste
    EEPROM.write(address, 6);// Almaceno en memoria direccion x - espacio 6
    delay(tiempo);
  }
  else if ((r > 0.98) && (r < 1.03) && (b > 0.75) && (b < 0.81)) {// Si rojo entre 0.98-1.03 & azul entre 0.75-0.81
    Serial.print("\tblanco");// Color Blanco
    EEPROM.write(address, 7);// Almaceno en memoria direccion xespacio 7
    delay(tiempo);
  }else {
    Serial.print("\tSin color");// Error
    EEPROM.write(address, 0);// Almaceno en memoria direccion xespacio 7
    delay(tiempo);
  }
}
void ColorGuardado(int tiempo) {
  if (Color == 1) {// si p =1
    Serial.print("\tamarillo"); // Imprimo amarillo
    delay(tiempo);// tiempo
  }
  if (Color == 2)  {// Si p=2
    Serial.print("\trojo"); // Imprimo rojo
    delay(tiempo);
  }
  if (Color == 3) {
    Serial.print("\tverde");// Imprimo verde
    delay(tiempo);
  }
  if (Color == 4) {
    Serial.print("\tazul");//Imprimo azul
    delay(tiempo);
  }
  if (Color == 5) {
    Serial.print("\tnegro");// Imprimo negro
    delay(tiempo);
  }
  if (Color == 6 ) {
    Serial.print("\ttomate");// Imprimo tomate
    delay(tiempo);
  }
  if (Color == 7) {
    Serial.print("\tmorado");// Imprimo morado
    delay(tiempo);
  }
  if (Color == 8) {
    Serial.print("\tblanco");// Imprimo blanco
    delay(tiempo);
  }else {
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
  if ((r > 1.09) && (r < 1.23) && (g>1.05) && (b<0.7)){// Si valor promedio de rojo>1.09 && rojo<1.23
    Serial.print("\tamarillo"); // Imprimo que es el color amarrillo
    delay(tiempo);
  }
  else if ((r > 1.24) && (g < 1.33) ) {// Si el valor rojo >1.24 & verde <1.33
    Serial.print("\trojo");// Color es rojo
    delay(tiempo);
  }
  else  if ((b > 0.78) && (b < 0.82) && (g > 1.30) && (g < 1.37)) {// Si azul esta entre 078-0.82 & verde es > 1.37
    Serial.print("\tverde");// Color es verde
    delay(tiempo);
  }
  else if ((b > 0.90) && (b < 0.98) && (r > 0.79) && (r < 0.84)) {// Si azul esta entre 0.90-0.98 & rojo entre 0.79-0.84
    Serial.print("\tazul");// Color es Azul
    delay(tiempo);
  }
  else if ((g > 1.20) && (g < 1.30 ) && (b > 0.80) && (b < 0.87)) {// Si rojo entre 1.20-1.30 & azul entre 0.80-0.87
    Serial.print("\tmorado");// Color es morado
    delay(tiempo);
  }
  else if ((r > 0.74) && (r < 0.79) && (b > 0.98) && (b < 1.03)) {// Si rojo entre 0.74-0.79 & azul entre 0.98-1.03
    Serial.print("\tceleste");// Color Celeste
    delay(tiempo);
  }
  else if ((r > 0.98) && (r < 1.03) && (b > 0.75) && (b < 0.81)) {// Si rojo entre 0.98-1.03 & azul entre 0.75-0.81
    Serial.print("\tblanco");// Color Blanco
    delay(tiempo);
  }else {
    Serial.print("\tSin color");// Error
    delay(tiempo);
  }
}
void Calibrar(){
  promedioR=promedioR+r;
  promedioB=promedioB+b;
  promedioG=promedioG+g;
}
void ImprimirCalibracion(String coloraCalibrar){
  Serial.println("Calibro Color: ");
  Serial.print(coloraCalibrar);
  Serial.println("Rango Rojo: ");
  Serial.print(promediorojo=promedioR/25);
  Serial.print("\tRango Azul: ");
  Serial.print(promedioazul=promedioB/25);
  Serial.print("\tRango Verde: ");  
  Serial.print(promedioverde=promedioG/25);
  Serial.println("Para la configuracion de color aumentar un rango promedio de +10,-10");
  Serial.println("Cada superficie cambia los valores");
  Serial.println("OJO REVISAR LOS VALORES DE LOS PROMEDIOS");
  promedioR = 0;
  promedioB = 0;
  promedioG = 0;
}
