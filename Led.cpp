#include "LED.h"

Led::Led(int t_pin) : Composant(t_pin), is_on(false) {
    turn_off();
};