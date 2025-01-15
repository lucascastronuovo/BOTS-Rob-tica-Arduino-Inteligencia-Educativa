/*
Código para encender las 4 luces led de nuestro robot.
*/

//Definimos variables

int ledBlancoDerecha = 2; 
int ledBlancoIzquierda = 4; 
int ledRojoDerecha = 7; 
int ledRojoIzquierda = 8; 

int ledTest = 13;

// Setup: Inicialización del pin de salida

void setup() {
  // Inicializamos los pines de salida
  pinMode(ledBlancoDerecha, OUTPUT); 
  pinMode(ledBlancoIzquierda, OUTPUT);
  pinMode(ledRojoDerecha, OUTPUT);
  pinMode(ledRojoIzquierda, OUTPUT);
  pinMode(ledTest, OUTPUT);

  //apagamos todos los leds
  
  digitalWrite(ledBlancoDerecha, LOW);
  digitalWrite(ledBlancoIzquierda, LOW);
  digitalWrite(ledRojoDerecha, LOW);
  digitalWrite(ledRojoIzquierda, LOW);
  digitalWrite(ledTest, LOW);

  //Saludo Inicial
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

void loop() {

  //encendemos luces delanteras y traseras
  digitalWrite(ledBlancoDerecha, HIGH);
  digitalWrite(ledBlancoIzquierda, HIGH);
  digitalWrite(ledRojoDerecha, HIGH);
  digitalWrite(ledRojoIzquierda, HIGH);

  //Esperamos un segundo
  delay(1000);

  //Hacemos parpadear el led blanco de la derecha 5 veces intervalo 1/2 segundo = 500 milisegundos
  parpadeo(ledBlancoDerecha, 5, 500);

  //Hacemos parpadear el led rojo de la derecha 10 veces intervalo 1/4 segundo = 250 milisegundos
  parpadeo(ledRojoDerecha, 10, 250);

  //Hacemos parpadear el led rojo de la izquierda 5 veces intervalo 1 segundo = 1000 milisegundos
  parpadeo(ledRojoIzquierda, 5, 1000);

  //Hacemos parpadear el led blanco de la izquierda 10 veces intervalo 3/4 segundo 750 milisegundos
  parpadeo(ledBlancoIzquierda, 10, 750);

  //ahora apagamos todas las luces y esperamos 2 segundos antes de que se repita el ciclo
  digitalWrite(ledBlancoDerecha, LOW);
  digitalWrite(ledBlancoIzquierda, LOW);
  digitalWrite(ledRojoDerecha, LOW);
  digitalWrite(ledRojoIzquierda, LOW);
  delay(2000);
  
}

               
               
//Ahora vamos a escribir la funcion "parpadeo". Para eso vamos a definir sus tres parámetros:
//1- ledParpadea
//2- veces
//3- tiempo

void parpadeo(int ledParpadea, int veces, int tiempo) {  //declaracion de funcion con sus parametros entre los parentesis 

/*La declaración la estructura for se usa para repetir un bloque de sentencias encerradas entre llaves un
número determinado de veces. Cada vez que se ejecutan las instrucciones del bucle se 
vuelve a testear la condición. La declaración for tiene tres partes separadas por (;)
vemos el ejemplo de su sintaxis: 
(inicialización; condición; expresión)*/

  for (int j=0; j <= veces ; j++) { 
    digitalWrite(ledParpadea, LOW);
    delay(tiempo);
    digitalWrite(ledParpadea, HIGH);
    delay(tiempo);
  }
  
}
