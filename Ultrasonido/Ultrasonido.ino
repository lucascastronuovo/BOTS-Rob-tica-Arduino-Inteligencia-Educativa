//definir variables

int disparo = 2;
int eco = 4;

int ledTest = 13;

long tiempoPulso;
float distMedida;

void setup()
{
   Serial.begin(9600);
  
  pinMode(ledTest, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(eco, INPUT);

  //Saludo Inicial

  for(int l=0; l<=3; l++)
   {
    digitalWrite(ledTest, HIGH);
    delay(500);
    digitalWrite(ledTest, HIGH);
    delay(500);
   }
}



void loop()
{
  digitalWrite(disparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparo, LOW);

  tiempoPulso = pulseIn(eco, HIGH);
  distMedida = 0.0340 / 2 * tiempoPulso;

  Serial.println("Tiempo/Distancia");
  Serial.print(tiempoPulso);
  Serial.print("/");
  Serial.println(distMedida);

  delay(500);

  


  delay(500);
}
