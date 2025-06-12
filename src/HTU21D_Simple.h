#ifndef HTU21D_SIMPLE_H
#define HTU21D_SIMPLE_H

#include <Arduino.h>

class HTU21D_Simple {
  public:
    HTU21D_Simple(uint8_t address = 0x40);
    bool begin();
    float readTemperature();
    float readHumidity();
    
  private:
    uint8_t _address;
};

#endif
