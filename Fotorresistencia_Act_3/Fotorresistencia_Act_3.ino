//definir constantes de salida

const int led = 9;
const int ledTest = 13;

//definir las entradas

const int fotor = A0;

//definir los datos

int valor = 0;
int intensidad = 0;
long tVal;

void setup()
{
  Serial.begin(9600);
  
//nombrar las salidas
  pinMode(led, OUTPUT);
  pinMode(ledTest, OUTPUT);
  digitalWrite(led, LOW);
  digitalWrite(ledTest, LOW);

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
  valor = analogRead(fotor);
  delay(100);

  tVal = constrain(valor, 0, 1024);
  intensidad = map(tVal, 0, 1024, 0, 255);

  analogWrite(led, intensidad);
  
}
