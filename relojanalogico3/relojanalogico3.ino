
/*Reloj pov analogico simple v0.3## Proyecto F 2016 ##   https://www.youtube.com/channel/UC4QNO137PQxvAnCAUXVM-lQ
  Diagrama de conecciones: https:https://mega.nz/#!LIIjRRoJ!IicGZ7mbU_5kpsSVm0Io9o7LJwBDT95QzGqL0LtphSQ
  Informacion y actualizaciones: https://youtu.be/yjg1DjAfrnk
  Codigo libre de uso no comercial para modificar y Compartir!!  //////////////////////////Reg188///*/

///// Declaraciones y variables/////
int led10 = 11;
int led9 = 10;
int led8 = 9;
int led7 = 8;
int led6 = 7;
int led5 = 6;
int led4 = 5;
int led3 = 4;
int led2 = 3;
int led1 = 2;      //led central
int brillo = 25;    // define brillo agujas
int brilloc = 10;  // define brillo cuadrante
int boton = 13;    // define pin sensor
int tiempo = 0;
// establecer sugundos, minutos y hora de inicio.
int segundos = 0;
int minutos = 45;
int hora = 10;
///////////////////
int cuad = 1;


int sep = 860;   // espacio entre puntos cuadrante


//Configuracion Pines
void setup ()
{
  pinMode (led10, OUTPUT);
  pinMode (led9, OUTPUT);
  pinMode (led8, OUTPUT);
  pinMode (led7, OUTPUT);
  pinMode (led6, OUTPUT);
  pinMode (led5, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (boton, INPUT);
  hora = hora * 5;

}

//Programa Principal
void loop ()
{


  if (digitalRead (boton) == HIGH ) {

    tiempo ++;
    if ( tiempo == 15) {
      tiempo = 0; // tiempo define revoluciones en segundos
      segundos = segundos + 1;
    }

    if ( segundos == 60) {
      segundos = 0;

      minutos ++;
    }

    if ( minutos == 60) {
      hora + 5;
      minutos = 0;
    }

    if ( hora >= 60) {
      hora = 0;
    }
    //////////////////////////////////////////////////



    //////////////////////////////////FFFF////////////////////////////////
    //0
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 0) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 0) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 0) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////1
    if ( cuad == 0 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 1) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 1) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 1) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////2
    if ( cuad == 2 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 2) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 2) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 2) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////3
    if ( cuad == 3 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 3) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 3) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 3) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////4
    if ( cuad == 4 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 4) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 4) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 4) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////5
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 5) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 5) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 5) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////6
    if ( cuad == 6 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 6) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 6) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 6) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////7
    if ( cuad == 7 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 7) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 7) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 7) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////8
    if ( cuad == 8 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 8) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 8) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 8) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////9
    if ( cuad == 9 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 9) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 9) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 9) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////10
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 10) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 10) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 10) {
      // digitalWrite(led6,HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      delayMicroseconds(brillo);
      // digitalWrite(led6,LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
    }
    delayMicroseconds (sep);
    //////11
    if ( cuad == 11 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 11) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 11) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 11) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////12
    if ( cuad == 12 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 12) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 12) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 12) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////13
    if ( cuad == 13 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 13) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 13) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 13) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////14
    if ( cuad == 14) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 14) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 14) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 14) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////15
    if ( cuad == 1) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 15) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 15) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 15) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////16
    if ( cuad == 16 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 16) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 16) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 16) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////17
    if ( cuad == 17 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 17) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 17) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 17) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////18
    if ( cuad == 18 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 18) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 18) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 18) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////19
    if ( cuad == 19 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 19) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 19) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 19) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////20
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 20) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 20) {
      // digitalWrite(led8,HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      //  digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 20) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////21
    if ( cuad == 21 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 21) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 21) {
      // digitalWrite(led8,HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      // digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 21) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////22
    if ( cuad == 22 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 22) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 22) {
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      // digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 22) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////23
    if ( cuad == 23 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 23) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 23) {
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      // digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 23) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////24
    if ( cuad == 24 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 24) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 24) {
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      // digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 24) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////25
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 25) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 25) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 25) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////26
    if ( cuad == 26) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 26) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 26) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 26) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////27
    if ( cuad == 27 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 27) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 27) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 27) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////28
    if ( cuad == 28) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 28) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 28) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 28) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////29
    if ( cuad == 29 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 29) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 29) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 29) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////30
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 30) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 30) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 30) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////31
    if ( cuad == 31 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 31) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 31) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 31) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////32
    if ( cuad == 32 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 32) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 32) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 32) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////33
    if ( cuad == 33 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 33) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 33) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 33) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////34
    if ( cuad == 34 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 34) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 34) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 34) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////35
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 35) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 35) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 35) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////36
    if ( cuad == 36) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 36) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 36) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 36) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////37
    if ( cuad == 37 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 37) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 37) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 37) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////38
    if ( cuad == 38) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 38) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 38) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 38) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////39
    if ( cuad == 39 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 39) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 39) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 39) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////40
    if ( cuad == 1) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 40) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 40) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 40) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////41
    if ( cuad == 41 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 41) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 41) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 41) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////42
    if ( cuad == 42 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 42) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 42) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 42) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////43
    if ( cuad == 43 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 43) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 43) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 43) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////44
    if ( cuad == 44 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 44) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 44) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 44) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////45
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 45) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 45) {
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      //  digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 45) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////46
    if ( cuad == 46 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 46) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 46) {
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      //  digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 46) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////47
    if ( cuad == 47 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 47) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 47) {
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      //  digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 47) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////48
    if ( cuad == 48 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 48) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 48) {
      digitalWrite(led7, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      delayMicroseconds(brillo);
      //  digitalWrite(led8,LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if ( hora == 48) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////49
    if ( cuad == 49 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 49) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 49) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 49) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////50
    if ( cuad == 1) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 50) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 50) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 50) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////51
    if ( cuad == 51 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 51) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 51) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 51) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////52
    if ( cuad == 52) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 52) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 52) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 52) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////53
    if ( cuad == 53) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 53) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 53) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 53) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////54
    if ( cuad == 54) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 54) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 54) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 54) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////55
    if ( cuad == 1 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 55) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 55) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 55) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////56
    if ( cuad == 56 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 56) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 56) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 56) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////57
    if ( cuad == 57 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 57) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 57) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 57) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////58
    if ( cuad == 58 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 58) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 58) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 58) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);
    //////59
    if ( cuad == 59 ) {
      digitalWrite(led10 , HIGH);
      delayMicroseconds(brilloc);
      digitalWrite(led10, LOW);
    }
    if ( segundos == 59) {
      digitalWrite(led9, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led9, LOW);
    }
    if ( minutos == 59) {
      digitalWrite(led8, HIGH);
      digitalWrite(led7, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led8, LOW);
      digitalWrite(led7, LOW);
    }
    if ( hora == 59) {
      digitalWrite(led6, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led4, HIGH);
      delayMicroseconds(brillo);
      digitalWrite(led6, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led4, LOW);
    }
    delayMicroseconds (sep);

    //////////////FFFF///////////////



  }
}
