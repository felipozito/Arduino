
int led[] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
unsigned long tiempo = 500, tiempopasado = 0;
void setup()
{
  Serial.begin(9600);  // Debugging only
  for (int i = 0; i < 13; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  MINEBULIZADOR();
}

void paresimpares () {
  for (int i = 0; i <= 13; i++) {
    if (i & 0x01) {
      digitalWrite(led[i], HIGH);
    }
  }
  delay(100);
  for (int i = 0; i <= 13; i++) {
    if (i & 0x01) {
      digitalWrite(led[i], LOW);
    }
  }
  delay(100);
  for (int i = 0; i <= 13; i++) {
    if (i & 0x00) {
      digitalWrite(led[i], HIGH);
    }
  }
  delay(100);
  for (int i = 0; i <= 13; i++) {
    if (i & 0x00) {
      digitalWrite(led[i], LOW);
    }
  }
  delay(100);
}
void extremosalcentro() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(led[i], HIGH);
    digitalWrite(led[13 - i], HIGH);
    delay(100);
    digitalWrite(led[i], LOW);
    digitalWrite(led[13 - i], LOW);
    delay(100);
  }
  for (int i = 6; i >= 0; i--) {
    digitalWrite(led[i], HIGH);
    digitalWrite(led[13 - i], HIGH);
    delay(100);
    digitalWrite(led[i], LOW);
    digitalWrite(led[13 - i], LOW);
    delay(100);
  }
}
void MINEBULIZADOR() {
  if (millis() - tiempopasado < tiempo) { ///mientras el millis() se menor Ton
    digitalWrite(led[46], HIGH);
  } if (millis() - tiempopasado > tiempo && millis() - tiempopasado <= (2 * tiempo)) {
    digitalWrite(led[46], LOW);
  } if (millis() - tiempopasado > (2 * tiempo) && millis() - tiempopasado <= (3 * tiempo)) {
    digitalWrite(led[45], HIGH);
    digitalWrite(led[47], HIGH);
  } if (millis() - tiempopasado > (3 * tiempo )&& millis() - tiempopasado <= (4 * tiempo)) {
    digitalWrite(led[44], HIGH);
    digitalWrite(led[48], HIGH);
  } if (millis() - tiempopasado > (4 * tiempo) && millis() - tiempopasado <=(5 * tiempo)) {
    digitalWrite(led[43], HIGH);
    digitalWrite(led[49], HIGH);
  } if (millis() - tiempopasado > (5 * tiempo )&& millis() - tiempopasado <= (6 * tiempo)) {
    digitalWrite(led[42], HIGH);
    digitalWrite(led[50], HIGH);
  } if (millis() - tiempopasado > (6 * tiempo) && millis() - tiempopasado <= (7 * tiempo)) {
    digitalWrite(led[41], HIGH);
    digitalWrite(led[51], HIGH);
  } if (millis() - tiempopasado > (7 * tiempo) && millis() - tiempopasado <=(8 * tiempo)) {
    digitalWrite(led[40], HIGH);
    digitalWrite(led[52], HIGH);
  } if (millis() - tiempopasado > (8 * tiempo)) {
    tiempopasado = millis();
    for (int i; i <= 12; i++) {
      digitalWrite(led[40], LOW);
    }
  }
}



