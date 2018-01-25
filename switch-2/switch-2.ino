/*
 * Test switch
 *
 * Carte 
 *
 * Connecter un switch sans resistance (mode builtin pull-up)
 * aux pin 
 *
 */
// declaration constante
#define PINA D1

// declaration variable
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // initialisation du port serie

  // declaration du pinMode
  pinMode(PINA, INPUT_PULLUP);

  // declaration d'un «interrupteur»
  attachInterrupt(digitalPinToInterrupt(PINA), etatSwitch, CHANGE);
}

void loop() {
// put your main code here, to run repeatedly:
//  Serial.print("Etat pin A: ");
//  Serial.println(digitalRead(PINA));

}

// declaration des fonctions
void etatSwitch () {
  Serial.print(count);
  Serial.print(" : ");
  Serial.print(millis());

  if (digitalRead(PINA) == 0) {
    Serial.println(" : CLICK !");
  }
  else {
    Serial.println(" : UN-CLICK !");
  }

  count++;

}
