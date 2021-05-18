#include "Composant.h"
#include "Led.h"
#include "Bouton.h"
#include "Chauffage.h"
#include "Pompe.h"
#include "Afficheur.h"

#ifndef CAFETIERE_H
#define CAFETIERE_H

//Configuration des pins
#define PIN_LED_ALIM D7
#define PIN_BOUTON_SW D6
#define PIN_BOUTON_SEL D5
#define PIN_CHAUFFAGE D4
#define PIN_TEMP A0
#define PIN_POMPE D8

//Paramètres café
#define PALIER_TEMP_INF 0.50
#define PALIER_TEMP_SUP 0.55
#define TEMPS_CAFE_FILTRE 30000 /* WIP valeur arbitraire */
#define TEMPS_CAFE_EXPRESSO 7500 /* WIP valeur arbitraire */

//Paramètres système
#define SLEEP_TIME 1800000

class Cafetiere
{
private:
    Led led_alim; //D7
    Bouton bouton_switch; //D6
    Bouton bouton_select; //D5
    Chauffage chauffage; //D4 out, A0 in
    Pompe pompe; //D8
    Afficheur afficheur; //I2C
    // 1 : filtre, 2 : expresso
    int type_cafe;
    // paliers de temperature
    //const float PALIER_TEMP_INF = 0.45;
    //const float PALIER_TEMP_SUP = 0.57;
    // temps de preparation (en ms)
    unsigned long tps_cafe;
    //const unsigned long TEMPS_CAFE_FILTRE = 13000; /* WIP valeur arbitraire */
    //const unsigned long TEMPS_CAFE_EXPRESSO = 13000; /* WIP valeur arbitraire */
    // temps d'utilisation (en ms)
    unsigned long start_time;
    unsigned long elapsed_time;
    //const unsigned long SLEEP_TIME = 1800000;
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
