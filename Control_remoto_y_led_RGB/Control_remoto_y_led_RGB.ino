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


void loop()
{
  if(receptorIR.decode(&codigoLeidoNuevo))
  {
    receptorIR.resume();
  }
  
  if(codigoLeidoNuevo.value != codigoLeido.value && codigoLeidoNuevo != 0xFFFFFFFF) 
  {
    digitalWrite(ledTest, HIGH);
    delay(50);
    digitalWrite(ledTest, LOW);

    Serial.println(codigoLeido.value, HEX);
    codigoLeido = codigoLeidoNuevo;

    switch (codigoLeido.value)
    {
      case 0xFFA25D:
      analogWrite(ledRojo, 0);
      break;

      case 0xFF629D:
      analogWrite(ledRojo, 127);
      break;

      case 0xFFE21D:
      analogWrite(ledRojo, 255);
      break;

      case 0xFF22DD:
      digitalWrite(ledVerde, 0);
      break;

      case 0xFF02FD:
      digitalWrite(ledVerde, 127);
      break;

      case 0xFFC23D:
      digitalWrite(ledVerde, 255);
      break;

      case 0xFFE01F:
      analogWrite(ledAzul, 0);
      break;

      case 0xFFA857:
      analogWrite(ledAzul, 127);
      break;
      
      case 0xFF906F:
      analogWrite(ledAzul, 255);
      break;

      case 0xFF6897:
      analogWrite(ledRojo, 255);
      analogWrite(ledVerde, 255);
      analogWrite(ledAzul, 255);
      break;

      case 0xFFB04F:
      analogWrite(ledRojo, 0);
      analogWrite(ledVerde, 0);
      analogWrite(ledAzul, 0);
      break;    

      case 0xFF38C7: 
      for(int luces=0; luces<=255; luces++)
      {
      analogWrite(ledRojo, luces);
      analogWrite(ledVerde, luces);
      analogWrite(ledAzul, luces);
      delay(100);
      }
      
      delay(100);
      
      for(int luces=255; luces>=0; luces--)
      {
      analogWrite(ledRojo, luces);
      analogWrite(ledVerde, luces);
      analogWrite(ledAzul, luces);
      delay(100);
      }

      break;

      default:
      digitalWrite(ledTest, HIGH);
      delay(200);
      digitalWrite(ledTest, LOW);
      delay(200);
      digitalWrite(ledTest, HIGH);
      delay(200);
      digitalWrite(ledTest, LOW);
      delay(200);

      break;
    }
  }
}
