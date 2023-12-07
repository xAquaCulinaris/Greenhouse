#include <Adafruit_SSD1306.h>

class DisplayController
{

public:
    void setup();
    void activate();
    void deactivate();
    void update();

    void setPrinterTmp(float printerTmp);
    void setPrinterLights(boolean printerLights);
    void setPPM(float ppm);

    void setGreenhouseTmp(float greenhouseTmp);
    void setGreenhouseLights(boolean greenhouseLights);
    void setPlantHumidity(int plantHumidity);

private:
    float printerTmp;
    float ppm;
    boolean printerLights;

    float greenhouseTmp;
    boolean greenhouseLights;
    int plantHumidity;

    Adafruit_SSD1306 *display;
    String booleanToString(boolean toConvert);
};
