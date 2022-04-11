
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//pines de sensores lcd( RS,E,D4,D5,D6,D7) RW=GND
//////////////

///LIBRERIA SENSOR DTH22
#include <DHT.h>
#define DHTPIN A0   // pin de datos
#define DHTTYPE DHT22   // DHT 22  
DHT dht(DHTPIN, DHTTYPE);

/////variables sensor
int humedad;
int temperatura;
///////variable extra/////
char opcion;
char telefono[20];
int temp = 15;
int hum = 45;
int foco = 4;
int ventiladorfoco = 5;
int vapor = 6;
int ventiladorhumedad = 7;
int aux;

void setup() {
  ///declaro pines
  pinMode(foco, OUTPUT);
  pinMode(ventiladorfoco, OUTPUT);
  pinMode(ventiladorhumedad, OUTPUT);
  pinMode(vapor, OUTPUT);
  //comunicacion serial
  Serial.begin(9600);
  //inicializo lcd
  lcd.begin(16, 2);
  //mostrar mensaje
  lcd.setCursor(1, 0);
  lcd.print("ELECTRONICA DE");
  lcd.setCursor(4, 1);
  lcd.print("POTENCIA");
  delay(1000);
  Barridolcd();
}


void loop() {
  ////TELEFONO
  
  if (Serial.available() > 0) {
    opcion = Serial.read();
    switch (opcion) {
      case '1' :
        lcd.clear();
        lcd.print("...PROCESANDO...");
        delay(500);
        Barridolcd();
        while(temp!=temperatura || hum!=humedad){
          enviarTelefono();
          Mostrarlcd();
          EtapaControl();
        }
        if(temp==temperatura){
          Completo();
          delay(200);
        }
          Mostrarlcd();
          opcion=' ';
        break;

      case '2' :
        lcd.clear();
        lcd.print("...VISUALIZAR...");
        delay(500);
        Barridolcd();
        visualizar();
        delay(500);
        enviarTelefono();
        break ;

      case 'a':
        temp = temp + 1;
        delay(250);
        enviarTelefono();
        Mostrarlcd();
        opcion = ' ';
        break;

      case 'b':
        temp =temp - 1;
        delay(250);
        enviarTelefono();
        Mostrarlcd();
        opcion = " ";
        break;

      case 'c':
        hum = hum + 1;
        delay(250);
        enviarTelefono();
        Mostrarlcd();
        opcion = ' ';
        break;

      case 'd':
        hum = hum - 1;      
        delay(250);
        enviarTelefono();
        Mostrarlcd();
        opcion = ' ';
        break;
    }
  }
}
void Mostrarlcd() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("t=");
  lcd.print(temp);
  lcd.setCursor(10, 0);
  lcd.print("h=");
  lcd.print(hum);
  lcd.setCursor(1, 1);
  lcd.print("t=");
  lcd.print(temperatura);
  lcd.setCursor(10, 1);
  lcd.print("H=");
  lcd.print(humedad);
}
void enviarTelefono() {
  temperatura = dht.readTemperature();
  humedad = dht.readHumidity();
  sprintf(telefono, "t=%i*h=%i*T=%i*H=%i",temp,hum,temperatura, humedad);
  /*
  Serial.print(temp);
  Serial.print("*");
  Serial.print(hum);
  Serial.print("*");
  Serial.print((int)temperatura);
  Serial.print("*");
  Serial.println((int)humedad);
  */
  Serial.println(telefono);
}
void visualizar() { 
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Actualmente :");
  lcd.setCursor(1, 1);
  lcd.print("Temp=");
  lcd.print(temperatura);
  lcd.setCursor(10, 1);
  lcd.print("Hum=");
  lcd.print(humedad);
}
void EtapaControl() {
  if (temperatura > temp) {
    digitalWrite(ventiladorfoco, HIGH);
    digitalWrite(foco, LOW);
  }
  if (temperatura < temp) {
    digitalWrite(foco, HIGH);
    digitalWrite(ventiladorfoco, LOW);
  }
  if (temp == temperatura) {
    digitalWrite(foco, LOW);
    digitalWrite(ventiladorfoco, LOW);
  }
  if (humedad > hum) {
    digitalWrite(vapor, LOW);
    digitalWrite(ventiladorhumedad,HIGH);
    
  }
  if (humedad < hum) {
    digitalWrite(vapor, HIGH);
    digitalWrite(ventiladorhumedad,LOW);
  }
  if (hum == humedad) {
    digitalWrite(vapor, LOW);
    digitalWrite(ventiladorhumedad,LOW);
  }
  delay(100);  
}
void Barridolcd(){
  for (int i = 0; i < 40; i++) {
    lcd.scrollDisplayRight();
    delay(100);
  }
  delay(500);  
}

void Completo(){
  lcd.clear();
  lcd.print("...COMPLETADO...");
  delay(500);
  digitalWrite(foco, LOW);
  digitalWrite(ventiladorfoco, LOW);
  digitalWrite(vapor, LOW);
  digitalWrite(ventiladorhumedad,LOW);
  }







