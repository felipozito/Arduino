/*
Codigo creado por Victor Perez Domingo en plena epoca de examenes.
 Puedes modificar compartir difindur destrozar criticar mejorar e incluso empeorar el codigo a placer.
 
 
 Configuraciones de los pines de conexion de la matriz de leds
 Mi matriz de led esta conectada de la siguiente forma. los dos numeros de cada columna indican la patilla
 positiva y la negativa respectivamente para encender esa casilla.
 el modelo de la matriz es 1588BS y mi patilla 1 es la que se encuentra en la zona superior izquierda mirando desde
 atras con el codigo del modelo en la parte superior.
 ______________
 |  ooooooo   | 
 |  1234567   | 
 |            | 
 |  ooooooo   | 
 |__4321098___|
 
 pongo 4 3 2 1 0 haciendo referencia a  14 13 12 11 10.
 
 		52	50	48	46	44	42	40	38
 		-	-	-	-	-	-	-	-
 39	+	5 16	5 15	5 11	5 6	5 10	5 4	5 3	5 13
 41	+	2 16	2 15	2 11	2 6	2 10	2 4	2 3	2 13
 43	+	7 16	7 15	7 11	7 6	7 10	7 4	7 3	7 13
 45	+	1 16	1 15	1 11	1 6	1 10	1 4	1 3	1 13
 47	+	12 16	12 15	12 11	12 6	12 10	12 4	12 3	12 13
 49	+	8 16	8 15	8 11	8 6	8 10	8 4	8 3	8 13
 51	+	14 16	14 15	14 11	14 6	14 10	14 4	14 3	14 13
 53	+	9 16	9 15	9 11	9 6	9 10	9 4	9 3	9 13
 
 Los numeros de la primera fila y la primera columna son los pines de arduino
 NO se pueden cambiar los pines de conexion ya que los algoritmos tienen en cuanta cuales son. 
 
 */
//Pines de conexion de los botones, son activos a flanco de bajada y tienen activadas resistencias pull up internas
int Bbajar=9; 
int Brotar=10;
int Bizquierda=11;
int Bderecha=12;

/*Pines de la matriz Led NO se pueden cambiar debido a como esta estructurado el codigo
 fila1=53
 fila2=51
 fila3=49
 fila4=47
 fila5=45
 fila6=43
 fila7=41
 fila8=49
 columna1=52
 columna2=50
 columna3=48
 columna4=46
 columna5=44
 columna6=42
 columna7=40
 columna8=38
 
 */
//Incluye el archivo pitches para tocar las notas
#include "pitches.h"  

long milis=0; //Guarda el tiempo actual
long anterior=0; // Guarda el ultimo tiempo en el que se ejecuto la cancion
int thisNote=0; //guarda la nota siguiente
int noteDuration=0; //tiempo que dura la nota
int flag=0; //flanco de subida para controlar el tiempo de la cancion
int pauseBetweenNotes=0;  //tiempo de silencio entre notas
int pantalla[13][16];  // matriz con la posicion de las piezas
boolean iluminar[8][8];  //leds a encender
int pieza=0;    // el numero de la pieza que se esta moviendo
boolean dimensiones[4][4]; //Contiene la pieza que se esta moviendo
int posPiezasx; //posicion de las piezas en el eje X
int posPiezasy; //posicion de las piezas en el eje Y
boolean stoped=1; //se pone a 1 cuando una pieza se para
long desplazamiento=0; //controla el tiempo que tarda una pieza en caer
int tiempodesplazamiento=1000; //tiempo en caer una casilla

boolean flancoPin22=0;//flanco del boton bajar
boolean flancoPin23=0;//flanco del boton rotar
boolean flancoPin24=0;//flanco del boton izquierda
boolean flancoPin26=0;//flanco del boton derecha

boolean rot[4][4]; //variable auxiliar para rotar las piezas

