/*
 *   Blink
 *   Turns on an LED on for one second, then off for one second, repeatedly.
 *
 *   This example code is in the public domain.
 *
 *   Modified to blink the second led on Olimexino-T32u4
 */

// Useful definitions for the two LEDs on the board
#define GLED 7      // The GREEN  LED is on Pin 7
#define YLED 9      // The YELLOW LED is on Pin 9

void setup() {
    // initialize the digital pin as an output.
    pinMode(GLED, OUTPUT);
    pinMode(YLED, OUTPUT);
}

void loop() {
    digitalWrite(GLED, HIGH);   // set the LED on
    delay(500);                 // wait for a second
    digitalWrite(GLED, LOW);    // set the LED off
    delay(500);                 // wait for a second

    digitalWrite(YLED, HIGH);
    delay(500);
    digitalWrite(YLED, LOW);
    delay(500);
}
