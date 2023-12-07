#include <Arduino.h>
#include "LedStripController.h"
#include "DisplayController.h"
#include "Co2Sensor.h"


int delayval = 500;

DisplayController *display;

Co2Sensor *co2Sensor;

void setup()
{
  Serial.begin(115200);
  Serial.print("Setuped");

  display = new DisplayController();
  display->setup();

  co2Sensor = new Co2Sensor();
  co2Sensor->setup();
  co2Sensor->calibrate();
}

void loop()
{
  Serial.println("Measure");

  float printerTmp = 26.7;
  boolean printerLightOn = true;
  float ppm = co2Sensor->measure();

  float greenHouseTmp = 21.7;
  boolean greenHouseLightOn = false;
  float plantHumidity = 37.8;

  display->setPrinterTmp(printerTmp);
  display->setPPM(ppm);
  display->setPrinterLights(printerLightOn);

  display->setGreenhouseTmp(greenHouseTmp);
  display->setGreenhouseLights(greenHouseLightOn);
  display->setPlantHumidity(plantHumidity);

  display->update();

  delay(delayval); // Delay for a period of time (in milliseconds).
}
