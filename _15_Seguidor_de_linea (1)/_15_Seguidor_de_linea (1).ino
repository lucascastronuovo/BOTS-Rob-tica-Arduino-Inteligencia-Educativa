/*
  Vamos a realizar un robot que sigue una linea negra
*/
//Variables de Salida

const int irIzquierda = 9;
const int irDerecha = 8;
const int ledTest = 13;

/*
  Variables Motor
*/
const int AIA = 3; 
const int AIB = 11;
const int BIA = 10; 
const int BIB = 6;

/*
  Variables Entradas
*/
const int trIzquierda = A0;
const int trDerecha = A1;


/*
  Datos reflectividad guardada
*/
int refDer = 0;
int refIzq = 0;

/*FIN VARIABLES*/

void setup() {
  //INICIO SETUP ENTRADAS / SALIDAS

  pinMode(irIzquierda, OUTPUT);
  pinMode(irDerecha, OUTPUT);
  pinMode(ledTest, OUTPUT);

  digitalWrite(irIzquierda, LOW);
  digitalWrite(irDerecha, LOW);
  digitalWrite(ledTest, LOW);


  /*
     Inicializacion salidas del Motor
  */
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  /*
     colocamos en 0 las salidas y nos aseguramos que está apagado
  */
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  //Saludo Inicial
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);

  Serial.begin(9600);
  
}


void loop() {
  
  digitalWrite(ledTest, HIGH);
  
  digitalWrite(irIzquierda, HIGH);
  refIzq =  analogRead(trIzquierda);

  digitalWrite(irDerecha, HIGH);
  refDer =  analogRead(trDerecha);
  
  digitalWrite(ledTest, LOW);
  
  Serial.print(refIzq);
  Serial.print(",");
  Serial.println(refDer);

  movimiento();

  delay(50);
}
void movimiento(){
    // < 965  --> Blanco  - Deben medir en su entorno
    // > 965  --> Negro   - Deben medir en su entorno
  if (refDer < 970 && refIzq < 970) { //(-XX-)
    atras();
  }
  else if (refDer > 970 && refIzq > 970) { //(-II-)
    adelante();
  }
 
  else if (refDer < 970 && refIzq > 970) { //(-IX-)
    derecha();
  }
  
  else if (refDer > 970 && refIzq < 970) { //(-XI-)
    
    izquierda();
  }
}
/**
   Funciones para controlar el motor
*/
/**
   colocamos en alto los IA y en bajo los IB de los dos motores. 
*/
void adelante()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

/**
   colocamos en alto los IB y en bajo los IA de los dos motores
*/
void atras()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

/**
   Combinamos adelante y atras
*/
void derecha()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}


/**
   Combinamos adelante y atras pero de forma diferente

*/
void izquierda()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
}



