

#ifndef Linea_h
#define Linea_h
#include "Arduino.h"



class Linea
{
  public:
    Linea(int LED);
	long LineaNegra();
	long LineaBlanca();
    void calibracion();

  private:

	int _posicion;
};

#endif
