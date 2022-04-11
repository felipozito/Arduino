//----------------------------Inluyo librerias-----------------------//
#include <EEPROM.h>//libreria para guarda en la memoria EEPROM
#include "Adafruit_TCS34725.h"// libreria sensor de color TCS 34725
#include <SoftwareSerial.h>// libreria para comunicacion Dfplayer mini
#include <DFRobotDFPlayerMini.h>// Libreria DFplayer mini
//----------------------------------------------------------------------//


//-------------------CONFIGURACION DEL REPRODUCTOR---------------------//
DFRobotDFPlayerMini myDFPlayer;
//--------------------------ENTRDAS Y SALIDAS------------------------------//
int boton1 = 6 ;//Pin 3 boton1 
int boton2 = 7 ;//Pin 4 boton2 
int boton3 = 8 ;//Pin 5 boton3 
int indicador=3;//Led 
int buzzer=2;//Buzzer 

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
  }else{Serial.println("\nMDPlayer Conectado");}
  // ---------------- Declaro las variables como entrada o salida---------------------//
  pinMode(boton1, INPUT);// Declaro como entrada
  pinMode(boton2, INPUT);// Declaro como entrada
  pinMode(boton3, INPUT);// Declaro como entrada
  pinMode(buzzer, OUTPUT);// Declaro como salida
  pinMode(indicador, OUTPUT);// Declaro como salida
  digitalWrite(buzzer, LOW);// Inicializo apagado
  digitalWrite(indicador, LOW);// Inicializo apagado
  Serial.println("INICIO");
  myDFPlayer.volume(15); //Indico el nivel de volumen(1-30)
  //----------------------------------------------------------------------------------//
}

void loop() {
  //--------------------------Leo las entradas ---------------------------------------//
  if (digitalRead(boton1) == 1) { // Leo la entrada del btn 1 verde 1 si pulso =1
    while(digitalRead(boton1));//antirebote
    digitalWrite(indicador,HIGH);
    delay(500);
    digitalWrite(indicador,LOW);
    delay(500);
  }
  if (digitalRead(boton2) == 1) { // Leo la entrada del btn 2 Rojo 2 si pulso=1
    while(digitalRead(boton2));//Antirebote
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
  }
  if (digitalRead(boton3) == 1) { // Leo la entrada del btn 2 Rojo 2 si pulso=1
    while(digitalRead(boton3));//Antirebote
    todaLaMusica(1000);// Ingresas tiempo entre canciones
  }
  //----------------------------------------------------------------------------------//

}
void todaLaMusica(int tiempo){
  digitalWrite(indicador,HIGH);
  for(int i=1;i<=7;i++){
    myDFPlayer.play(i);
    delay(tiempo);
  }
  digitalWrite(indicador,LOW);
  delay(200);
}