void setup() {

  //  Serial.begin(9600); //lo utilizaba para mandar datos al ordenador
  randomSeed(analogRead(13)); //genera numeros aleatorios en funcion de lo que se lee en el pin 13
  for(int x=0;x<100;x++){
    int j=random(0, 7);
  }   

  for(int k=0;k<17;k++){ //inicializa los pines de la matriz led como salidas
    pinMode(38+k,OUTPUT);
  }

  for(int x=0;x<9;x++){ //inicializa la variable iluminar 
    for(int y=0;y<9;y++){
      iluminar[x][y]=0;
    }
  }
  pinMode(Bbajar,INPUT); //boton 1
  pinMode(Brotar,INPUT); //botn 2
  pinMode(Bizquierda,INPUT); //boton 3
  pinMode(Bderecha,INPUT); // boton 4
  digitalWrite(Bbajar,HIGH); //boton 1 pull-up
  digitalWrite(Brotar,HIGH); //botn 2 pull-up
  digitalWrite(Bizquierda,HIGH); //boton 3 pull-up
  digitalWrite(Bderecha,HIGH); // boton 4 pull-up
  //inicializa para que la matriz led este apagada.
  digitalWrite(38,HIGH);
  digitalWrite(39,LOW);
  digitalWrite(40,HIGH);
  digitalWrite(41,LOW);
  digitalWrite(42,HIGH);
  digitalWrite(43,LOW);
  digitalWrite(44,HIGH);
  digitalWrite(45,LOW);
  digitalWrite(46,HIGH);
  digitalWrite(47,LOW);
  digitalWrite(48,HIGH);
  digitalWrite(49,LOW);
  digitalWrite(50,HIGH);
  digitalWrite(51,LOW);
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW);

}
// esta funcion "dibuja" la matriz iluminar en la matriz led
void dibujar(){

  for(int x=0;x<8;x++){
    for(int y=0;y<8;y++){
      int pinpositivo=53-2*x;
      int pinnegativo=52-2*y;
      digitalWrite(38,HIGH);
      digitalWrite(39,LOW);
      digitalWrite(40,HIGH);
      digitalWrite(41,LOW);
      digitalWrite(42,HIGH);
      digitalWrite(43,LOW);
      digitalWrite(44,HIGH);
      digitalWrite(45,LOW);
      digitalWrite(46,HIGH);
      digitalWrite(47,LOW);
      digitalWrite(48,HIGH);
      digitalWrite(49,LOW);
      digitalWrite(50,HIGH);
      digitalWrite(51,LOW);
      digitalWrite(52,HIGH);
      digitalWrite(53,LOW);
      if (iluminar[x][y]==1){
        digitalWrite(pinpositivo,HIGH);
        digitalWrite(pinnegativo,LOW);
      }
      else{
        digitalWrite(pinpositivo,LOW);
        digitalWrite(pinnegativo,HIGH);
      }  
      ;
    }
  }
}

