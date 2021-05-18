#ifndef LED_H
#define LED_H

#include "Composant.h"

class Led : public Composant
{
private:
    bool m_is_on;
public:
    Led(char t_pin);
    void turn_on();
    void turn_off();
    void toggle();
};

#endif