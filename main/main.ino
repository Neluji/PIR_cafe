#include "Cafetiere.h"

Cafetiere cafetiere;

void setup() {
  Serial.begin(9600);
}

void loop() {
  cafetiere.fonctionne();
}