#include <Arduino.h>
#include "LedStripController.h"
#include "DisplayController.h"
#include "Co2Sensor.h"
#include "PlantHumiditySensor.h"

int delayval = 500;

DisplayController *display;
Co2Sensor *co2Sensor;
PlantHumiditySensor *plantHumSensor;

void setup()
{
  Serial.begin(115200);
  Serial.print("Setuped");

  display = new DisplayController();
  display->setup();

  co2Sensor = new Co2Sensor();
  co2Sensor->setup();
  co2Sensor->calibrate();

  plantHumSensor = new PlantHumiditySensor();
}

void loop()
{
  Serial.println("Measure");

  float printerTmp = 26.7;
  boolean printerLightOn = true;
  float ppm = co2Sensor->measure();

  float greenHouseTmp = 21.7;
  boolean greenHouseLightOn = false;
  int plantHumidity = plantHumSensor->measure();

  display->setPrinterTmp(printerTmp);
  display->setPPM(ppm);
  display->setPrinterLights(printerLightOn);

  display->setGreenhouseTmp(greenHouseTmp);
  display->setGreenhouseLights(greenHouseLightOn);
  display->setPlantHumidity(plantHumidity);

  display->update();

  delay(delayval); // Delay for a period of time (in milliseconds).
}
