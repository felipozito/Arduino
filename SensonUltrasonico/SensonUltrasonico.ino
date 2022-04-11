int trigPin = 10;   // Elegimos el pin para Trig
int echoPin = 9;    // Elegimos el pin para Echo
long duration, cm; // Variables que utilizaremos
 
void setup() {
  
 
  Serial.begin (9600);   // Iniciamos el puerto serial
 
  pinMode(trigPin, OUTPUT);  //Definimos inputs y outputs
  pinMode(echoPin, INPUT);
}
 
void loop() // Iniciamos la secuencia 
{
 
 
  // El emisor se activa al recibir un impulso HIGH de al menos 10 milisegundos.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 

  // La duración es el tiempo, en microsegundos que tarda la señal
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convertimos el tiempo en distancia
  cm = (duration/2) *0.0344; 
  
  // Configuramos al información de salida del puerto serial
  Serial.print("Distancia al objetivo >> ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(500); // Tiempo entre mediciones
}

