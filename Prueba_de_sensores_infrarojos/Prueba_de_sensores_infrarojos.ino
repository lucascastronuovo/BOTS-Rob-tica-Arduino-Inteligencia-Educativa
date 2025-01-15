//definir variables de salida
 
const int emIzq = 8;
const int emDer = 9;

const int ledTest = 13;

//variables de los motores
const int AIA = 3;
const int AIB = 11;
const int BIA = 10;
const int BIB = 6;

// variables de entrada

const int reIzq = A0;
const int reDer = A1;

//datos guardados

int valIzq = 0;
int valDer = 0;

void setup()
{
  //iniciamos las salidas
  Serial.begin(9600);

 pinMode(emIzq, OUTPUT);
 pinMode(emDer, OUTPUT);
 pinMode(ledTest, OUTPUT);
 pinMode(AIA, OUTPUT);
 pinMode(AIB, OUTPUT);
 pinMode(BIA, OUTPUT);
 pinMode(BIB, OUTPUT);

 digitalWrite(ledTest, LOW);
 digitalWrite(emIzq, LOW);
 digitalWrite(emDer, LOW);
}

void loop()
{
  digitalWrite(emIzq, HIGH);
  valIzq = analogRead(reIzq);
  delay(100);
  digitalWrite(emIzq, LOW);

  digitalWrite(emDer, HIGH);
  valDer = analogRead(reDer);
  delay(100);
  digitalWrite(emDer, LOW);

  Serial.println("ValIzq/ValDer");
  Serial.print(valIzq);
  Serial.print("/");
  Serial.print(valDer);

  delay(500);
}
