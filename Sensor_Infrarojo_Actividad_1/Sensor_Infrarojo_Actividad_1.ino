//definiendo las constantes de salida

const int emIzquierda = 7;
const int emDerecha = 6;

const int ledTest = 12;

//definiendo las constantes de entrada

const int reIzquierda = A0;
const int reDerecha = A1;

//Datos de reflectividad guardados

int refDer = 0;
int refIzq = 0;

void setup()
{

Serial.begin(9600);
  
  //iniciar las salidas

  pinMode (emIzquierda, OUTPUT);
  pinMode (emDerecha, OUTPUT);
  pinMode (ledTest, OUTPUT);

  digitalWrite (emIzquierda, LOW);
  digitalWrite (emDerecha, LOW);
  digitalWrite (ledTest, LOW);

  //Saludo inicial 

  for (int l=0; l<3; l++)
  {
    digitalWrite (ledTest, HIGH);
    delay(500);
    digitalWrite (ledTest, LOW);
    delay(500);
  }
  


}


void loop()
{
  digitalWrite(emIzquierda, HIGH);
  refIzq = analogRead(reIzquierda);
  delay(100);
  digitalWrite(emIzquierda, LOW);

  digitalWrite(emDerecha, HIGH);
  refDer = analogRead(reDerecha);
  delay(100);
  digitalWrite(emDerecha, LOW);

  //Enviamos la información al puerto serie

 if(analogRead(refIzq)<=700)
 {
  Serial.println("Blanco");
 }
  else
  {
   Serial.println("Negro"); 
  }
  
 if(analogRead(refDer)<=700)
 {
  Serial.println("Blanco");
 }
  else
  {
   Serial.println("Negro"); 
  }
    delay(500);
}
