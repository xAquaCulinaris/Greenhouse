#include <Adafruit_NeoPixel.h>

class LedStripController
{

public:
    LedStripController(int pinNumber, int numberOfLeds);
    void setup();
    void activate();
    void deactivate();

private:
    void setLedColor();
    int numberOfLeds;
    int pinNumber;
    Adafruit_NeoPixel *pixels;
};

