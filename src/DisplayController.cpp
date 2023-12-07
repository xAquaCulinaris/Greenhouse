#include "DisplayController.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

void DisplayController::setup()
{
    display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
    display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display->clearDisplay();

    // Beispiel einer Textausgabe:
    display->setTextColor(WHITE);
    display->setTextSize(1);
    display->setCursor(10, 0);
    display->println("Setuped");
    display->display();
}

void DisplayController::update()
{
    display->clearDisplay();
    display->setTextColor(WHITE);
    display->setTextSize(1);

    // Printer
    display->setCursor(0, 0);
    display->print("Printer:");

    display->setCursor(75, 0);
    display->print("(" + String(printerTmp) + "c)");

    display->setCursor(10, 10);
    display->print("CO2: " + String(ppm));

    display->setCursor(10, 20);
    display->print("Light: " + booleanToString(printerLights));

    // GreenHouse
    display->setCursor(0, 35);
    display->print("Greenhouse:");

    display->setCursor(75, 35);
    display->print("(" + String(greenhouseTmp) + "c)");

    display->setCursor(10, 45);
    display->print("PlantHum: " + String(plantHumidity));

    display->setCursor(10, 55);
    display->print("Light: " + booleanToString(greenhouseLights));

    display->display();
}

void DisplayController::setPrinterTmp(float tmp)
{
    this->printerTmp = tmp;
}

void DisplayController::setPPM(float ppm)
{
    this->ppm = ppm;
}

void DisplayController::setPrinterLights(boolean lightsOn)
{
    this->printerLights = lightsOn;
}

void DisplayController::setGreenhouseTmp(float tmp)
{
    this->greenhouseTmp = tmp;
}

void DisplayController::setGreenhouseLights(boolean lightsOn)
{
    this->greenhouseLights = lightsOn;
}

void DisplayController::setPlantHumidity(int humidity)
{
    this->plantHumidity = humidity;
}

String DisplayController::booleanToString(boolean toConvert)
{
    if (toConvert)
        return "on";
    else
        return "off";
}
