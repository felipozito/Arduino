int automatico=4;
int control=5;
int led1=6;
int led2=7;
int pwm=11;
int motor1=12;
int motor2=13;
int pot=A0;

void setup() {
  Serial.begin(9600);
  pinMode(automatico,INPUT);
  pinMode(control,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(pwm,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor1,OUTPUT);
  delay(500);
}
int resp=0;
int adc=0;
void loop() {
 if(digitalRead(automatico)==0){
   resp=1;
  }
 if(digitalRead(control)==0){
   resp=2;
  }
  switch (resp){
    ////Automatico
    case 1:
     digitalWrite(led1,LOW);
     digitalWrite(led2,HIGH);
     adc=analogRead(pot);
     Serial.println(adc);
     if(adc>=0 && adc<510){
       digitalWrite(motor1,HIGH);
       digitalWrite(motor2,LOW);
       analogWrite(pwm,255);
      }
      else if(adc>512 && adc<=1023){
        digitalWrite(motor1,LOW);
        digitalWrite(motor2,HIGH);
        analogWrite(pwm,255);
        }
      else if (adc>=510 && adc<=512){
        digitalWrite(motor1,LOW);
        digitalWrite(motor2,LOW);
        analogWrite(pwm,0);
        }       
    break;
    /////Velocidad variable
    case 2:
     digitalWrite(led1,HIGH);
     digitalWrite(led2,LOW);
     adc=analogRead(pot);
     map(adc,0,1023,-255,255);
     if(adc<0){
       digitalWrite(motor1,HIGH);
       digitalWrite(motor2,LOW);
       analogWrite(pwm,(adc*-1));
      }
      else if(adc>0){
        digitalWrite(motor1,LOW);
        digitalWrite(motor2,HIGH);
        analogWrite(pwm,adc);
        }
      else if (adc==0){
        digitalWrite(motor1,LOW);
        digitalWrite(motor2,LOW);
        analogWrite(pwm,0);
        }  
    break;
    }
}
