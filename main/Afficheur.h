#ifndef LCD_H
#define LCD_H

#include <U8g2lib.h>

using namespace std;

class Afficheur {
private:
    U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2;
public:
    Afficheur();
    void print_text(const int t_x, const int t_y, const char* t_text, const uint8_t* t_font);
    void print_bmp(const int t_height, const int t_width, const uint8_t* t_bmp);
    void turn_off();
    //==== Screens definitions ====//
    void welcome_screen();
    void select_screen();
    void filter_screen();
    void espresso_screen();
    void prepare_screen(int percentage);
    void ready_screen();
    void sleep_screen();
};

#endif