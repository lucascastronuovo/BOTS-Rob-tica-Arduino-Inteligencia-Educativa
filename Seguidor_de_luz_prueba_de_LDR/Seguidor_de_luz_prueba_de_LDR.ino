//definir las constantes de salida

int const ledTest = 13;

//definir los motores
const int AIA = 3;
const int AIB = 11;
const int BIA = 10;
const int BIB = 6;

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
 
 pinMode(fotoIzq, INPUT);
 pinMode(fotoDer, INPUT);

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

  delay(500);
}
