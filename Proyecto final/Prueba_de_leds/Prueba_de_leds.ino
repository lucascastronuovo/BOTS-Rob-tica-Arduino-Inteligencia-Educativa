//variables

int ledRojoIzq = 7;
int ledRojoDer = 4;

int ledBlanco = 8;

void setup()
{
  pinMode(ledRojoIzq, OUTPUT);
  pinMode(ledRojoDer, OUTPUT);
  pinMode(ledBlanco, OUTPUT);

  digitalWrite(ledRojoIzq, LOW);
  digitalWrite(ledRojoDer, LOW);
  digitalWrite(ledBlanco, LOW);
}

void loop()
{
  digitalWrite(ledBlanco, HIGH);
  delay(1000);
  digitalWrite(ledRojoDer, HIGH);
  delay(500);
  digitalWrite(ledRojoIzq, HIGH);
  delay(1000);
  digitalWrite(ledBlanco, LOW);
  digitalWrite(ledRojoDer, LOW);
  digitalWrite(ledRojoIzq, LOW);
  delay(1000);
}
