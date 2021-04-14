#include "Led.h"
#include "Potentiometre.h"

Led led(D8);
Potentiometre pot(A0);

void setup() {
  pinMode(D5, INPUT);
}

void loop() {
  if (digitalRead(D5) == HIGH)
  {
    led.turn_on();
  }
  else led.turn_off();
}