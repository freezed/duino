/*
 * 
 * 
 * 
 * 
 */
#define PINA D1 
#define PINB D2 

int etatPinA = 0;
int etatPinB = 0;
int clic = 0;

int temps = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //initialisation port serie

  pinMode(PINA, INPUT_PULLUP);
  pinMode(PINB, INPUT_PULLUP);

//  delay(500);
//  Serial.println("");
//  digitalWrite(D1, LOW);
//  digitalWrite(D2, LOW);
//  Serial.println("Initialisation ok");
}

void loop() {
  // put your main code here, to run repeatedly:
//  d_1 = digitalRead(D1);
//  d_2 = digitalRead(D2);
//  Serial.print("état D1 : ");
//  Serial.print(d_1);
//  Serial.print(" / D2 : ");
//  Serial.println(d_2);
  if (millis() > temps + 50){
//    clic = 1-digitalRead(PINA);
    if (clic == 0){
      attachInterrupt(digitalPinToInterrupt(PINA), Click_, FALLING);
    }
    else
      attachInterrupt(digitalPinToInterrupt(PINA), Unclick_, RISING);
  }
}

void Click_ () {
  detachInterrupt(digitalPinToInterrupt(PINA));
  temps  = millis();
  Serial.println("Click");
  clic = 1;
}

void Unclick_ () {
  detachInterrupt(digitalPinToInterrupt(PINA));
  temps  = millis();
  Serial.println("Unclick");
  clic = 0;
}
