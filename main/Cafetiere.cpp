#include <Arduino.h>
#include "Cafetiere.h"

Cafetiere::Cafetiere() {
    //
    Led led_alim('D7');
    Bouton bouton_filtre('D6');
    Bouton bouton_expresso('D5');
    Sensor capteur_eau('D9');
    Potentiometre pot_eau('A0');
    Chauffage chauffage('D2');
    Pompe pompe('D1');
    // 0 : aucun, 1 : filtre, 2 : expresso
    int type_cafe = 0;
    // 0 : pas assez d'eau, 1 : assez d'eau
    bool niveau_eau_OK = 0;
    // temps de chauffe en ms
    int tps_chauffe_filtre = 10000;
    int tps_chauffe_expresso = 20000;
}
////////////////////////////////////////////////////////////////////////////////
void selection_cafe() {
    if(bouton_filtre.is_pushed()){
        type_cafe = 1;
    }
    else if(bouton_expresso.is_pushed()){
        type_cafe = 2;
    }
    else{
        type_cafe = 0;
    }
}
////////////////////////////////////////////////////////////////////////////////
void check_eau() {
    niveau_eau_OK = !capteur_eau.read();
}
////////////////////////////////////////////////////////////////////////////////
void lancer_chauffe() {
    chauffage.start();
}
////////////////////////////////////////////////////////////////////////////////
void arreter_chauffe() {
    chauffage.stop();
}
////////////////////////////////////////////////////////////////////////////////
void lancer_pompe() {
    pompe.start();
}
////////////////////////////////////////////////////////////////////////////////
void arreter_pompe() {
    pompe.stop();
}
////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void fonctionne() {

    selection_cafe();

    // boucle attente assez eau

    if(type_cafe == 1){
        check_eau();

        lancer_chauffe();
        delay(tps_chauffe_filtre);
        arreter_chauffe();
    }
    else if(type_cafe == 2){
        check_eau();

        lancer_chauffe();
        delay(tps_chauffe_expresso);
        arreter_chauffe();
    }
}




