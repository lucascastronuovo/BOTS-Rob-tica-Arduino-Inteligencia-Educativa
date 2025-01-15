#include <IRremote.h>

//variables

int ledTest = 13;

//seto del receptor

int receptorControl = 8;
IRrecv receptor(receptorControl);
decode_results codigoLeido;

void setup()
{
  Serial.begin(9600);

  //habilitamos la lectura del sensor

  receptor.enableIRIn();

  pinMode(ledTest, OUTPUT);
  digitalWrite(ledTest, LOW);

  //saludo inicial

  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
}


void loop()
{
  if(receptor.decode(&codigoLeido))
  {
    Serial.print("0x");
    Serial.println(codigoLeido.value, HEX);
    delay(50);
    receptor.resume();
  }
}
