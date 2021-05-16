#include <Arduino.h>
#include "Chauffage.h"

Chauffage::Chauffage(char t_pin) : Composant(t_pin, OUTPUT), m_is_on(false) {
    stop();
}

void Chauffage::start() {
    digitalWrite(m_pin, HIGH);
    m_is_on = true;
}

void Chauffage::stop() {
    digitalWrite(m_pin, LOW);
    m_is_on = false;
}

float Chauffage::read() {
    return analogRead(m_pin)/1024;
}

bool Chauffage::is_on() {
    return m_is_on;
}