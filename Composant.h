#ifndef COMPOSANT_H
#define COMPOSANT_H

class Composant
{
private:
    int m_pin;
public:
    Composant(int t_pin);
    void set_pin(int t_pin);
};

#endif