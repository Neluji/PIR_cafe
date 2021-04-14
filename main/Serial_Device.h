#ifndef SERIAL_DEVICE_H
#define SERIAL_DEVICE_H

class Serial_Device
{
private:
    
public:
    Serial_Device(unsigned int t_baud);
    void serial_send_data(const char* data, int data_len);
};

#endif