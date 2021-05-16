#ifndef BOUTON_H
#define BOUTON_H

#include "Composant.h"

class Bouton : public Composant
{
public:
    Bouton(char t_pin);
    bool is_pushed();
    bool is_released();
private:
    bool m_is_pressed;
    bool m_is_pressed_prev;
};

#endif


