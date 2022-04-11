
#include <Keypad.h>
 
const byte filas = 4;
const byte columnas = 4;
 
char teclas[filas][columnas] ={
 { '1','4','7', 'R' },  ///| 1  2   3  INICIO 
 { '2','5','8', '0' },  ///| 4  5   6  TEMPERATURA 
 { '3','6','9', '.' },  ///| 7  8   9  HUMEDAD
 { 'A','B','C', 'D' }   ///| -  0   .  RESET 
};
 
const byte pinfilas[filas] = { 6, 7, 8, 9 };
const byte pincolumnas[columnas] = { 10, 11, 12, 13 };
 
Keypad teclado = Keypad(makeKeymap(teclas), pinfilas, pincolumnas, filas, columnas);
char tecla;
void setup() {
 Serial.begin(9600);
}
 
void loop() {
 tecla= teclado.getKey();
 
 if (tecla) {
 Serial.println(tecla);
 }
}
