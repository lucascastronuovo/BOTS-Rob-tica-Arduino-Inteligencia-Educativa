//definiendo constantes

const int AIA = 3;
const int AIB = 11;
const int BIA = 10;
const int BIB = 6;

const int ledTest = 13;


void setup()
{
  //definir las salidas

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  pinMode(ledTest, OUTPUT);

  //salidas apagadas

  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  digitalWrite(ledTest, LOW);

  //saludo inicial

  for (int l=0; l<=3; l++);
 {
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
 }
  
  
  
}




void loop()
{
  parpadeo(1);
  adelante();
  delay(1000);
  parar();

  parpadeo(4);
  izquierda();
  delay(250);
  parar();


  parpadeo(1);
  adelante();
  delay(1000);
  parar();

  parpadeo(4);
  izquierda();
  delay(250);
  parar();

 parpadeo(1);
  adelante();
  delay(1000);
  parar();

  parpadeo(4);
  izquierda();
  delay(250);
  parar();


  parpadeo(1);
  adelante();
  delay(1000);
  parar();

  parpadeo(4);
  izquierda();
  delay(250);
  parar();
 
}

void adelante ()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void atras()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

void derecha()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

void izquierda()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void parar()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
}

void parpadeo (int veces)
{
  for (int i=0; i<=veces; i++)
  {
    digitalWrite(ledTest, HIGH);
    delay(200);
    digitalWrite(ledTest, LOW);
    delay(200);
  }
}
