/*
   Affichage d'une boucle de comptage sur le TFT

   BUG: Affiche seulement 20 lignes
        Ligne 21 a 32 ne s'affiche pas
        Affiche en haut a partir de la ligne 33
*/

#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>

#define TFT_GREY 0x5AEB // New colour

TFT_eSPI tft = TFT_eSPI();  // Invoke library

const int DELAY_MS = 300;   // ms for delay
const int COUNT_TO = 42;

bool stop_loop;
int led_pin;

void setup() {
  tft.init();
  tft.setRotation(2);

  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined
  tft.fillScreen(TFT_BLACK);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'tft.println'
  //  or stay on the line is there is room for the text with tft.print)
  tft.setCursor(0, 0, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_WHITE,TFT_GREY);
  tft.setTextSize(1);

  // We can now plot text on screen using the "print" class
}

void loop() {
  if (!stop_loop) {
    // Disclamer  
    tft.print("Counting to ");
    tft.print(COUNT_TO);

    tft.print(", start: ");
    // Test des pins l'un apres l'autre
    for (int i = 1; i < COUNT_TO; i++) {
      tft.print(" ");
      tft.println(i);
      delay(DELAY_MS);
    }
    tft.println("End!");
    stop_loop = true;
  }
}
