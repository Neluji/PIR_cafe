#include <Arduino.h>
#include "Chauffage.h"

Chauffage::Chauffage(char t_pin, char t_pin_read) : Composant(t_pin, OUTPUT), m_is_on(false), m_pin_read(t_pin_read) {
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
    return (float)(analogRead(m_pin_read))/1024.0;
}

bool Chauffage::is_on() {
    return m_is_on;
}