// las funciones de la A a la H son las figuras, se las llama para crear una nueva.
void A(int a, int b,int id){
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      dimensiones[y][x]=0;
    }
  }
  dimensiones[0][0]=1;
  dimensiones[1][0]=1;
  dimensiones[0][1]=1;
  dimensiones[0][2]=1;
  posPiezasy=b;
  posPiezasx=a+4;
}
void B(int a, int b,int id){
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      dimensiones[y][x]=0;
    }
  }
  dimensiones[0][0]=1;
  dimensiones[1][2]=1;
  dimensiones[0][1]=1;
  dimensiones[0][2]=1; 
  posPiezasy=b;
  posPiezasx=a+4;
}
void C(int a, int b,int id){
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      dimensiones[y][x]=0;
    }
  }
  dimensiones[0][0]=1;
  dimensiones[1][0]=1;
  dimensiones[0][1]=1;
  dimensiones[1][1]=1; 
  posPiezasy=b;
  posPiezasx=a+4;
}
void D(int a, int b,int id){
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      dimensiones[y][x]=0;
    }
  }
  dimensiones[0][0]=1;
  dimensiones[0][1]=1;
  dimensiones[0][2]=1;
  dimensiones[0][3]=1; 
  posPiezasy=b;
  posPiezasx=a+4;
}
void E(int a, int b,int id){
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      dimensiones[y][x]=0;
    }
  }
  dimensiones[0][0]=1;
  dimensiones[0][1]=1;
  dimensiones[0][2]=1;
  dimensiones[1][1]=1; 
  posPiezasy=b;
  posPiezasx=a+4;
}
void H(int a, int b,int id){
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      dimensiones[y][x]=0;
    }
  }
  dimensiones[0][0]=1;
  dimensiones[0][1]=1;
  dimensiones[1][2]=1;
  dimensiones[1][1]=1; 
  posPiezasy=b;
  posPiezasx=a+4;
}
void G(int a, int b,int id){
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      dimensiones[y][x]=0;
    }
  }
  dimensiones[1][0]=1;
  dimensiones[1][1]=1;
  dimensiones[0][2]=1;
  dimensiones[0][1]=1; 
  posPiezasy=b;
  posPiezasx=a+4;
}
//rota las figuras creadas a la derecha
void rotar(){
  int acondicionador=1;
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      rot[3-x][y]=dimensiones[y][x];
    }
  }
  while(acondicionador==1){
    for(int y=0;y<4;y++){
      if(rot[y][0]==1){
        acondicionador=0;
      }
    }
    if (acondicionador==1){
      for(int y=0;y<4;y++){
        rot[y][0]=rot[y][1];
        rot[y][1]=rot[y][2];
        rot[y][2]=rot[y][3];    
        rot[y][3]=0;         
      }
    }
  }

  acondicionador=1;
  while(acondicionador==1){
    for(int x=0;x<4;x++){
      if(rot[0][x]==1){
        acondicionador=0;
      }
    }
    if (acondicionador==1){
      for(int x=0;x<4;x++){
        rot[0][x]=rot[1][x];
        rot[1][x]=rot[2][x];
        rot[2][x]=rot[3][x];    
        rot[3][x]=0;         
      }
    }
  }
  int ocupado=0;
  for(int x=posPiezasx;x<posPiezasx+4;x++){
    if (posPiezasy>0){
      if(posPiezasy-1<8){ 
        for(int s=0;s<4;s++){
          if (pantalla[posPiezasy+s][x]==1&&rot[s][x-posPiezasx]==1){
            ocupado=1;  
          } 
          if (x>11&&rot[s][x-posPiezasx]==1){
            ocupado=1;  
          }        
        }
      }
    }
    else{
      ocupado=1;
    }
  } 

  if (ocupado==0){  
    for(int x=0;x<4;x++){
      for(int y=0;y<4;y++){
        dimensiones[y][x]=rot[y][x];
      }
    }  
  }
}

