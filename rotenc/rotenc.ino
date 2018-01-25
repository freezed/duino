/*
 * Test rotary encoder
 */

// declaration constante
#define CLK D1
#define DT D3
#define SW D4
#define S1 "->"
#define S2 "<-"

// declaration variable
//int clk_old = clk;
//int dt_old = dt;
int incre = 0;
int jauge = 0;
int clics = 0;
int timestamp = 0;
//int timestamp_old = 0;
String sens = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // initialisation du port serie

  clk = digitalRead(CLK);
  dt = digitalRead(DT);
  sw = digitalRead(SW);

  // declaration du pinMode
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

// declaration d'un «interrupteur»
  attachInterrupt(digitalPinToInterrupt(CLK), etatSwitch, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT), etatSwitch, CHANGE);
}

void loop() {
// put your main code here, to run repeatedly:

  if ((
        clk_old != clk ||
        dt_old != dt
      ) &&
      timestamp != timestamp_old
     ) {
    Serial.print(timestamp);
    Serial.print("|CLK : ");
    Serial.print(clk);
    Serial.print("|DT: ");
    Serial.print(dt);
    Serial.print("|incre: ");
    Serial.print(incre);
    Serial.print("|jauge: ");
    Serial.print(jauge);
    Serial.print("|sens: ");
    Serial.println(sens);
//    Serial.print("|SW: "); 
//    Serial.println(sw);
    timestamp_old = timestamp;
  }
}

// declaration des fonctions
void etatSwitch () {
  incre++;
  clk = digitalRead(CLK);
  dt = digitalRead(DT);
  timestamp = millis();

  if (dt_old != dt) {
    sens = S1;
    jauge++;
  }
  
  if (clk_old != clk) {
    sens = S2;
    jauge--;
  }

}
