 #include <Arduino.h>
 #include "Cafetiere.h"

 Cafetiere::Cafetiere() : led_alim(D7), bouton_switch(D6), bouton_select(D5), capteur_eau(D9),  chauffage(D2), pompe(D1) {
     type_cafe = 1;
     niveau_eau_OK = 0;
     tps_cafe = -1;
     tps_chauffe = -1;
     tps_pompe = -1;
     start_time = 0;
     elapsed_time = 0;
     go_sleep = false;
 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::selection_cafe() {
     // RAZ des variables de veille
     start_time = millis();
     elapsed_time = 0;
     go_sleep = false;

     // boucle bloquante en attente de l'utilisateur
     while(!bouton_select.is_pushed() && !go_sleep ){
        
         /* WIP écran accueil */
         if(bouton_switch.is_pushed()){
             if(type_cafe == 1){
                 type_cafe = 2;
                 tps_cafe = tps_cafe_expresso;
                 tps_chauffe = tps_chauffe_expresso;
                 tps_pompe = tps_pompe_expresso;
                 /* WIP écran expresso */
             }
             else if(type_cafe == 2){
                 type_cafe = 1;
                 tps_cafe = tps_cafe_filtre;
                 tps_chauffe = tps_chauffe_filtre;
                 tps_pompe = tps_pompe_filtre;
                 /* WIP écran filtre */
             }
         }
         // MAJ des variables de veille
         elapsed_time = millis() - start_time;
         //go_sleep = (elapsed_time > sleep_time); //temp suspendu
     }

 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::check_sleep() {
     if(go_sleep) {
         /* WIP écran mise en veille */
         delay(5000);
        
         ////////////////////////
         // regarder deepSleep //
         // https://randomnerdtutorials.com/esp8266-deep-sleep-with-arduino-ide/ //
         ////////////////////////
     }
 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::check_eau() {
     niveau_eau_OK = !capteur_eau.read();
     if(!niveau_eau_OK) {
         /* WIP écran niveau eau insuffisant */
         delay(5000);
     }
 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::preparer_chauffe() {
     chauffage.start();
     while (chauffage.read() < palier_temp_inf) {
         delay(100);
     }
     chauffage.stop();
     /* WIP a tester, pour faire chuter l'inertie */
     delay(5000);
 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::cycle_machine() {
     float valeur_temp = 0.0;
     bool en_chauffe = false;

     start_time = millis();
     elapsed_time = 0;
     pompe.start();
     while (elapsed_time < tps_cafe) {
         valeur_temp = chauffage.read();
         en_chauffe = chauffage.is_on();

         if (valeur_temp < palier_temp_inf && !en_chauffe) {
             chauffage.start();
         }
         else if (valeur_temp > palier_temp_sup && en_chauffe) {
             chauffage.stop();
         }
         delay(100);
         elapsed_time = millis() - start_time;
     }
     pompe.stop();
     chauffage.stop();
 }
 ////////////////////////////////////////////////////////////////////////////////



 ////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::fonctionne() {

     selection_cafe();
     check_sleep();
     check_eau();
     preparer_chauffe();
     cycle_machine();

     //if(niveau_eau_OK){}
 }



