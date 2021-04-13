#ifndef POT_H
#define POT_H

#include "Composant.h"

class Potentiometre : public Composant {
    private :
        int m_valeur;
    public :
        Potentiometre(char t_pin);
        int recuperer_valeur();
};

#endif