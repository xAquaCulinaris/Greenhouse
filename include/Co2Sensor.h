#include "MQUnifiedsensor.h"

/************************Hardware Related Macros************************************/
#define Board ("ESP-32")
#define Pin (0)
/***********************Software Related Macros************************************/
#define Type ("MQ-2") // MQ2
#define Voltage_Resolution (5)
#define ADC_Bit_Resolution (12)
#define RatioMQ2CleanAir (9.83) // RS / R0 = 9.83 ppm

class Co2Sensor
{
public:
    Co2Sensor();
    void setup();
    void calibrate();
    float measure();

private:
    MQUnifiedsensor *sensor;
};