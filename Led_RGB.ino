/*
  Vamos a configurar las diferentes salidas de nuestro arduino lograr diferentes colores utilizando la tecnica de adiciÃƒÆ’Ã‚Â³n
*/

//INICIO VARIABLES

int ledRojo = 11;
int ledVerde = 10;
int ledAzul = 9;

int ledTest = 13;

int rojo = 0;
int verde = 0;
int azul = 0;
int todos = 0;
/*FIN VARIABLES*/

void setup() {
  //INICIO SETUP SALIDAS

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledTest, OUTPUT);

  analogWrite(ledRojo, 0);
  analogWrite(ledVerde, 0);
  analogWrite(ledAzul, 0);

  digitalWrite(ledTest, LOW);

  //Saludo Inicial con bucle for
  for(int i=0;i<3;i++){
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  }

}


void loop() {
  //INICIO ENCENDER COLORES
    
  for (rojo = 0; rojo <= 255; rojo++) {
    analogWrite(ledRojo, rojo);           //Escribe un valor entre 0 y 255  en un pin analÃƒÆ’Ã‚Â³gico (~). Se puede usar para encender 
    delay(10);                             //  un LED con luminosidad variable o accionar un motor a diferentes velocidades      
  }
  for (rojo = 255; rojo >= 0; rojo--) {    // en este caso, usando "rojo--" en vez de incrementar, decrementa el valor de la variable 
    analogWrite(ledRojo, rojo);             // de control "rojo" en 1 
    delay(10);
  }

  for (verde = 0; verde <= 255; verde++) {
    analogWrite(ledVerde, verde);
    delay(10);
  }
  for (verde = 255; verde >= 0; verde--) {
    analogWrite(ledVerde, verde);
    delay(10);
  }

  for (azul = 0; azul <= 255; azul++) {
    analogWrite(ledAzul, azul);
    delay(10);
  }
  for (azul = 255; azul >= 0; azul--) {
    analogWrite(ledAzul, azul);
    delay(10);
  }

  
  analogWrite(ledRojo, 255); //
  analogWrite(ledVerde, 0);
  analogWrite(ledAzul, 0);
  for (verde = 0; verde <= 255; verde++) {
    analogWrite(ledVerde, verde);
    delay(10);
  }
  for (azul = 0; azul <= 255; azul++) {
    analogWrite(ledAzul, azul);
    delay(10);
  }
  for (verde = 255; verde >= 0; verde--) {
    analogWrite(ledVerde, verde);
    delay(10);
  }
    for (rojo = 255; rojo >= 0; rojo--) {
    analogWrite(ledRojo, rojo);
    delay(10);
  }
  for (azul = 255; azul >= 0; azul--) {
    analogWrite(ledAzul, azul);
    delay(10);
  }

  delay(50);

  
  for (todos = 0; todos <= 255; todos++) {        
    analogWrite(ledRojo, todos);
    analogWrite(ledVerde, todos);
    analogWrite(ledAzul, todos);
    delay(10);
  }
  for (todos = 255; todos >= 0; todos--) {
    analogWrite(ledRojo, todos);
    analogWrite(ledVerde, todos);
    analogWrite(ledAzul, todos);
    delay(10);
  }

}

