#ifndef SENSOR_H
#define SENSOR_H

#include "Composant.h"

class Sensor : public Composant
{
public:
    Sensor(char t_pin);
    int read();
};

#endif
