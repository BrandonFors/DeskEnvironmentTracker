#ifndef RTOS_SETUP_H
#define RTOS_SETUP_H

#include "freertos/FreeRTOS.h"

#define BUTTON_QUEUE_LEN 1

#define DEBOUNCE_TIME_MS 250



typedef struct {

} Actuator;



//queue handles

QueueHandle_t buttonQueue;


//Task Handles 

TaskHandle_t userInterfaceTask;


void gpio_isr_handler(void* arg);

#endif