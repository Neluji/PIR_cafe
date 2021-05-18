#ifndef POMPE_H
#define POMPE_H

#include "Composant.h"

class Pompe : public Composant
{
private:
    bool m_is_on;
public:
    Pompe(char t_pin);
    void start();
    void stop();
    void toggle();
};

#endif