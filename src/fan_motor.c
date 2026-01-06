#include "fan_motor.h"
#include "driver/gpio.h"
#include "board.h"

void fan_init(){
  gpio_set_direction(MOTOR_PIN, GPIO_MODE_OUTPUT);

}

void fan_on(){
  gpio_set_level(MOTOR_PIN, 1);

}

void fan_off(){
  gpio_set_level(MOTOR_PIN, 0);
}