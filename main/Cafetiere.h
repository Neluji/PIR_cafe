#include "Composant.h"
#include "Led.h"
#include "Bouton.h"
#include "Chauffage.h"
#include "Pompe.h"
#include "Afficheur.h"

#ifndef CAFETIERE_H
#define CAFETIERE_H

class Cafetiere
{
private:
    Led led_alim;
    Bouton bouton_switch;
    Bouton bouton_select;
    Chauffage chauffage;
    Pompe pompe;
    Afficheur afficheur;
    // 1 : filtre, 2 : expresso
    int type_cafe;
    // paliers de temperature
    float static palier_temp_inf = 10 / (15 + 10);
    float static palier_temp_sup = 10 / (10 + 10);
    // temps de preparation (en ms)
    unsigned long tps_cafe;
    unsigned long static tps_cafe_filtre = 10000; /* WIP valeur arbitraire */
    unsigned long static tps_cafe_expresso = 20000; /* WIP valeur arbitraire */
    // temps de chauffe (en ms)
    unsigned long tps_chauffe;
    unsigned long static tps_chauffe_filtre = 10000; /* WIP valeur arbitraire */
    unsigned long static tps_chauffe_expresso = 20000; /* WIP valeur arbitraire */
    // temps de pompage (en ms)
    unsigned long tps_pompe;
    unsigned long static tps_pompe_filtre = 5000; /* WIP valeur arbitraire */
    unsigned long static tps_pompe_expresso = 10000; /* WIP valeur arbitraire */
    // temps d'utilisation (en ms)
    unsigned long start_time;
    unsigned long elapsed_time;
    unsigned long static sleep_time = 1800000;
    // mode veille
    bool go_sleep;

public:
    Cafetiere();
    void selection_cafe();
    void check_sleep();
    void preparer_chauffe();
    void cycle_machine();
    void fonctionne();
};

#endif
