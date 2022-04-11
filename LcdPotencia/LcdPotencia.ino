
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600); 
   lcd.begin(16, 2);
   lcd.setCursor(1, 0);
   lcd.print("ELECTRONICA DE");
   lcd.setCursor(2, 1);
   lcd.print("POTENCIA");
    delay(500);
        for(int i=0;i<40;i++){
        lcd.scrollDisplayRight();
        delay(80);
          }
   delay(500);
   lcd.clear(); 
   int t=89;
}


void loop() {
  
  delay(500);
       lcd.clear(); // Limpia la pantalla
       lcd.setCursor(3,0); 
       lcd.print("ERROR SENSOR");
       lcd.setCursor(0,1); 
       lcd.print("REVISAR  DTH22");
       delay(1000);
        for(int i=0;i<40;i++){
          lcd.scrollDisplayRight();
          delay(80);
        }
    delay(1000);  
        
  

  lcd.clear();
  delay(500);
  
  lcd.setCursor(0,0); 
  lcd.print("TEMPERATURA :");
  lcd.setCursor(0,1);
  lcd.print("t");
  delay(1000);
  for(int i=0;i<40;i++){
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);
  lcd.clear(); // 
  delay(500);
  lcd.setCursor(0,0); 
  lcd.print("HUMEDAD : ");
  lcd.setCursor(0,1); 
  lcd.print("*%");
  delay(1000);
  for(int i=0;i<40;i++){
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);

  lcd.clear(); // 
  delay(500);
  lcd.setCursor(0,0); 
  lcd.print("INGRESE LA ");
  lcd.setCursor(0,1); 
  lcd.print("TEMPERATURA");
  delay(1000);

  lcd.clear(); // 
  delay(500);
  lcd.setCursor(0,0); 
  lcd.print("INGRESE LA ");
  lcd.setCursor(0,1); 
  lcd.print("HUMEDAD");
  delay(1000);
  
  lcd.clear(); // 
  delay(500);
  lcd.setCursor(0,0); 
  lcd.print("INICIANDO.... ");
   lcd.noBlink();
  delay(1000);
  lcd.blink();
  delay(1000);
  lcd.setCursor(0,1); 
  lcd.print("PROCESANDO....");
  delay(1000);
  lcd.noBlink();
  delay(1000);
  lcd.blink();
  delay(1000);

}





