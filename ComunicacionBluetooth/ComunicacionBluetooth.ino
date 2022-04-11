
#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(10,11); // RX, TX

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(38400);
  Serial.println("CONFIGURACION AT ");
}

void loop() { // run over and over
  if (Bluetooth.available()) {
    Serial.write(Bluetooth.read());
  }
  if (Serial.available()) {
    Bluetooth.write(Serial.read());
  }
}

