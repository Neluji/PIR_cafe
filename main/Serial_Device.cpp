#include <Arduino.h>
#include "Serial_Device.h"

void send_begin() {
    char str = 'a';
    Serial.write(str);
    while (1) {
        if (Serial.available() > 0) {
            delay(10);
            char str1 = Serial.read();
            Serial.print(str1);
            if (str1 == 'b') {
                break;
            }
        }
    }
}

Serial_Device::Serial_Device(unsigned int t_baud) {
    Serial.begin(t_baud);
    delay(10);
    send_begin();
    delay(2000);
}

void Serial_Device::serial_send_data(const char* data, int data_len) {
    for (int i = 0; i < data_len; i++) {
        Serial.write(pgm_read_byte(&data[i]));
    }
}