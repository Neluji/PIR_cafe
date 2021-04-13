#include "Composant.h"

Composant::Composant(int t_pin) : m_pin(t_pin) {}

void Composant::set_pin(int t_pin) {
    m_pin = t_pin;
}