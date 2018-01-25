/*
 * Test switch
 * 
 * Carte NodeMCU
 * 
 * Connecter un switch sans resistance (mode builtin pull-up)
 * aux pin D1 (GPIO5) & pin D2 (GPIO4)
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
//  attachInterrupt(digitalPinToInterrupt(PINA), unclick_, LOW);
}

void loop() {
// put your main code here, to run repeatedly:
//  Serial.print("Etat pin A: ");
//  Serial.println(digitalRead(PINA));

}

// declaration des fonctions
void etatSwitch () {
  if (digitalRead(PINA) == 0) {
    Serial.print(count);
    Serial.println("CLICK !");
  }
  else {
    Serial.print(count);
    Serial.println("UN-CLICK !");
  }

  count++;

}
