#include "servo.hpp"

servo::servo(uint8_t pin, uint16_t min, uint16_t max): pin(pin), min(min), max(max)
{
    gpio_set_function(this->pin, GPIO_FUNC_PWM);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 40.f);
    pwm_init(pwm_gpio_to_slice_num(this->pin), &config, true);
    set((this->max - this->min)/2);
    position = (this->max - this->min)/2;
}

void servo::set(uint16_t value) {
    if(value > this->max) value = max;
    if(value < this->min) value = min;
    pwm_set_gpio_level(this->pin, value);
}

void servo::move(uint16_t value, uint8_t dir) {
    if(dir) this->position += value;
    else this->position += -value;

    if(this->position > this->max) this->position = this->max;
    if(this->position < this->min) this->position = this->min;
    set(this->position);
}
