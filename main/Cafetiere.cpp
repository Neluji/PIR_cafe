// #include <Arduino.h>
// #include "Cafetiere.h"

// Cafetiere::Cafetiere() : 
//     Led led_alim(D7), 
//     Bouton bouton_switch(D6), 
//     Bouton bouton_select(D5), 
//     Sensor capteur_eau(D9), 
//     Potentiometre pot_eau(A0), 
//     Chauffage chauffage(D2), 
//     Pompe pompe(D1) {
//     //
//     // 1 : filtre, 2 : expresso
//     int type_cafe = 1;
//     // 0 : pas assez d'eau, 1 : assez d'eau
//     bool niveau_eau_OK = 0;
//     // temps de chauffe (en ms)
//     int tps_chauffe = -1;
//     int tps_chauffe_filtre = 10000; /* WIP valeur arbitraire */
//     int tps_chauffe_expresso = 20000; /* WIP valeur arbitraire */
//     // temps de pompage (en ms)
//     int tps_pompe = -1;
//     int tps_pompe_filtre = 5000; /* WIP valeur arbitraire */
//     int tps_pompe_expresso = 10000; /* WIP valeur arbitraire */
//     // temps d'utilisation (en ms)
//     unsigned long static start_time = 0;
//     unsigned long static elapsed_time = 0;
//     unsigned long static sleep_time = 1800000;
//     bool static go_sleep = false;
// }
// ////////////////////////////////////////////////////////////////////////////////
// void Cafetiere::selection_cafe() {
//     // RAZ des variables de veille
//     start_time = millis();
//     elapsed_time = 0;
//     go_sleep = false;

//     // boucle bloquante en attente de l'utilisateur
//     while(!bouton_select.is_pushed() && !go_sleep ){
        
//         /* WIP écran accueil */
//         if(bouton_switch.is_pushed()){
//             if(type_cafe == 1){
//                 type_cafe = 2;
//                 tps_chauffe = tps_chauffe_expresso;
//                 tps_pompe = tps_pompe_expresso;
//                 /* WIP écran expresso */
//             }
//             else if(type_cafe == 2){
//                 type_cafe = 1;
//                 tps_chauffe = tps_chauffe_filtre;
//                 tps_pompe = tps_pompe_filtre;
//                 /* WIP écran filtre */
//             }
//         }
//         // MAJ des variables de veille
//         elapsed_time = millis() - start_time;
//         go_sleep = (elapsed_time > sleep_time);
//     }

// }
// ////////////////////////////////////////////////////////////////////////////////
// void Cafetiere::check_sleep() {
//     if(go_sleep) {
//         /* WIP écran mise en veille */
//         delay(5000);
        
//         ////////////////////////
//         // regarder deepSleep //
//         // https://forum.arduino.cc/t/sleep-mode-of-esp8266/582229/2 //
//         ////////////////////////
//     }
// }
// ////////////////////////////////////////////////////////////////////////////////
// void Cafetiere::check_eau() {
//     niveau_eau_OK = !capteur_eau.read();
//     if(!niveau_eau_OK) {
//         /* WIP écran niveau eau insuffisant */
//         delay(5000);
//     }
// }
// ////////////////////////////////////////////////////////////////////////////////
// void Cafetiere::cycle_chauffe() {
//     chauffage.start();
//     delay(tps_chauffe);
//     chauffage.stop();
// }
// ////////////////////////////////////////////////////////////////////////////////
// void Cafetiere::cycle_pompe() {
//     pompe.start();
//     delay(tps_pompe);
//     pompe.stop();
// }
// ////////////////////////////////////////////////////////////////////////////////




// ////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////
// void Cafetiere::fonctionne() {

//     selection_cafe();
//     check_sleep();
//     check_eau();

//     if(niveau_eau_OK){
//         cycle_chauffe();
//         cycle_pompe();
//     }
// }



