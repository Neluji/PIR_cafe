#include "Led.h"
#include "Potentiometre.h"

Led led(D8);
Potentiometre pot(A0);

void setup() {
}

void loop() {
  led.turn_off();
  delay(pot.recuperer_valeur()+10);
  led.turn_on();
  delay(pot.recuperer_valeur()+10);
}