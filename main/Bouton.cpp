#include <Arduino.h>
#include "Bouton.h"

Bouton::Bouton(char t_pin) : Composant(t_pin,INPUT) {}

bool Bouton::is_pushed() {
    return digitalRead(m_pin);
}
