#include <Arduino.h>
#include "PlantHumiditySensor.h"

int PlantHumiditySensor::measure()
{
    return analogRead(AOUT_PIN);
}