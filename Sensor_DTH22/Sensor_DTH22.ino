
#include "DHT.h"
DHT dht1(2, DHT22); 
DHT dht2(3, DHT11); 
int mensaje=0;
boolean start=false;
void setup() {
  Serial.begin(9600); 
  dht1.begin();
  dht2.begin(); 
}
void loop() {
  if (Serial.available()>0){
    mensaje=Serial.read();
    if (mensaje=='1'){
      start=true;
    }
    else
    {
      start=false;
    }
 
  }
  if (start==true){
    float h1 = dht1.readHumidity();
    float t1 = dht1.readTemperature(); 
    float h2 = dht2.readHumidity();
    float t2 = dht2.readTemperature(); 
    Serial.println(h1);
    Serial.println(t1);
    Serial.println(h2);
    Serial.println(t2);
    delay(2000);
  }
}
