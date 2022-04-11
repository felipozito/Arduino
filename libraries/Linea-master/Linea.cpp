/*

Esta librería es de uso abierto. Pertenece al conjunto de librerías del Robotracer "Open Lamborghino"

La librería Linea.h sirve para obtener facilmente la posición sobre la línea.

Recuerda que debes calibrar los sensores con la función "Linea.calibracion()", si tienes dudas, pregúnta en mi canal de youTube
https://www.youtube.com/lamborghino

Para obtener la posición en la línea, debes ocupar la función Linea.LineaNegra() para línea negra ó Linea.LineaBlanca() para línea blanca... Más fácil, imposible.



*/


#include "Arduino.h"
#include "Linea.h"


#define s0        A0  
#define s1        A1  
#define s2        A2         
#define s3        A3
#define s4        A4
#define s5        A5


int _LED;
long limitup = 15000;
long limitdown = 0;

long pos;

//QTRA
int limitDown_s1 = 1000, limitDown_s2 = 1000, limitDown_s3 = 1000, limitDown_s4 = 1000, limitDown_s5 = 1000,  limitDown_s6 = 1000;
int limitUp_s1 = 0, limitUp_s2 = 0, limitUp_s3 = 0, limitUp_s4 = 0, limitUp_s5 = 0,  limitUp_s6 = 0;
int sensor1, sensor2, sensor3, sensor4, sensor5, sensor6;
int umbralLine = 40;
int sentido = 0;





Linea::Linea(int LED)  //Define el pin LED del QTR 8A
{
	_LED = LED;
  pinMode(_LED,OUTPUT);     
 
}




void Linea::calibracion()
{
	digitalWrite(_LED,HIGH);

  for (int i = 0; i < 150; i++)
  {
    sensor1 = analogRead(s0);
    sensor2 = analogRead(s1);
    sensor3 = analogRead(s2);
    sensor4 = analogRead(s3);
    sensor5 = analogRead(s4);
    sensor6 = analogRead(s5);

    if (sensor1 < limitDown_s1) {
      limitDown_s1 = sensor1;
    } else if (sensor1 > limitUp_s1) {
      limitUp_s1 = sensor1;
    }

    if (sensor2 < limitDown_s2) {
      limitDown_s2 = sensor2;
    } else if (sensor2 > limitUp_s2) {
      limitUp_s2 = sensor2;
    }

    if (sensor3 < limitDown_s3) {
      limitDown_s3 = sensor3;
    } else if (sensor3 > limitUp_s3) {
      limitUp_s3 = sensor3;
    }

    if (sensor4 < limitDown_s4) {
      limitDown_s4 = sensor4;
    } else if (sensor4 > limitUp_s4) {
      limitUp_s4 = sensor4;
    }

    if (sensor5 < limitDown_s5) {
      limitDown_s5 = sensor5;
    } else if (sensor5 > limitUp_s5) {
      limitUp_s5 = sensor5;
    }

    if (sensor6 < limitDown_s6) {
      limitDown_s6 = sensor6;
    } else if (sensor6 > limitUp_s6) {
      limitUp_s6 = sensor6;
    }
	delay(20);

  }
  
  	Serial.print(limitDown_s1);
	Serial.print("\t");
	Serial.print(limitDown_s2);
	Serial.print("\t");
	Serial.print(limitDown_s3);
	Serial.print("\t");
	Serial.print(limitDown_s4);
	Serial.print("\t");
	Serial.print(limitDown_s5);
	Serial.print("\t");
	Serial.print(limitDown_s6);
	Serial.println("\t");
	
	Serial.print(limitUp_s1);
	Serial.print("\t");
	Serial.print(limitUp_s2);
	Serial.print("\t");
	Serial.print(limitUp_s3);
	Serial.print("\t");
	Serial.print(limitUp_s4);
	Serial.print("\t");
	Serial.print(limitUp_s5);
	Serial.print("\t");
	Serial.print(limitUp_s6);
	Serial.println("\t");
    delay(3000);
	umbralLine = limitDown_s1+limitDown_s2+limitDown_s3+limitDown_s4+limitDown_s5+limitDown_s6;
		digitalWrite(_LED,LOW);
 
}



