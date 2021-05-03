#ifndef LCD_H
#define LCD_H

#include <U8g2lib.h>

using namespace std;

class Lcd {
private:
    U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2;
public:
    Lcd();
    void printText(const int t_x, const int t_y, const char* t_text, const uint8_t* t_font);
    void printBmp(const int t_height, const int t_width, const uint8_t* t_bmp);
    void selectScreen();
};

#endif