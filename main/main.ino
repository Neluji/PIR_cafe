#include "Led.h"

Led led(D8);
int ratio = 0;

void setup() {
  pinMode(A0,INPUT);
}

void loop() {
  ratio = analogRead(A0);
  led.turn_off();
  delay(ratio);
  led.turn_on();
  delay(ratio);
}