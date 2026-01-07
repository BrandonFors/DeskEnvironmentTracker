
//these values represent the min and max duty cycle when the lamp is in a usable state
#define MAX_LAMP_DUTY 255
#define MIN_LAMP_DUTY 0

void lamp_init();

void lamp_set_brightness(uint8_t percent);