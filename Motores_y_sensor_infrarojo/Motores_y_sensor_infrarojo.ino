//definir variables de salida
 
const int emIzq = 8;
const int emDer = 9;

const int ledTest = 13;

//variables de los motores
const int AIA = 3;
const int AIB = 11;
const int BIA = 10;
const int BIB = 6;

// variables de entrada

const int reIzq = A0;
const int reDer = A1;

//datos guardados

int valIzq = 0;
int valDer = 0;

void setup()
{
  //iniciamos las salidas
  Serial.begin(9600);

 pinMode(emIzq, OUTPUT);
 pinMode(emDer, OUTPUT);
 pinMode(ledTest, OUTPUT);
 pinMode(AIA, OUTPUT);
 pinMode(AIB, OUTPUT);
 pinMode(BIA, OUTPUT);
 pinMode(BIB, OUTPUT);

 digitalWrite(ledTest, LOW);
 digitalWrite(emIzq, LOW);
 digitalWrite(emDer, LOW);

 analogWrite(AIA, 0);
 analogWrite(AIB, 0);
 analogWrite(BIA, 0);
 analogWrite(BIB, 0);

   //saludo inicial

  for (int l=0; l<3; l++);
 {
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
 }
}

void loop()
{
  digitalWrite(ledTest, HIGH);
  digitalWrite(emIzq, HIGH);
  valIzq = analogRead(reIzq);
  delay(100);
  digitalWrite(emIzq, LOW);
  
  
  digitalWrite(emDer, HIGH);
  valDer = analogRead(reDer);
  digitalWrite(ledTest, LOW);
  delay(100);
  digitalWrite(emDer, LOW);
  
  Serial.print(valIzq);
  Serial.print(",");
  Serial.println(valDer);

  movimiento();
  delay(100);
}

void movimiento()
 {
  if(valIzq<900 && valDer<900)
   {
    atras();
   }

   else if(valIzq>900 && valDer>900)
   {
    adelante();
   }
   else if(valIzq>900 && valDer<900)
   {
    izquierda();
   }
   else if(valIzq<900 && valDer>900)
   {
    derecha();
   }
 }

void adelante()
{
  analogWrite(AIA, 150);
  analogWrite(AIB, 0);
  analogWrite(BIA, 150);
  analogWrite(BIB, 0); 
}

void atras()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 150);
  analogWrite(BIA, 0);
  analogWrite(BIB, 150);
 
}

void derecha()
{
  analogWrite(AIA, 150);
  analogWrite(AIB, 0);
  analogWrite(BIA, 150);
  analogWrite(BIB, 150);
  delay(50);
}

void izquierda()
{
  analogWrite(AIA, 150);
  analogWrite(AIB, 150);
  analogWrite(BIA, 150);
  analogWrite(BIB, 0);
  delay(50);
}
