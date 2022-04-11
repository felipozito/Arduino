#include <Servo.h>
//#include <MegaServo.h>

#define NBR_SERVOS 2  // the number of servos, up to 48 for Mega, 12 for other boards
#define FIRST_SERVO_PIN 9 

Servo Servos[NBR_SERVOS] ; // max servos is 48 for mega, 12 for other boards

int pos1 = 0;      // variable to store the servo position
int pos2 = 0;
int potPin1 = 0;   // connect a pot to this pin.
int potPin2 = 1;

void setup() {
  for(int i = 0; i < NBR_SERVOS; i++)
    Servos[i].attach(FIRST_SERVO_PIN + i, 800, 2200);
}

void loop() { 
    servoPID(pos1, potPin1, 1);
  servoPID(pos2, potPin2, 2);  
}

void servoPID(int pos, int potPin, int j) {
    Servo Servo[j];
  pos = analogRead(potPin);
    Servo[j].write(map(pos, 0, 1023, 0, 180));
    delay(15);
}
