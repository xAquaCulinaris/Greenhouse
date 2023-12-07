#include "LedStripController.h"


LedStripController::LedStripController(int pinNumber, int numberOfLeds)
{
    this->pinNumber = pinNumber;
    this->numberOfLeds = numberOfLeds;
}

void LedStripController::setup()
{
    pixels = new Adafruit_NeoPixel(numberOfLeds, pinNumber, NEO_GRB + NEO_KHZ800);
}

void LedStripController::deactivate()
{
    for (int i = 0; i < this->numberOfLeds; i++)
    {
        pixels->setPixelColor(i, pixels->Color(0, 0, 0));
        pixels->show();
    }
}

void LedStripController::activate()
{
    for (int i = 0; i < this->numberOfLeds; i++)
    {
        pixels->setPixelColor(i, pixels->Color(255, 255, 255)); // Moderately bright green color.
        pixels->show();                                         // This sends the updated pixel color to the hardware.
    }
}
