/*
   Find the fucking builtin LEDpin test
*/

const int DELAY_MS = 200;       // ms for delay
const int PINS_TO_TEST_COUNT = 19;            // the number of LED pin to test
const int LAST_KEY = PINS_TO_TEST_COUNT - 1;  // Last key of the pins_to_test array

bool stop_loop;
int led_pin;

// array des pins a tester
int pins_to_test[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
};

void setup() {
  Serial.begin(9600);   // init du port serie
  delay(DELAY_MS * 10); // Si je met pas le delay le retour mange le debut

  // Disclamer
  Serial.print("Checking BUILTIN fucking ledpin, from pin ");
  Serial.print(pins_to_test[0]);
  Serial.print(", to pin ");
  Serial.println(pins_to_test[LAST_KEY]);
  Serial.print("> Activate pins… ");

  // Activation des pins a tester
  for (led_pin = 0; led_pin < PINS_TO_TEST_COUNT; led_pin++) {
    Serial.print(pins_to_test[led_pin]);
    pinMode(pins_to_test[led_pin], OUTPUT);
    Serial.print(", ");
  }
  Serial.println();
  delay(DELAY_MS * 10); // Si je met pas le delay le retour mange le debut
}

void loop() {
  
  if (!stop_loop) {

    // Test des pins l'un apres l'autre
    for (led_pin = 0; led_pin < PINS_TO_TEST_COUNT; led_pin++) {
      Serial.print("# Testing pin: ");    // print out the tested pin
      Serial.print(pins_to_test[led_pin]);
      Serial.print(" >OFF< ");
      digitalWrite(pins_to_test[led_pin], LOW);  // set the LED off
      delay(DELAY_MS * 10);
      Serial.println(" >ON< ");
      digitalWrite(pins_to_test[led_pin], HIGH); // set the LED on
      delay(DELAY_MS);
    }
    stop_loop = true;
  }
}

