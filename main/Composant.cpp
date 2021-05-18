#include <Arduino.h>
#include "Composant.h"

Composant::Composant(char t_pin, char t_mode) : m_pin(t_pin),m_mode(t_mode) {
    pinMode(t_pin, t_mode);
}

void Composant::set_pin(char t_pin) {
    m_pin = t_pin;
}

char Composant::get_pin() {
    return m_pin;
}

void Composant::set_mode(char t_mode) {
    m_mode = t_mode;
}