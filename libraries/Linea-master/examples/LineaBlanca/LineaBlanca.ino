#include <Linea.h>

Linea Linea(2); // acá se debe poner el pin del Arduini donde tienen conectado el pin LED del QTR-8A

void setup() {
  Serial.begin(9600);
  Linea.calibracion();
}

void loop()
{

  int a = Linea.LineaBlanca();
  Serial.println(a);
  delay(20);

}

