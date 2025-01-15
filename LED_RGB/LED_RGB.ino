//definir variables

int LEDROJO = 9;
int LEDVERDE = 10;
int LEDAZUL = 11;
int LEDTest = 13;

int rojo = 0;
int verde = 0;
int azul = 0;
int todos = 0;

void setup()
{
  //iniciando los pines de salida
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
  pinMode(LEDTest, OUTPUT);


  analogWrite(LEDROJO, 0);
  analogWrite(LEDVERDE, 0);
  analogWrite(LEDAZUL, 0);

  digitalWrite(LEDTest, LOW);

  //saludo inicial

  for(int i=0; i<=3; i++)
  {
    digitalWrite(LEDTest, LOW);
    delay(500);
    digitalWrite(LEDTest, LOW);
    delay(500);   
  }
  
}


void loop()
{ 
  /*
   se encienden todos los colores
   ROJO
   ROJO + VERDE
   ROJO + VERDE + AZUL
   ROJO - VERDE + AZUL
   -ROJO + AZUL
   -AZUL
   Todos se enciendan y se apaguen
  */

 for(rojo=0; rojo<=255; rojo++)
  {
    analogWrite(LEDROJO, rojo);
    delay(10);  
  }

  for(rojo=255; rojo>=0; rojo--)
  {
    analogWrite(LEDROJO, rojo);
    delay(10);  
  }



   for(verde=0; verde<=255; verde++)
  {
    analogWrite(LEDVERDE, verde);
    delay(10);  
  }

  for(verde=255; verde>=0; verde--)
  {
    analogWrite(LEDVERDE, verde);
    delay(10);  
  }



 for(azul=0; azul<=255; azul++)
  {
    analogWrite(LEDAZUL, azul);
    delay(10);  
  }

  for(azul=255; azul>=0; azul--)
  {
    analogWrite(LEDAZUL, azul);
    delay(10);  
  }




  analogWrite(LEDROJO, 255);
  analogWrite(LEDVERDE, 0);
  analogWrite(LEDAZUL, 0);

  for(verde=0; verde<=255; verde++)
  {
    analogWrite(LEDVERDE, verde);
    delay(10);  
  }


  
   for(azul=0; azul<=255; azul++)
  {
    analogWrite(LEDAZUL, azul);
    delay(10);  
  }

    for(verde=255; verde>=0; verde--)
  {
    analogWrite(LEDVERDE, verde);
    delay(10);  
  }


  for(rojo=255; rojo>=0; rojo--)
  {
    analogWrite(LEDROJO, rojo);
    delay(10);  
  }


  for(azul=255; azul>=0; azul--)
  {
    analogWrite(LEDAZUL, azul);
    delay(10);  
  }


 delay(50);

 for(todos=0; todos<=255; todos++)
  {
    analogWrite(LEDROJO, todos);
    analogWrite(LEDVERDE, todos);
    analogWrite(LEDAZUL, todos);
    delay(10);
  }


 for(todos=255; todos>=0; todos--)
  {
    analogWrite(LEDROJO, todos);
    analogWrite(LEDVERDE, todos);
    analogWrite(LEDAZUL, todos);
    delay(10);
  }

}
