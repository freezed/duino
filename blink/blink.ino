/*
 *   Blink
 *   Turns on an LED on for, then off, repeatedly.
 *
 *   Modified to blink the second led on Olimexino-T32u4
 */

// Useful definitions for the two LEDs on the board
#define YLED 17      // The YELLOW LED is on Pin 17
#define TIME_DELAY 500

void setup() {
    // initialize the digital pin as an output.
    pinMode(YLED, OUTPUT);
}

void loop() {
    digitalWrite(YLED, HIGH);
    delay(TIME_DELAY);
    digitalWrite(YLED, LOW);
    delay(TIME_DELAY);
}
