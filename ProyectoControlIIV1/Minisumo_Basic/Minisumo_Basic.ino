//-------------------Pines Para Sensores-----------------//
int SharpDer = A0;
int SharpIzq = A1;
int SharpladoDer = A4;
int SharpladoIzq = A5;
int QtrDer = A2;
int QtrIzq = A3;
int QtrAtras= A6;
//-----------------Varaible de Sensores-----------------//
int Sizq = 0;
int Sder = 0;
int SLadoizq = 0;
int SLadoder = 0;
int Qder = 0;
int Qizq = 0;
int Qatras = 0;
//-----------------Pines de Motores-----------------//
int Mder1 = 4;
int Mder2 = 5;
int Mizq1 = 6;
int Mizq2 = 7;
int Pwm1 = 8;
int Pwm2 = 9;
int Led = 10;

void setup( ) {
  pinMode(Mder1, OUTPUT);
  pinMode(Mder2, OUTPUT);
  pinMode(Mizq1, OUTPUT);
  pinMode(Mizq2, OUTPUT);
  pinMode(Pwm1, OUTPUT);
  pinMode(Pwm2, OUTPUT);
  pinMode(Led, OUTPUT);
  digitalWrite(Led, HIGH);
  delay(500);
  analogWrite(Pwm1, 200);
  analogWrite(Pwm2, 200);
}

void loop() {
  sensores();
  if ((SLadoizq <= 300) && (Sizq <= 300) && (Sder <= 300) && (SLadoder <= 300)) {// 0 0 0 0
    derechasuave();
  }
  if ((SLadoizq <= 300) && (Sizq <= 300) && (Sder <= 300) && (SLadoder >= 300)) {// 0 0 0 1
    derechafuerte();
  }
  if ((SLadoizq <= 300) && (Sizq <= 300) && (Sder >= 300) && (SLadoder <= 300)) {// 0 0 1 0
    derechasuave();
  }
  if ((SLadoizq <= 300) && (Sizq >= 300) && (Sder <= 300) && (SLadoder <= 300)) {// 0 1 0 0
    izquierdasuave();
  } 
  if ((SLadoizq <= 300) && (Sizq >= 300) && (Sder >= 300) && (SLadoder <= 300)) {// 0 1 1 0
    adelante();
  }
  if ((SLadoizq >= 300) && (Sizq <= 300) && (Sder <= 300) && (SLadoder <= 300)) {// 1 0 0 0
    izquierdafuerte();
  }
  if ((Qder <= 500) || (Qizq <= 500)) {// Linea limite Adelante
    atras();
  }
  if(Qatras<=500){// Linea limite Atras
    derechafuerte();
    delay(10);
    adelante(); 
  }
}
void sensores () {
  Sder = analogRead(SharpDer);
  delay(1);
  Sizq = analogRead(SharpIzq);
  delay(1);
  SLadoder = analogRead(SharpladoDer);
  delay(1);
  SLadoizq = analogRead(SharpladoIzq);
  delay(1);
  Qder = analogRead(QtrDer);
  delay(1);
  Qizq = analogRead(QtrIzq);
  delay(1);
  Qatras = analogRead(QtrAtras);
  delay(1);
}
void adelante() {
  digitalWrite(Mder1, HIGH);
  digitalWrite(Mder2, LOW);
  digitalWrite(Mizq1, HIGH);
  digitalWrite(Mizq2, LOW);
}
void atras() {
  digitalWrite(Mder1, LOW);
  digitalWrite(Mder2, HIGH);
  digitalWrite(Mizq1, LOW);
  digitalWrite(Mizq2, HIGH);
}
void parar() {
  digitalWrite(Mder1, LOW);
  digitalWrite(Mder2, LOW);
  digitalWrite(Mizq1, LOW);
  digitalWrite(Mizq2, LOW);
}
void derechasuave() {
  digitalWrite(Mder1, LOW);
  digitalWrite(Mder2, LOW);
  digitalWrite(Mizq1, HIGH);
  digitalWrite(Mizq2, LOW);
}
void derechafuerte() {
  digitalWrite(Mder1, LOW);
  digitalWrite(Mder2, HIGH);
  digitalWrite(Mizq1, HIGH);
  digitalWrite(Mizq2, LOW);
}
void izquierdasuave() {
  digitalWrite(Mder1, HIGH);
  digitalWrite(Mder2, LOW);
  digitalWrite(Mizq1, LOW);
  digitalWrite(Mizq2, LOW);
}
void izquierdafuerte() {
  digitalWrite(Mder1, HIGH);
  digitalWrite(Mder2, LOW);
  digitalWrite(Mizq1, LOW);
  digitalWrite(Mizq2, HIGH);
}
