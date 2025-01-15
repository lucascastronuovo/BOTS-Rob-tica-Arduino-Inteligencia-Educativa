//definir las constantes de salida

const int ledTest = 13;

//definir los motores
int AIA = 3;
int AIB = 11;
int BIA = 10;
int BIB = 6;

//definir las constantes de entrada
const int fotoIzq = A1;
const int fotoDer = A0;

//datos
int valIzq = 0;
int valDer = 0;

void setup()
{
  Serial.begin(9600);
  
  //iniciamos las entradas y salidas
 pinMode(ledTest, OUTPUT);
 
 pinMode(AIA, OUTPUT);
 pinMode(AIB, OUTPUT);
 pinMode(BIA, OUTPUT);
 pinMode(BIB, OUTPUT);
 


  //apago las salidas

 digitalWrite(ledTest, LOW);
 
 analogWrite(AIA, 0); //Siempre usar analogWrite para apagar los motores en el void setup()
 analogWrite(AIB, 0);
 analogWrite(BIA, 0);
 analogWrite(BIB, 0);

 //saludo inicial
 for(int l=0; l<=2; l++)
 {
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
 }
}

void loop()
{
  
  valIzq = analogRead(fotoIzq);
  valDer = analogRead(fotoDer);

  Serial.print(valIzq);
  Serial.print(",");
  Serial.println(valDer);


 if(valIzq<70 && valDer<400)
  {
    adelante();
  }

  else if(valIzq>70 && valDer<400)
  {
    izquierda();
    delay(20);
  }
  
  else if(valIzq>70 && valDer>400)
  {
    derecha();
    delay(20);
  }


  
  
}


void adelante()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void derecha()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
}

void izquierda()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}
