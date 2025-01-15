//definir constantes de salida

const int led = 12;
const int ledTest = 13;

//definir las entradas

const int fotor = A0;

//definir los datos

int valor = 0;

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

  if(valor>800)
  {
    //le agregue un parpadeo en vez de que este siempre el led encendido
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
  
  else
  {
   digitalWrite(led, LOW); 
  }
  
}
