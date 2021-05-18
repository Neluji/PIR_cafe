#ifndef CHAUFFAGE_H
#define CHAUFFAGE_H

#include "Composant.h"

class Chauffage : public Composant
{
private:
    bool m_is_on;
    char m_pin_read;
public:
    Chauffage(char t_pin, char t_pin_read);
    void start();
    void stop();
    float read();
    bool is_on();
};

#endif