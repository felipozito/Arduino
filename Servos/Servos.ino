#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos = 0;    // variable to store the servo position
int pos1 = 0;
int pos0 = 0;
int pos2 = 0;
int pos3 = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(11);  // Indica el pin del Servo
  myservo1.attach(10);
  myservo2.attach(9);
  myservo3.attach(8);
  myservo4.attach(12);
  delay(10);
  myservo.write(45); // posicion del servo
  myservo2.write(80);
  myservo1.write(45);
  myservo3.write(45);
  myservo4.write(45);
  delay(500);
}

void loop() {


for (pos = 45; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 45; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

     for (pos0 = 45; pos0 >= 15; pos0 -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos0);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   for (pos0 = 15; pos0 <= 45; pos0 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos0);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  for (pos1 = 80; pos1 <= 120; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 120; pos1 >= 80; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos2 = 80; pos2 <= 120; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo3.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 120; pos2 >= 80; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo3.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos3 = 80; pos3 <= 120; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo4.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos3 = 120; pos3 >= 80; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo4.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

delay(500);

}


