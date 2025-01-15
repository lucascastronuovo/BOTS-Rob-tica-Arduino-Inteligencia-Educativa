int LedBlancoIzq = 2;
int LedBlancoDer = 4;
int LedRojoIzq = 8;
int LedRojoDer = 7;
int LedTest = 13;

void setup ()
{
  pinMode(LedBlancoIzq, OUTPUT);
  pinMode(LedBlancoDer, OUTPUT);
  pinMode(LedRojoIzq, OUTPUT);
  pinMode(LedRojoDer, OUTPUT);

  pinMode(LedTest, OUTPUT);

  digitalWrite(LedBlancoIzq, LOW);
  digitalWrite(LedBlancoDer, LOW);
  digitalWrite(LedRojoIzq, LOW);
  digitalWrite(LedRojoDer, LOW);

  digitalWrite(LedTest, LOW);

  //saludo inicial

  digitalWrite(LedTest, HIGH);
  delay(500);
  digitalWrite(LedTest, LOW);
  delay(500);
  digitalWrite(LedTest, HIGH);
  delay(500);
  digitalWrite(LedTest, LOW);
  delay(500);
  digitalWrite(LedTest, HIGH);
  delay(500);
  digitalWrite(LedTest, LOW);
  delay(500);

}



void loop()
{

  digitalWrite(LedBlancoIzq, HIGH);
  digitalWrite(LedBlancoDer, HIGH);
  digitalWrite(LedRojoIzq, HIGH);
  digitalWrite(LedRojoDer, HIGH);

  delay(1000);

  parpadeo(LedBlancoIzq, 10, 250);
  parpadeo(LedBlancoDer, 5, 500);
  parpadeo(LedRojoDer, 5, 1000);
  parpadeo(LedRojoIzq, 10, 750);

  digitalWrite(LedBlancoIzq, LOW);
  digitalWrite(LedBlancoDer, LOW);
  digitalWrite(LedRojoIzq, LOW);
  digitalWrite(LedRojoDer, LOW);

  delay(2000);
}

void parpadeo(int ledParpadea, int veces, int tiempo)
{
  
  for(int j=0; j<=veces; j++)
 {
  
  digitalWrite(ledParpadea, LOW);
  delay(tiempo);
  digitalWrite(ledParpadea, HIGH);
  delay(tiempo);
  
 }
 
}
