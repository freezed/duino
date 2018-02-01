/*
   Affichage d'une boucle de comptage sur le TFT
*/

const int DELAY_MS = 2000;   // ms for delay
const int COUNT_TO = 42;

bool stop_loop;
int led_pin;

void setup() {
  Serial.begin(9600);   // init du port serie
  delay(DELAY_MS); // Si je met pas le delay le retour mange le debut

  // Disclamer
  Serial.print("Counting to ");
  Serial.println(COUNT_TO);

}

void loop() {
  if (!stop_loop) {
    Serial.println("Début du compteur:");
    // Test des pins l'un apres l'autre
    for (int i = 0; i < COUNT_TO; i++) {
      Serial.print(" - ");    // print out the tested pin
      Serial.println(i);
    }
    Serial.println("Fin du compteur!");
    stop_loop = true;
  }
}
