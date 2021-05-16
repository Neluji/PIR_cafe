 #include <Arduino.h>
 #include "Cafetiere.h"

<<<<<<< Updated upstream
 Cafetiere::Cafetiere() : led_alim(D7), bouton_switch(D6), bouton_select(D5), chauffage(D2), pompe(D1) {
=======
 Cafetiere::Cafetiere() : led_alim(D7), bouton_switch(D6), bouton_select(D5),  chauffage(D2), pompe(D1) {
     led_alim.turn_on();
>>>>>>> Stashed changes
     type_cafe = 1;
     tps_cafe = -1;
     start_time = 0;
     elapsed_time = 0;
     go_sleep = false;
     led_alim.turn_on();
     afficheur.welcome_screen();
     delay(3000);
 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::selection_cafe() {
     // RAZ des variables de veille
     start_time = millis();
     elapsed_time = 0;
     go_sleep = false;
     // présentation du menu
     /* WIP écran accueil */
     delay(10000);
     /* WIP écran expresso (default)*/

     // boucle bloquante en attente de l'utilisateur
     while(!bouton_select.is_pushed() && !go_sleep ){
        
         if(bouton_switch.is_pushed()){
             if(type_cafe == 1){
                 type_cafe = 2;
                 tps_cafe = tps_cafe_expresso;
                 /* WIP écran expresso */
             }
             else if(type_cafe == 2){
                 type_cafe = 1;
                 tps_cafe = tps_cafe_filtre;
                 /* WIP écran filtre */
             }
         }
         // MAJ des variables de veille
         elapsed_time = millis() - start_time;
         go_sleep = (elapsed_time > sleep_time);
     }

 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::check_sleep() {
     if(go_sleep) {
         /* WIP écran mise en veille */
         delay(5000);
         ESP.deepSleep(0);
        
         ////////////////////////
         // regarder deepSleep //
         // https://randomnerdtutorials.com/esp8266-deep-sleep-with-arduino-ide/ //
         ////////////////////////
     }
 }
 ////////////////////////////////////////////////////////////////////////////////
 void Cafetiere::preparer_chauffe() {
     chauffage.start();
     while (chauffage.read() < palier_temp_inf) {
         delay(100);
     }
     chauffage.stop();
     // retard pour faire chuter l'inertie
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
     preparer_chauffe();
     cycle_machine();
 }



