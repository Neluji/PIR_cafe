#include <Arduino.h>
#include "Lcd.h"

Lcd::Lcd(char t_pin) : Serial_Device(230400) {}

void Lcd::display_image(String t_image, int t_width, int t_height) {
    for (int i = 0; i < t_width/8; i++) {
        serial_send_data(&m_image_set.at(t_image).first[i * t_height], t_height);
        delay(70);
    }
    delay(70);
    for (int i = 0; i < t_width/8; i++) {
        serial_send_data(&m_image_set.at(t_image).second[i * t_height], t_height);
        delay(70);
    }
}

void Lcd::add_to_set(String t_name,pair<char*,char*> t_image) {
    m_image_set.insert(make_pair(t_name,t_image));
}

void Lcd::remove_from_set(String t_name) {
    m_image_set.erase(t_name);
}