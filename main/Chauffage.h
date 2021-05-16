#ifndef CHAUFFAGE_H
#define CHAUFFAGE_H

#include "Composant.h"

class Chauffage : public Composant
{
private:
    bool m_is_on;
public:
    Chauffage(char t_pin);
    void start();
    void stop();
    float read();
    bool is_on();
};

#endif