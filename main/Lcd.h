#ifndef LCD_H
#define LCD_H

#include "Serial_Device.h"
#include <map>

using namespace std;

class Lcd : public Serial_Device {
private:
    std::map<String,pair<char*,char*>> m_image_set;
public:
    Lcd(char t_pin);
    void display_image(String t_image, int t_width, int t_height);
    void add_to_set(String t_name,pair<char*,char*> t_image);
    void remove_from_set(String t_name);
};

#endif