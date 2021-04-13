#include <Arduino.h>
#include "Led.h"

Led::Led(char t_pin) : Composant(t_pin,OUTPUT), m_is_on(false) {
    turn_off();
}

void Led::turn_on() {
    digitalWrite(m_pin, HIGH);
    m_is_on = true;
}

void Led::turn_off() {
    digitalWrite(m_pin, LOW);
    m_is_on = false;
}

void Led::toggle() {
    switch(m_is_on) {
        case true : turn_off();
        default : turn_on();
    }
}