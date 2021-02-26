#include "hardware/adc.h"
#include "servo.hpp"
#include "math.h"
#include "pico/stdlib.h"
#include <stdint.h>


#define ADC0 26
#define ADC1 27
#define ADC2 28
#define PWM0 14
#define PWM1 15
#define EPSILON 40

servo s1(PWM0, 1200, 8240);
servo s2(PWM1, 3450, 5700);

uint16_t sun[3];

inline void sunMeasurement(uint16_t count) {
    for(uint8_t adc = 0; adc < 3; adc++) {
        adc_select_input(adc);
        uint32_t sum = 0;
        for(uint16_t i = 0; i < count; ++i) sum += adc_read();

        sun[adc] = sum/count;
    }
}

int main() {

    stdio_init_all();

    adc_init();
    adc_gpio_init(ADC0);
    adc_gpio_init(ADC1);
    adc_gpio_init(ADC2);

    while(true) {
        sunMeasurement(500);
        if(abs(sun[0] - sun[1]) > EPSILON) {
            if(sun[0] > sun[1]) s1.move(1, 1);
            else if(sun[0] < sun[1]) s1.move(1, 0);
        }

        if(abs(sun[1] - sun[2]) > EPSILON) {
            if(sun[1] > sun[2]) s2.move(1, 0);
            else if(sun[1] < sun[2]) s2.move(1, 1);
        }
    }
    return 0;
}
