#include <QTRSensors.h>
#define NUM_SENSORS   8     // numeros de sensores
#define TIEMPO       2000  // esperar tiempo inicializarse
#define LEDON   2     // pin de control de sensores Ledon
// indicamos el numero de sensores colocados nuestro caso 6
///codigo de la libreria qtr
QTRSensorsRC qtrrc((unsigned char[]) {0,1,2,3,4,5,6,7},
  NUM_SENSORS, TIEMPO, LEDON); 
unsigned int sensor[NUM_SENSORS];
////indicamos los pines a utilizar 
int led=13;
int motor1a=11; 
int motor1b=A4; 
int motor2a=13; 
int motor2b=A1; 
int ena1=9; 
int ena2=10;
int velmedia=180;
int velmaxima=255;
int velminima=120;
void setup(){
  Serial.begin(9600); 
  pinMode(led,OUTPUT);
  pinMode(motor1a,OUTPUT);
  pinMode(motor1b,OUTPUT);
  pinMode(motor2a,OUTPUT);
  pinMode(motor2b,OUTPUT);
  pinMode(ena1,OUTPUT);
  pinMode(ena2,OUTPUT);
}
void loop(){
  //Leemos los valores de los sensores
  qtrrc.read(sensor);
  /*Cuando el sensor nos da un rango de 2500 o 2000 existe un nivle de reflactance de 0 (LINEA NEGRA)
   *cuando el sensor indica un rango de 0 nos indica que el nivel de reflactancia es maximo(LINEA BLANCA)  
   */
  for (unsigned char i = 0; i < NUM_SENSORS; i++){
    Serial.print(sensor[i]);
    Serial.print('\t'); 
  }
  //PRINCIPIO DEL SEGUIDOR LINEA
  //ADELANTE
   if (sensor[0]<100& sensor[1]<100&sensor[2]>1000 & sensor[3]>1000&&sensor[4]<100&sensor[5]<100){
   analogWrite( ena1, velmaxima);
   analogWrite( ena2, velmaxima);
   digitalWrite(motor1a,HIGH);
   digitalWrite(motor2a,HIGH);
   digitalWrite(motor1b,LOW);
   digitalWrite(motor2b,LOW);
   //DERECHA
    }
    if (sensor[0]<100& sensor[1]<100&sensor[2]>1000 & sensor[3]>500&&sensor[4]<100&sensor[5]<100){
   analogWrite( ena1, velmedia);
   analogWrite( ena2, velmedia);
   digitalWrite(motor1a,HIGH);
   digitalWrite(motor2a,HIGH);
   digitalWrite(motor1b,LOW);
   digitalWrite(motor2b,LOW);
    }
    //IZQUIERDA
     if (sensor[0]<100& sensor[1]<650&sensor[2]>1000 & sensor[3]>1000&&sensor[4]<100&sensor[5]<100){
   analogWrite( ena1, velmedia);
   analogWrite( ena2, velmedia);
   digitalWrite(motor1a,HIGH);
   digitalWrite(motor2a,HIGH);
   digitalWrite(motor1b,LOW);
   digitalWrite(motor2b,LOW);
     }
     //DERECHA 90 grados
    if (sensor[0]<100 && sensor[1]<100 && sensor[2]>1000 && sensor[3]>1000 && sensor[4]>1000 && sensor[5]>1000){
   analogWrite( ena1, velminima);
   analogWrite( ena2, velminima);
   digitalWrite(motor1a,HIGH);
   digitalWrite(motor2a,LOW);
   digitalWrite(motor1b,LOW);
   digitalWrite(motor2b,HIGH);
    }
     //IZQUIERDA 90 grados
    if (sensor[0]<1000& sensor[1 ]<1000&sensor[2]>1000 & sensor[3]>1000&&sensor[4]<100&sensor[5]<100){
   analogWrite( ena1, velminima);
   analogWrite( ena2, velminima);
   digitalWrite(motor1a,LOW);
   digitalWrite(motor2a,HIGH);
   digitalWrite(motor1b,HIGH);
   digitalWrite(motor2b,LOW);
    }
     Serial.println("");  
}

