#include "Co2Sensor.h"

Co2Sensor::Co2Sensor()
{
    sensor = new MQUnifiedsensor(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);
}

void Co2Sensor::setup()
{
    // Set math model to calculate the PPM concentration and the value of constants
    sensor->setRegressionMethod(1); //_PPM =  a*ratio^b
    sensor->setA(521853);
    sensor->setB(-3.821); // Configure the equation to to calculate Benzene concentration

    sensor->init();
}

void Co2Sensor::calibrate()
{
    /*
         Exponential regression:
         Gas    | a      | b
         LPG    | 44771  | -3.245
         CH4    | 2*10^31| 19.01
         CO     | 521853 | -3.821
         Alcohol| 0.3934 | -1.504
         Benzene| 4.8387 | -2.68
         Hexane | 7585.3 | -2.849
    */

    Serial.print("Calibrating please wait.");
    float calcR0 = 0;
    for (int i = 1; i <= 10; i++)
    {
        sensor->update(); // Update data, the arduino will read the voltage from the analog pin
        calcR0 += sensor->calibrate(RatioMQ2CleanAir);
        Serial.print(".");
    }
    sensor->setR0(calcR0 / 10);
    Serial.println("  done!.");

    if (isinf(calcR0))
    {
        Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply");
        while (1)
            ;
    }
    if (calcR0 == 0)
    {
        Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply");
        while (1)
            ;
    }
}

float Co2Sensor::measure()
{
    sensor->update();                 // Update data, the arduino will read the voltage from the analog pin
    float ppm = sensor->readSensor(); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
    return ppm;
}