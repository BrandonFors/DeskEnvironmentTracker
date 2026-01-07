#include "board.h"
#include "vent.h"
#include "driver/ledc.h"

//the values below are assigned based on SG90 datasheet
#define PWM_PERIOD 50 // pwm period in HZ
// next two are just used for angle calculations
#define MIN_PULSE 1000 // min pulse in us
#define MAX_PULSE 2000 // max pulse in us
#define MAX_DUTY 16383 // max duty cycle for 14 bit duty resolution

static ledc_timer_config_t timer_config;
static ledc_channel_config_t channel_config;

void vent_init(){
    timer_config = (ledc_timer_config_t){
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .duty_resolution = LEDC_TIMER_14_BIT,
    .timer_num = LEDC_TIMER_1,
    .freq_hz = PWM_PERIOD,
    .clk_cfg = LEDC_AUTO_CLK,
  };
  
  ledc_timer_config(&timer_config);

  //create a configuration for the channel of the ledc
  channel_config = (ledc_channel_config_t){
    .gpio_num = VENT_PIN, 
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .channel = LEDC_CHANNEL_1,
    .timer_sel = LEDC_TIMER_1,
    .duty = angle_to_duty(90),
    .hpoint = 0,

  };

  ledc_channel_config(&channel_config);

  ledc_fade_func_install(0);

}

uint32_t angle_to_duty(uint8_t angle){
  if (angle > 180){
    angle = 180;
  }
  //convert the angle into the pulse value for that angle
  uint32_t pulse = MIN_PULSE + (uint32_t)angle*(MAX_PULSE-MIN_PULSE)/180; 
  //return the duty cycle for the angle
  return pulse*MAX_DUTY/MAX_PULSE;
}

void vent_set_angle(uint8_t angle){
  uint32_t new_duty = angle_to_duty(angle);

  ESP_ERROR_CHECK(ledc_set_duty_and_update(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, new_duty, 0));


}