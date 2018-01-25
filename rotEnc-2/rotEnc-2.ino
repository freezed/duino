/*
   Test Rotary Encoder
*/

// declaration constante
#define PINA D1
#define PINB D3

// declaration variable
int encoder_steps = 0; // compteur de pas
int previous_encoder_state[4];
int actual_encoder_state[] = {
  digitalRead(PINA),   // etat du pin A
  digitalRead(PINB),   // etat du pin B
  int(millis()),       // horodatage de la mesure
  encoder_steps        // numero du pas
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // initialisation du port serie

  // declaration du pinMode
  pinMode(PINA, INPUT_PULLUP);
  pinMode(PINB, INPUT_PULLUP);

  // declaration des interruptions
  attachInterrupt(digitalPinToInterrupt(PINA), encoderState, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PINB), encoderState, CHANGE);
}

void loop() {   // La boucle du script

}

void encoderState () {

  // On archive l'etat de l'encodeur 
  previous_encoder_state[0] = actual_encoder_state[0];
  previous_encoder_state[1] = actual_encoder_state[1];
  previous_encoder_state[2] = actual_encoder_state[2];
  previous_encoder_state[3] = actual_encoder_state[3];

  actual_encoder_state[0] = digitalRead(PINA);  // On le met a jour
  actual_encoder_state[1] = digitalRead(PINB);
  actual_encoder_state[2] = millis();
  actual_encoder_state[3] = encoder_steps + 1;

  if (previous_encoder_state[2] != actual_encoder_state[2]) {
    printEncoderState();
    encoder_steps++;
  }
  else { 
    Serial.print("Pas de changement");
    Serial.print(" time: ");
    Serial.print(actual_encoder_state[2]);
    Serial.print(" pas: ");
    Serial.println(actual_encoder_state[3]);
  }
}

bool isStateChanged() {

  if (
    actual_encoder_state[0] == previous_encoder_state[0] &&
    actual_encoder_state[1] == previous_encoder_state[1] &&
    actual_encoder_state[2] == previous_encoder_state[2] &&
    actual_encoder_state[3] == previous_encoder_state[3]
  ) {
    return false;
  }
  else {
    return true;
  }

}

void printEncoderState() {
  // Impression de l'etat de l'encodeur
  Serial.print("A: ");
  Serial.print(actual_encoder_state[0]);
  Serial.print(" B: ");
  Serial.print(actual_encoder_state[1]);
  Serial.print(" time: ");
  Serial.print(actual_encoder_state[2]);
  Serial.print(" pas: ");
  Serial.println(actual_encoder_state[3]);
}