//crea una pieza de manera aleatoria
void crearPieza(){
  pieza++;

  int aleatorio=random(0, 7);
  switch (aleatorio){
  case 0:
    A(2,8,pieza);
    break;
  case 1:
    B(2,8,pieza);      
    break;
  case 2:
    C(2,8,pieza);
    break;
  case 3:
    E(2,8,pieza);
    break;
  case 4:
    G(2,8,pieza);      
    break;
  case 5:
    H(2,8,pieza);
    break;  
  case 6:
    D(2,8,pieza);
    break;    
  default:
    break;
  }


}
//comprueba si has perdido, gracioso no? xD
void  perdido(){
  boolean hasperdido=0;
  for(int x=4;x<12;x++){
    if(pantalla[7][x]==1){
      ;
      hasperdido=1;
     
      extra=3;
    }
  }
  if (hasperdido==1){
    tiempodesplazamiento=1000;
    for(int y=0;y<13;y++){
      for(int x=0;x<16;x++){
        pantalla[y][x]=0;
      }
    }
  }
}
//se encarga de borrar las linas completadas
void borrarLineas(){
  boolean eliminar=1;
  boolean repetir=1;
  while (repetir==1){
    repetir=0;
    for(int y=0;y<8;y++){
      eliminar=1;
      for(int x=4;x<12;x++){
        if(pantalla[y][x]==0){
          eliminar=0; 
        }
      }
      if (eliminar==1){
        extra=2;
        tiempodesplazamiento=250+tiempodesplazamiento*0.65;
        int top=y+1;
        while (top<8){
          for(int x=4;x<12;x++){
            pantalla[top-1][x]=pantalla[top][x];
            repetir=1;
          }
          top++;
        }
      }
    }  
  } 
}
//el programa principal
void loop() {
  milis=millis();

  dibujar();

  

  //borra la matriz iluminar 
  for(int x=4;x<12;x++){
    for(int y=0;y<8;y++){   
      iluminar[y][x-4]=0;  
    }
  }
  // pasa el valor de pantalla a la matriz iluminar
  for(int x=4;x<12;x++){
    for(int y=0;y<8;y++){
      if(pantalla[y][x]>0){
        iluminar[y][x-4]=1;
      }
      else{     
        // iluminar[y][x-4]=0;
      }

    }
  }
  // pasa el valor de dimensiones a la matriz iluminar
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
      if(posPiezasy+y>7 || posPiezasy+y<0 ||posPiezasx+x-4>7 ||posPiezasx+x-4<0 ){
      }
      else{
        if (dimensiones[y][x]==1){
          iluminar[posPiezasy+y][posPiezasx+x-4]=dimensiones[y][x];   
        }
      }
    }
  }

  //es el boton de bajar, se activa solo cada X tiempo si no lo pulsas
  if(digitalRead(Bbajar)==0 && flancoPin22 == 0 || milis>tiempodesplazamiento+desplazamiento){
    desplazamiento=milis;
    flancoPin22=1;
    //esta funcion mira a ver si la posicion inferior esta ocupada y de ser asi bloquea la pieza en el lugar en el que se encuentra
    int ocupado=0;
    for(int x=posPiezasx;x<posPiezasx+4;x++){
      if (posPiezasy>0){
        if(posPiezasy-1<8){ 
          for(int s=0;s<4;s++){
            if (pantalla[posPiezasy-1+s][x]==1&&dimensiones[s][x-posPiezasx]==1){
              ocupado=1;  
            }
            else{

            }  
          }
        }
      }
      else{
        ocupado=1;
      }
    }

    if (ocupado==1){
      ocupado==0;
      extra=1;
      for(int x=0;x<4;x++){
        for(int y=0;y<4;y++){
          if(posPiezasy+y>7 || posPiezasy+y<0 ||posPiezasx+x>12 ||posPiezasx+x<0 ){
          }
          else{
            if (dimensiones[y][x]==1){
              pantalla[posPiezasy+y][posPiezasx+x]=dimensiones[y][x];   
            }
          }
        }
      }
      borrarLineas();
      perdido();
      crearPieza();
    }

    if (posPiezasy==0){
      posPiezasy=8;
    }
    posPiezasy=posPiezasy-1;

  }
  else if(digitalRead(Bbajar)==1){
    flancoPin22=0;
  }

  //boton de rotar
  if(digitalRead(Brotar)==0 && flancoPin23 == 0){
    flancoPin23=1;
    rotar();

  }
  else if(digitalRead(Brotar)==1){
    flancoPin23=0;
  }

  //boton izquierda
  if(digitalRead(Bizquierda)==0 && flancoPin24 == 0){
    flancoPin24=1;

    int ocupado=0;
    for(int x=0;x<4;x++){
      for(int y=0;y<4;y++){    
        if(dimensiones[y][x]==1 && pantalla[posPiezasy+y][posPiezasx+x-1]==1){
          ocupado=1;
        }
        if(dimensiones[y][x]==1 && posPiezasx==4){
          ocupado=1;
        }    
      }
    }

    if (ocupado==0){
      posPiezasx=posPiezasx-1;
    }


  }
  else if(digitalRead(Bizquierda)==1){
    flancoPin24=0;
  }
  //boton derecha
  if(digitalRead(Bderecha)==0 && flancoPin26 == 0){
    flancoPin26=1;
    int ocupado=0;
    for(int x=0;x<4;x++){
      for(int y=0;y<4;y++){    
        if(dimensiones[y][x]==1 && pantalla[posPiezasy+y][posPiezasx+x+1]==1){
          ocupado=1;
        }
        if(dimensiones[y][x]==1 && posPiezasx+x+1-4>7){
          ocupado=1;
        }    
      }
    }

    if (ocupado==0){
      posPiezasx=posPiezasx+1;
    }

  }
  else if(digitalRead(Bderecha)==1){
    flancoPin26=0;
  }

}

