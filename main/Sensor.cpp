#include <Arduino.h>
#include "Sensor.h"

Sensor::Sensor(char t_pin) : Composant(t_pin,INPUT) {}

int Sensor::read() {
    return digitalRead(m_pin);
}
