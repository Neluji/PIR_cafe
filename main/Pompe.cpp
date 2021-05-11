#include <Arduino.h>
#include "Pompe.h"

Pompe::Pompe(char t_pin) : Composant(t_pin, OUTPUT), m_is_on(false) {
    turn_off();
}

void Pompe::start() {
    digitalWrite(m_pin, HIGH);
    m_is_on = true;
}

void Pompe::stop() {
    digitalWrite(m_pin, LOW);
    m_is_on = false;
}

void Pompe::toggle() {
    switch (m_is_on) {
    case true: stop();
    default: start();
    }
}
