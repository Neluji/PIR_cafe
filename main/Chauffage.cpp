#include <Arduino.h>
#include "Chauffage.h"

Chauffage::Chauffage(char t_pin) : Composant(t_pin, OUTPUT), m_is_on(false) {
    turn_off();
}

void Chauffage::start() {
    digitalWrite(m_pin, HIGH);
    m_is_on = true;
}

void Chauffage::stop() {
    digitalWrite(m_pin, LOW);
    m_is_on = false;
}

void Chauffage::toggle() {
    switch (m_is_on) {
    case true: stop();
    default: start();
    }
}

float Chauffage::read() {
    return analogRead(m_pin)/1024;
}

bool Chauffage::is_on() {
    return m_is_on;
}