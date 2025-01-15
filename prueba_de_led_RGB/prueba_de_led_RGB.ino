#include <IRremote.h>

//definir las variables

int ledTest = 13;

//seteo del receptor

int receptorControl = 2;
IRrecv receptorIR(receptorControl);
decode_results codigoLeido;
decode_results codigoLeidoNuevo;

//seteo del led RGB

int ledRojo = 9;
int ledVerde = 12;
int ledAzul = 5;

int potenciaRojo = 0;
int potenciaVerde = 0;
int potenciaAzul = 0;


void setup()
{
  Serial.begin(9600);

  receptorIR.enableIRIn();

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  analogWrite(ledRojo, 0);
  analogWrite(ledVerde, 0);
  analogWrite(ledAzul, 0);

  pinMode(ledTest, OUTPUT);
  digitalWrite(ledTest, LOW);

  //saludo inicial

  for(int l=0; l<= 2; l++)
  {
    digitalWrite(ledTest, HIGH);
    delay(500);
    digitalWrite(ledTest, LOW);
    delay(500);
  }
}


void loop(){
  analogWrite(ledRojo, 255);
  delay(500);
  analogWrite(ledRojo, 0);
  analogWrite(ledVerde, 255);
  delay(500);
  analogWrite(ledVerde, 0);
  analogWrite(ledAzul, 255);
  delay(500);
  analogWrite(ledAzul, 0);
  delay(500);
  
}
