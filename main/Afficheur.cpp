#include <Arduino.h>
#include <U8g2lib.h>
#include "Afficheur.h"
#include "res/bmp_list.h"

Afficheur::Afficheur() : u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE) {
    u8g2.begin();
}

void Afficheur::print_text(const int t_x, const int t_y, const char* t_text, const uint8_t* t_font) {
    u8g2.firstPage();
    do
    {
        u8g2.setFont(t_font);
        u8g2.drawStr(t_x,t_y,t_text);
    } while (u8g2.nextPage());
}

void Afficheur::print_bmp(const int t_height, const int t_width, const uint8_t* t_bmp) {
    u8g2.firstPage();
    do
    {
        u8g2.drawXBM(0,0,t_width,t_height,t_bmp);
    } while (u8g2.nextPage());
}

//==== Screens definitions ====//

void Afficheur::welcome_screen() {
    u8g2.firstPage();
    do
    {
        
    } while (u8g2.nextPage());
    
}

void Afficheur::select_screen() {
    print_bmp(select_height,select_width,select_bits);
}

void Afficheur::filter_screen() {
    print_bmp(filter_height,filter_width,filter_bits);
}

void Afficheur::espresso_screen() {
    print_bmp(espresso_height,espresso_width,espresso_bits);
}

void Afficheur::prepare_screen(int percentage) {
    int box_width = (percentage*108)/100;
    u8g2.firstPage();
    do
    {
        u8g2.drawXBM(0,0,prepare_width,prepare_height,prepare_bits);
        u8g2.drawBox(10,100,box_width,20);
    } while (u8g2.nextPage());
}

void Afficheur::ready_screen() {
    print_bmp(ready_height,ready_width,ready_bits);
}

void Afficheur::sleep_screen() {
    print_bmp(sleep_height,sleep_width,sleep_bits);
}