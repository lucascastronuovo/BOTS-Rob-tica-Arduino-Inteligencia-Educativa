//definir variables

int LEDROJO = 9;
int LEDVERDE = 10;
int LEDAZUL = 11;
int LEDTest = 13;

int rojo = 0;
int verde = 0;
int azul = 0;
int todos = 0;

void setup()
{
  //iniciando los pines de salida
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
  pinMode(LEDTest, OUTPUT);


  analogWrite(LEDROJO, 0);
  analogWrite(LEDVERDE, 0);
  analogWrite(LEDAZUL, 0);

  digitalWrite(LEDTest, LOW);

  //saludo inicial

  for(int i=0; i<=3; i++)
  {
    digitalWrite(LEDTest, LOW);
    delay(500);
    digitalWrite(LEDTest, LOW);
    delay(500);   
  }
  
}


void loop()
{
  analogWrite(LEDAZUL, 255);
  delay(100);
  for(int verdeyrojo=0; verdeyrojo<=255; verdeyrojo++)
  {
    analogWrite(LEDROJO, verdeyrojo);
    analogWrite(LEDVERDE, verdeyrojo);
    delay(100);
  }

}
