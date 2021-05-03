#include "Composant.h"
#include "Led.h"
#include "Bouton.h"
#include "Potentiometre.h"
#include "Sensor.h"

#ifndef CAFETIERE_H
#define CAFETIERE_H

class Cafetiere
{
private:
    Led led_alim;
    Bouton bouton_filtre;
    Bouton bouton_expresso;
    Sensor capteur_eau;
    Potentiometre pot_eau;
    Chauffage chauffage(D2);
    Pompe pompe(D1);
    int type_cafe;

public:
    Cafetiere();
    void selection_cafe();
    void check_eau();
    void cycle_chauffe();
    void cycle_pompe();

    void fonctionne();

};

#endif
