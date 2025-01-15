#include <IRremote.h>

//variables

int ledTest = 13;

//seteo del receptor

int receptorControl = 2;
IRrecv receptorIR(receptorControl);
decode_results codigoLeido;
decode_results codigoLeidoNuevo;

//seteo de los leds

int ledBlanco = 8;

int ledRojoIzq = 7;
int ledRojoDer = 4;

//seteo de los motores

int AIA = 3;
int AIB = 11;
int BIA = 10;
int BIB = 6;

void setup()
{
  Serial.begin(9600);
  
//iniciamos las salidas y las entradas

  receptorIR.enableIRIn();

  pinMode(ledTest, OUTPUT);

  pinMode (ledBlanco, OUTPUT);
  pinMode (ledRojoIzq, OUTPUT);
  pinMode (ledRojoDer, OUTPUT);

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

//apago las salidas

  digitalWrite(ledTest, LOW);

  digitalWrite(ledBlanco, LOW);
  digitalWrite(ledRojoIzq, LOW);
  digitalWrite(ledRojoDer, LOW);

  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  
}




void loop()
{
  if(receptorIR.decode(&codigoLeidoNuevo))
  {
    receptorIR.resume();
  }

  if(codigoLeidoNuevo.value != codigoLeido.value && codigoLeidoNuevo.value != 0xFFFFFFFF) 
  {
    digitalWrite(ledTest, HIGH);
    delay(50);
    digitalWrite(ledTest, LOW);

    Serial.println(codigoLeidoNuevo.value, HEX);
    codigoLeido = codigoLeidoNuevo;

    switch(codigoLeido.value)
      {
        case 0xFF18E7:
        adelante();
        break;
       
        
        case 0xFF4AB5:
        atras();
        digitalWrite(ledRojoIzq, HIGH);
        digitalWrite(ledRojoDer,HIGH);
        delay(500);
        digitalWrite(ledRojoIzq, LOW);
        digitalWrite(ledRojoDer, LOW);
        break;

        case 0xFF5AA5:
        derecha();
        digitalWrite(ledRojoDer, HIGH);
        delay(250);
        digitalWrite(ledRojoDer, LOW);
        break;


        case 0xFF10EF:
        izquierda();
        digitalWrite(ledRojoIzq, HIGH);
        delay(250);
        digitalWrite(ledRojoIzq, LOW);      
        break;


        case 0xFF38C7:
        parar();
        digitalWrite(ledRojoIzq, HIGH);
        digitalWrite(ledRojoDer, HIGH);
        delay(500);
        digitalWrite(ledRojoIzq, LOW);
        digitalWrite(ledRojoDer, LOW);
        break;

        case 0xFF6897:
        digitalWrite(ledBlanco, HIGH);
        break;

        case 0xFFB04F:
        digitalWrite(ledBlanco, LOW);
        break;

        case 0xFFA25D:
        izquierda1();
        digitalWrite(ledRojoIzq, HIGH);
        delay(250);
        digitalWrite(ledRojoIzq, LOW);
        break;

        case 0xFFE21D:
        derecha1();
        digitalWrite(ledRojoDer, HIGH);
        delay(250);
        digitalWrite(ledRojoDer, LOW);
        break;

        case 0xFF22DD:
        izquierda2();
        digitalWrite(ledRojoIzq, HIGH);
        delay(250);
        digitalWrite(ledRojoIzq, LOW);
        break;

        case 0xFFC23D:
        derecha2();
        digitalWrite(ledRojoDer, HIGH);
        delay(250);
        digitalWrite(ledRojoDer, LOW);
        break;

        case 0xFFE01F:
        atrasgiroizq();
        digitalWrite(ledRojoIzq, HIGH);
        delay(250);
        digitalWrite(ledRojoIzq, LOW);
        break;

        case 0xFF906F:
        atrasgiroder();
        digitalWrite(ledRojoDer, HIGH);
        delay(250);
        digitalWrite(ledRojoDer, LOW);
        break;

        case 0xFF629D:
        presentacion();
        digitalWrite(ledBlanco, HIGH);
        delay(250);
        digitalWrite(ledBlanco, LOW);
        delay(250);
        digitalWrite(ledBlanco, HIGH);
        delay(250);
        digitalWrite(ledBlanco, LOW);
        delay(250);
        digitalWrite(ledBlanco, HIGH);
        delay(250);
        digitalWrite(ledBlanco, LOW);
        delay(250);
        digitalWrite(ledBlanco, HIGH);
        delay(250);
        digitalWrite(ledBlanco, LOW);
        delay(250);
        break;

        case 0xFF02FD:
        presentacionluces();
        break;


        case 0xFFA857 :
        todaslasluces();
        break;

        case 0xFF9867:
        infinito();
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


void adelante()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void atras()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);  
}

void parar()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}

void derecha()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
  delay(250);
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);    
}

void derecha1()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255); 
}

void derecha2()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255); 
}


void izquierda()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
  delay(250);
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);   
}

void izquierda1()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void izquierda2()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void atrasgiroizq()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

void atrasgiroder()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255); 
}

void presentacion()
{ 
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
  delay(2000);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
  delay(2000);
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
  delay(2000);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
  delay(2000);
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255); 
  delay(2000);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
  delay(2000);
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
  delay(2000);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);  
}

void todaslasluces()
{
  digitalWrite(ledBlanco, HIGH);
  digitalWrite(ledRojoDer, HIGH);
  digitalWrite(ledRojoIzq, HIGH);
  delay(1500);
  digitalWrite(ledBlanco, LOW);
  digitalWrite(ledRojoDer, LOW);
  digitalWrite(ledRojoIzq, LOW);
}

void infinito()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);  
  delay(2500);
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
  delay(2500);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);   
}

void presentacionluces()
{
        digitalWrite(ledRojoDer, HIGH);
        delay(500);
        digitalWrite(ledRojoIzq, HIGH);
        delay(500);
        digitalWrite(ledBlanco, HIGH);
        delay(500);
        digitalWrite(ledRojoDer, LOW);
        digitalWrite(ledRojoIzq, LOW);
        digitalWrite(ledBlanco, LOW);
        delay(600);
        digitalWrite(ledRojoDer, HIGH);
        delay(300);
        digitalWrite(ledRojoIzq, HIGH);
        delay(300);
        digitalWrite(ledBlanco, HIGH);
        delay(300);
        digitalWrite(ledRojoDer, LOW);
        digitalWrite(ledRojoIzq, LOW);
        digitalWrite(ledBlanco, LOW);
        delay(600);
        digitalWrite(ledRojoDer, HIGH);
        delay(300);
        digitalWrite(ledRojoIzq, HIGH);
        delay(300);
        digitalWrite(ledBlanco, HIGH);
        delay(300);
        digitalWrite(ledRojoDer, LOW);
        digitalWrite(ledRojoIzq, LOW);
        digitalWrite(ledBlanco, LOW);
        delay(600);
        digitalWrite(ledRojoDer, HIGH);
        digitalWrite(ledRojoIzq, HIGH);
        digitalWrite(ledBlanco, HIGH);
        delay(150);
        digitalWrite(ledRojoDer, LOW);
        digitalWrite(ledRojoIzq, LOW);
        digitalWrite(ledBlanco, LOW);
        delay(150);
        digitalWrite(ledRojoDer, HIGH);
        digitalWrite(ledRojoIzq, HIGH);
        digitalWrite(ledBlanco, HIGH);
        delay(150);
        digitalWrite(ledRojoDer, LOW);
        digitalWrite(ledRojoIzq, LOW);
        digitalWrite(ledBlanco, LOW);
}
