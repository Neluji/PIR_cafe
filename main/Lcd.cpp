#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include "Lcd.h"

Lcd::Lcd() : u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE) {
    u8g2.begin();
}

void Lcd::printText(const int t_x, const int t_y, const char* t_text, const uint8_t* t_font) {
    u8g2.firstPage();
    do
    {
        u8g2.setFont(t_font);
        u8g2.drawStr(t_x,t_y,t_text);
    } while (u8g2.nextPage());
}

void Lcd::printBmp(const int t_height, const int t_width, const uint8_t* t_bmp) {
    u8g2.firstPage();
    do
    {
        u8g2.drawXBM(0,0,t_width,t_height,t_bmp);
    } while (u8g2.nextPage());
}

//==== Screens definitions ====//

//Les \n ne marchent pas --> écrire en plusieurs ligne
void Lcd::selectScreen() {
    printText(0,40,"Veuillez\nsélectionner\nun café",u8g2_font_logisoso16_tf);
}