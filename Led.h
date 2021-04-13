#include "Composant.h"

#ifndef LED_H
#define LED_H

class Led : public Composant
{
private:
    bool is_on;
public:
    Led(int t_pin);
    void turn_on();
    void turn_off();
    void toggle();
};

#endif