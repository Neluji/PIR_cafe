#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include "Lcd.h"
#include "res/bmp_list.h"

Lcd::Lcd() : u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE) {
    u8g2.begin();
}

void Lcd::print_text(const int t_x, const int t_y, const char* t_text, const uint8_t* t_font) {
    u8g2.firstPage();
    do
    {
        u8g2.setFont(t_font);
        u8g2.drawStr(t_x,t_y,t_text);
    } while (u8g2.nextPage());
}

void Lcd::print_bmp(const int t_height, const int t_width, const uint8_t* t_bmp) {
    u8g2.firstPage();
    do
    {
        u8g2.drawXBM(0,0,t_width,t_height,t_bmp);
    } while (u8g2.nextPage());
}

//==== Screens definitions ====//

void Lcd::welcome_screen() {
    u8g2.firstPage();
    do
    {
        
    } while (u8g2.nextPage());
    
}

void Lcd::select_screen() {
    u8g2.firstPage();
    do
    {
        u8g2.setFont(u8g2_font_logisoso16_tf);
        u8g2.drawStr(0,40,"Veuillez");
        u8g2.drawStr(0,40,"sélectionner");
        u8g2.drawStr(0,40,"un café");
    } while (u8g2.nextPage());
}
void Lcd::filter_screen() {
    print_bmp(filter_height,filter_width,filter_bits);
}

void Lcd::espresso_screen() {
    print_bmp(espresso_height,espresso_width,espresso_bits);
}

void Lcd::prepare_screen(int percentage) {
    int box_width = (percentage*108)/100;
    u8g2.firstPage();
    do
    {
        u8g2.drawBox(10,100,box_width,20);
        u8g2.drawXBM(0,0,prepare_width,prepare_height,prepare_bits);
    } while (u8g2.nextPage());
}

void Lcd::water_alert_screen() {
    print_bmp(wateralert_height,wateralert_width,wateralert_bits);
}

void Lcd::sleep_screen() {}