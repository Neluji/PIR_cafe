#include <Arduino.h>
#include "Cafetiere.h"

Cafetiere::Cafetiere() :
    led_alim(PIN_LED_ALIM),
    bouton_switch(PIN_BOUTON_SW),
    bouton_select(PIN_BOUTON_SEL),
    chauffage(PIN_CHAUFFAGE, PIN_TEMP),
    pompe(PIN_POMPE),
    afficheur(),
    type_cafe(1),
    tps_cafe(TEMPS_CAFE_FILTRE),
    start_time(0),
    elapsed_time(0),
    go_sleep(false)
{
    led_alim.turn_on();
    afficheur.welcome_screen();
}
////////////////////////////////////////////////////////////////////////////////
void Cafetiere::selection_cafe()
{
    Serial.println("Début sélection café :");
    // RAZ des variables de veille
    start_time = millis();
    elapsed_time = 0;
    go_sleep = false;
    // présentation du menu
    afficheur.select_screen();
    delay(2000);
    afficheur.filter_screen();
    Serial.println("|   Filtre sélectionné");

    // boucle bloquante en attente de l'utilisateur
    while (!bouton_select.is_pushed() && !go_sleep)
    {
        if (bouton_switch.is_pushed())
        {
            if (type_cafe == 1)
            {
                type_cafe = 2;
                tps_cafe = TEMPS_CAFE_EXPRESSO;
                afficheur.espresso_screen();
                Serial.println("|   Espresso sélectionné");
            }
            else if (type_cafe == 2)
            {
                type_cafe = 1;
                tps_cafe = TEMPS_CAFE_FILTRE;
                afficheur.filter_screen();
                Serial.println("|   Filtre sélectionné");
            }
        }
        // MAJ des variables de veille
        elapsed_time = millis() - start_time;
        go_sleep = (elapsed_time > SLEEP_TIME);
        delay(100);
    }
    Serial.println(">Fin sélection café");
}
////////////////////////////////////////////////////////////////////////////////
void Cafetiere::check_sleep()
{
    Serial.println("Début check sleep");
    if (go_sleep)
    {
        Serial.println("|    Mise en deep sleep");
        afficheur.sleep_screen();
        delay(5000);
        afficheur.turn_off();
        ESP.deepSleep(0);

        ////////////////////////
        // regarder deepSleep //
        // https://randomnerdtutorials.com/esp8266-deep-sleep-with-arduino-ide/ //
        ////////////////////////
    }
    Serial.println(">Fin check sleep");
}
////////////////////////////////////////////////////////////////////////////////
void Cafetiere::preparer_chauffe()
{
    Serial.println("Début préchauffage");
    afficheur.prepare_screen(0);
    chauffage.start();
    float valeur_temp = chauffage.read();
    while (valeur_temp < PALIER_TEMP_INF)
    {
        Serial.print("|   valeur_temp : ");
        Serial.print(valeur_temp);
        Serial.print(" ~ RT = ");
        Serial.print((10/valeur_temp)-10);
        Serial.print(";");
        Serial.print(millis());
        Serial.print(";");
        Serial.println(valeur_temp);
        valeur_temp = chauffage.read();
        delay(100);
    }
    Serial.print("|   Arrêt chauffage");
    chauffage.stop();
    // retard pour faire chuter l'inertie
    /*unsigned long start = millis();
    while (millis() - start < 5000)
    {
        Serial.print("|   valeur_temp : ");
        Serial.print(valeur_temp);
        Serial.print(" ~ RT = ");
        Serial.print((10/valeur_temp)-10);
        Serial.print(";");
        Serial.print(millis());
        Serial.print(";");
        Serial.println(valeur_temp);
        valeur_temp = chauffage.read();
        delay(100);
    }
    delay(500);*/
    while (valeur_temp < PALIER_TEMP_SUP)
    {
        Serial.print("|   Boucle coupe d'inertie");
        delay(100);
    }
    
    Serial.println(">Fin préchauffage");
}
////////////////////////////////////////////////////////////////////////////////
void Cafetiere::cycle_machine()
{
    Serial.println("Début cycle");
    float valeur_temp = 0.0;
    bool en_chauffe = false;

    afficheur.prepare_screen(0);
    start_time = millis();
    elapsed_time = 0;
    Serial.println("|   Démarrage de la pompe");
    pompe.start();
    while (elapsed_time < tps_cafe)
    {
        afficheur.prepare_screen((100 * elapsed_time) / tps_cafe);
        valeur_temp = chauffage.read();
        en_chauffe = chauffage.is_on();
        Serial.print("|   valeur_temp : ");
        Serial.print(valeur_temp);
        Serial.print(" ~ RT = ");
        Serial.print((10/valeur_temp)-10);
        Serial.print(";");
        Serial.print(millis());
        Serial.print(";");
        Serial.println(valeur_temp);
        if (valeur_temp < PALIER_TEMP_SUP && !en_chauffe)
        {
            Serial.println("|   Allumage du chauffage");
            chauffage.start();
        }
        else if (valeur_temp > PALIER_TEMP_SUP && en_chauffe)
        {
            Serial.println("|   Arrêt du chauffage");
            chauffage.stop();
        }
        delay(100);
        /*if (!en_chauffe) elapsed_time += millis()- start_time;
        start_time = millis();*/
        
        elapsed_time = millis() - start_time;
    }
    pompe.stop();
    Serial.println("|   Arrêt de la pompe");
    chauffage.stop();
    Serial.println("|   Arrêt du chauffage");
    Serial.println(">Fin cycle");
    afficheur.ready_screen();
    delay(5000);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Cafetiere::fonctionne()
{
    selection_cafe();
    check_sleep();
    preparer_chauffe();
    cycle_machine();
}
