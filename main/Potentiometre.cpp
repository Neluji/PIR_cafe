#include <Arduino.h>
#include <iostream>
#include "Potentiometre.h"

using namespace std;

Potentiometre::Potentiometre(char t_pin) : Composant(t_pin,INPUT), m_valeur(0) {};

int Potentiometre::recuperer_valeur() {
    m_valeur = analogRead(m_pin);
    return m_valeur;
}

/*ostream& operator << (ostream& s, Potentiometre& pot) {
   return s << "Potentiometre : {\n   Pin : " << pot.get_pin() << "\n   Valeur : " << pot.recuperer_valeur() << "\n}";
}*/