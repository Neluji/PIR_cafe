#include <Arduino.h>
#include "Bouton.h"

Bouton::Bouton(char t_pin) : Composant(t_pin,INPUT),m_is_pressed(false),m_is_pressed_prev(false) {}

bool Bouton::is_pushed() {
    m_is_pressed = digitalRead(m_pin);
    bool tmp = (!m_is_pressed_prev && m_is_pressed);
    m_is_pressed_prev = m_is_pressed;
    return tmp;
}

bool Bouton::is_released() {
    m_is_pressed = digitalRead(m_pin);
    bool tmp = (m_is_pressed_prev && !m_is_pressed);
    m_is_pressed_prev = m_is_pressed;
    return tmp;
}
