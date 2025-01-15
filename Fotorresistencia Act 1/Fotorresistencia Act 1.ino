//definir las constantes de salida

const int ledTest = 13;

//const de entrada

const int fotoIzq = A1;
const int fotoDer = A0;


//datos de resistividad

int valDer = 0;
int valIzq = 0;

void setup()
{
  Serial.begin(9600);

  //iniciar las entradas y salidas
  
  pinMode(ledTest, OUTPUT);

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
  //leyendo la tension izquierda y derecha
  valIzq = analogRead(fotoIzq);
  delay(100);
  
  valDer = analogRead(fotoDer);
  delay(100);

 if(valIzq<120)
  {
    Serial.println("Mañana");
  }

  else if(valDer<300)
  {
    Serial.println("Tarde");
  }
  else if(valIzq>600 && valDer>900)
  {
    Serial.println("Noche");
  }
  else
  {
    Serial.println("Mediodia");
  }

  delay(500);
}
