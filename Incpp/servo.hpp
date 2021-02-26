#include <stdint.h>
#include "hardware/pwm.h"
#include "pico/stdlib.h"


class servo
{
private:
    uint16_t min, max;
    uint8_t pin;
    uint16_t position;
    void set(uint16_t value);

public:
    servo(uint8_t pin, uint16_t min, uint16_t max);
    void move(uint16_t value, uint8_t dir);
};

