int disparo = 2;
int eco = 4;
int ledTest = 13;
int ledrojo = 11;
int ledverde = 9;
int ledazul = 10;
int intensidad = 0;

long tiempoPulso;
long tVal;


void setup()
{
  pinMode(ledTest, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(eco, INPUT);

  digitalWrite(disparo, LOW);
  analogWrite(ledrojo, 0);
  analogWrite(ledverde, 0);
  analogWrite(ledazul, 0);

  //saludo inicial

  for(int l=0; l<=3; l++)
  {
    digitalWrite(ledTest, HIGH);
    delay(500);
    digitalWrite(ledTest, LOW);
    delay(500);
  }
  
}

void loop()
{
  //iniciamos el disparo
  digitalWrite(disparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparo, LOW);

  tiempoPulso = pulseIn(eco, HIGH); 

  if(tiempoPulso<550)
   {
    analogWrite(ledrojo, 255);
    analogWrite(ledverde, 0);
    analogWrite(ledazul, 0);
   }

   else if(tiempoPulso>=550 && tiempoPulso<840)
    {
    analogWrite(ledrojo, 255);
    analogWrite(ledverde, 255);
    analogWrite(ledazul, 0);       
    }

   else if(tiempoPulso>=860 && tiempoPulso<1140)
    {
    analogWrite(ledrojo, 0);
    analogWrite(ledverde, 255);
    analogWrite(ledazul, 0);       
    }

    else
    {
      tVal = constrain(tiempoPulso, 1140, 5700); //convierte tVal en los valores que se encuentren entre 1140 a 5700. Si se sobrepasa a 5700 se tomará 5700.
      intensidad = map(tVal, 1140, 5700, 0, 255); //convierte a intensidad en valores de entre 0 a 255 (las distintas opciones de intensidad de los leds RGB) para que si se toma 1140 sea 0, si se toma 5700 sea 255 y si se toma un valor intermedio como 3000 se usara la mitad de 255 y esto se hará de manera proporcional.
    analogWrite(ledrojo, intensidad);
    analogWrite(ledverde, intensidad);
    analogWrite(ledazul, intensidad);      
    }
}
