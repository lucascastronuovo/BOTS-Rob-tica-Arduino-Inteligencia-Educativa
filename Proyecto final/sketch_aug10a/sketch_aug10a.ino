//definir las constantes de salida

const int ledTest = 13;

//definir los motores
int AIA = 3;
int AIB = 11;
int BIA = 10;
int BIB = 6;

void setup()
{
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
  for(int veces=0; veces<=5; veces++)
  {
    analogWrite(AIA, 255); //derecha
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 255);
    delay(250);
    analogWrite(AIA, 0); 
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);  
    delay(2000);
  }

    for(int vecesb=0; vecesb<=5; vecesb++)
  {
    analogWrite(AIA, 0); //izquierda
    analogWrite(AIB, 255);
    analogWrite(BIA, 255);
    analogWrite(BIB, 0);
    delay(250);
    analogWrite(AIA, 0); 
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);
    delay(2000);
  }
}
