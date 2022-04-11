#include <SparkFun_TB6612.h>
volatile int contador = 0;   // Variable entera que se almacena en la RAM del Micro 
void setup() {
  Serial.begin(9600);
  attachInterrupt(0,interrupcion0,RISING);  // Interrupcion 0 (pin2) 
}                                        
 
void loop() {
  delay(999);               // retardo de casi 1 segundo
  Serial.print(contador*30); // Como son dos interrupciones por vuelta (contador * (60/2))
  Serial.println(" RPM");    //  El numero 2 depende del numero aspas de la helise del motor en prueba
  contador = 0;
} 
void interrupcion0()    // Funcion que se ejecuta durante cada interrupion
{
  contador++;           // Se incrementa en uno el contador
}

