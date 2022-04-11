int sensor[]={A0,A1,A2,A3,A4,A5,A6,A7};
int limiteInferior[]={1000,1000,1000,1000,1000,1000,1000,1000};
int limiteSuperior[]={0,0,0,0,0,0,0,0};
int pos[]={0,0,0,0,0,0,0,0} ;
int vmax=255,vnormal=150,v;
int valor;
float kp,ki,kd;
float posicion,error=0,Proporcional,Integral,Derivativo;
int i,j,sentido=0;
int umbral = 40;
long mapear(long x, long in_min, long in_max, long out_min, long out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void sensar(){
  sensor[0]=analogRead(A0);
  sensor[1]=analogRead(A1);
  sensor[2]=analogRead(A2);
  sensor[3]=analogRead(A3);
  sensor[4]=analogRead(A4);
  sensor[5]=analogRead(A5);
  sensor[6]=analogRead(A6);
  sensor[7]=analogRead(A7);
}
void calibrar(){
  for (i = 0; i < 100; i++){
    sensar();
    for(j=0;j<=7;j++){
      if (sensor[j] < limiteInferior[j]) {
         limiteInferior[j] =sensor[j];
      }else if (sensor[j] > limiteSuperior[j]) {
         limiteSuperior[j] = sensor[j];
      }
     }
     delay(10);
  }
    umbral = limiteInferior[0]+limiteInferior[1]+limiteInferior[2]+limiteInferior[3]+limiteInferior[4]+limiteInferior[5]+limiteInferior[6]+limiteInferior[7];
}
void PosicionRelativa() {
  sensar();
  int avg=0;
  int sum=0;
  for(i=0;i<=7;i++){
    pos[i]=map(sensor[i],limiteInferior[i],limiteSuperior[i],0,1000);
    if(pos[i]>0 && pos[i]<1000){
      pos[i]=((pos[i]-limiteInferior[i])*1000)/(limiteSuperior[i]-limiteInferior[i]);
      }
    if(pos[i]<=0){pos[i]=0;}
    if(pos[i]>=1000){pos[i]=1000;}
  }
  
  for(i=0;i<=7;i++){
    avg+=pos[i]*(i*1000);
    sum+=pos[i];
    posicion=avg/sum;
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("\t Qtr 8A");
  calibrar();
  Serial.print("\tMinimo\t");Serial.println("Maximo");
  Serial.print("A0 \t");Serial.print(limiteInferior[0]);Serial.print("\t A0 \t");Serial.println(limiteSuperior[0]);
  Serial.print("A1 \t");Serial.print(limiteInferior[1]);Serial.print("\t A1 \t");Serial.println(limiteSuperior[1]);
  Serial.print("A2 \t");Serial.print(limiteInferior[2]);Serial.print("\t A2 \t");Serial.println(limiteSuperior[2]);
  Serial.print("A3 \t");Serial.print(limiteInferior[3]);Serial.print("\t A3 \t");Serial.println(limiteSuperior[3]);
  Serial.print("A4 \t");Serial.print(limiteInferior[4]);Serial.print("\t A4 \t");Serial.println(limiteSuperior[4]);
  Serial.print("A5 \t");Serial.print(limiteInferior[5]);Serial.print("\t A5 \t");Serial.println(limiteSuperior[5]);
  Serial.print("A6 \t");Serial.print(limiteInferior[6]);Serial.print("\t A6 \t");Serial.println(limiteSuperior[6]);
  Serial.print("A7 \t");Serial.print(limiteInferior[7]);Serial.print("\t A7 \t");Serial.println(limiteSuperior[7]);
  delay(2000);
}
void loop() {
  PosicionRelativa();
  Serial.print("Poscicion es :\t");
  Serial.println(posicion);
  Serial.print("\t");
  Serial.print(pos[0]);Serial.print("\t");Serial.print(pos[1]);Serial.print("\t");
  Serial.print(pos[2]);Serial.print("\t");Serial.print(pos[3]);Serial.print("\t");
  Serial.print(pos[4]);Serial.print("\t");Serial.print(pos[5]);Serial.print("\t");
  Serial.print(pos[6]);Serial.print("\t");Serial.print(pos[7]);Serial.print("\t");
  delay(100);

}
