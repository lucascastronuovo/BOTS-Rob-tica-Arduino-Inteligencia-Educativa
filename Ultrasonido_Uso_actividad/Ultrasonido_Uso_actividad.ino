int ledrojo = 11;
int ledverde = 9;
int ledazul = 10;
int disparo = 2;
int eco = 4;

long tiempoPulso;
float distMedida;

void setup()
{
  Serial.begin(9600);
  
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledazul, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(eco, INPUT);
}

 void loop()
 {
  digitalWrite(disparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparo, LOW);

  tiempoPulso = pulseIn(eco, HIGH);
  Serial.println(tiempoPulso);

  if(tiempoPulso<5000)
  {
    analogWrite(ledrojo, 0);
    analogWrite(ledverde, 255);
    analogWrite(ledazul, 0);
    delay(1000);
    analogWrite(ledrojo, 0);
    analogWrite(ledverde, 0);
    analogWrite(ledazul, 0);
    delay(1000);
     
  }

  else
  {
    analogWrite(ledrojo, 255);
    analogWrite(ledverde, 0);
    analogWrite(ledazul, 0); 
  }
}
