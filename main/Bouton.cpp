#include <Arduino.h>
#include "Bouton.h"

Bouton::Bouton(char t_pin) : Composant(t_pin,OUTPUT) {}

bool Bouton::is_pushed() {
    return digitalRead(t_pin);
}
