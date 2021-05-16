#ifndef COMPOSANT_H
#define COMPOSANT_H

class Composant
{
protected:
    char m_pin;
    char m_mode;
public:
    Composant(char t_pin, char t_mode);
    void set_pin(char t_pin);
    char get_pin();
    void set_mode(char t_mode);
};

#endif