long Linea::LineaNegra()
{
  digitalWrite(_LED,HIGH);
  sensor1 = analogRead(s0);
  sensor2 = analogRead(s1);
  sensor3 = analogRead(s2);
  sensor4 = analogRead(s3);
  sensor5 = analogRead(s4);
  sensor6 = analogRead(s5);

  int sen1 = map(sensor1, limitDown_s1, limitUp_s1, 0, 1000);
  sen1 = constrain(sen1, 0, 1000);

  int sen2 = map(sensor2, limitDown_s2, limitUp_s2, 0, 1000);
  sen2 = constrain(sen2, 0, 1000);

  int sen3 = map(sensor3, limitDown_s3, limitUp_s3, 0, 1000);
  sen3 = constrain(sen3, 0, 1000);

  int sen4 = map(sensor4, limitDown_s4, limitUp_s4, 0, 1000);
  sen4 = constrain(sen4, 0, 1000);

  int sen5 = map(sensor5, limitDown_s5, limitUp_s5, 0, 1000);
  sen5 = constrain(sen5, 0, 1000);

  int sen6 = map(sensor6, limitDown_s6, limitUp_s6, 0, 1000);
  sen6 = constrain(sen6, 0, 1000);


  if (sen1 + sen2 + sen3 + sen4 + sen5 + sen6 >= umbralLine ) {
    _posicion = 5000 - 1000 * (sen1 * 0 + sen2 * 1 + sen3 * 2 + sen4 * 3 + sen5 * 4 + sen6 * 5) / (sen1 + sen2 + sen3 + sen4 + sen5 + sen6);

    if (_posicion > 2500) {
      sentido = 1;
    } else {
      sentido = 0;
    }

  } else {

    if (sentido == 1) {
      _posicion = 5000;
    } else {
      _posicion = 0;
    }
  }
  
  return _posicion;
    digitalWrite(_LED,LOW);
}

long Linea::LineaBlanca()
{
  digitalWrite(_LED,HIGH);
  sensor1 = analogRead(s0);
  sensor2 = analogRead(s1);
  sensor3 = analogRead(s2);
  sensor4 = analogRead(s3);
  sensor5 = analogRead(s4);
  sensor6 = analogRead(s5);

  int sen1 = map(sensor1, limitDown_s1, limitUp_s1, 1000, 0);
  sen1 = constrain(sen1, 0, 1000);

  int sen2 = map(sensor2, limitDown_s2, limitUp_s2, 1000, 0);
  sen2 = constrain(sen2, 0, 1000);

  int sen3 = map(sensor3, limitDown_s3, limitUp_s3, 1000, 0);
  sen3 = constrain(sen3, 0, 1000);

  int sen4 = map(sensor4, limitDown_s4, limitUp_s4, 1000, 0);
  sen4 = constrain(sen4, 0, 1000);

  int sen5 = map(sensor5, limitDown_s5, limitUp_s5, 1000, 0);
  sen5 = constrain(sen5, 0, 1000);

  int sen6 = map(sensor6, limitDown_s6, limitUp_s6, 1000, 0);
  sen6 = constrain(sen6, 0, 1000);


  if (sen1 + sen2 + sen3 + sen4 + sen5 + sen6 >= umbralLine ) {
    _posicion = 5000 - 1000 * (sen1 * 0 + sen2 * 1 + sen3 * 2 + sen4 * 3 + sen5 * 4 + sen6 * 5) / (sen1 + sen2 + sen3 + sen4 + sen5 + sen6);

    if (_posicion > 2500) {
      sentido = 1;
    } else {
      sentido = 0;
    }

  } else {

    if (sentido == 1) {
      _posicion = 5000;
    } else {
      _posicion = 0;
    }
  }
  
  return _posicion;
   digitalWrite(_LED,LOW);
}










