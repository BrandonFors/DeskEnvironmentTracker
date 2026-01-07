// This file is unusable with esp32c3 as esp32c3 has no mcpwm hardware
// Keeping this in case i choose to upgrade to esp32 board




// #include "driver/mcpwm_prelude.h"
// #include "esp_log.h"
// #include "vent.h"
// #include "soc/clk_tree_defs.h"

// static const char *TAG = "Vent Servo";
// static mcpwm_timer_config_t timer_config;
// static mcpwm_timer_handle_t timer;
// static mcpwm_oper_handle_t oper;
// static mcpwm_operator_config_t operator_config;
// static mcpwm_cmpr_handle_t comparator;
// static mcpwm_comparator_config_t comparator_config;

// void vent_init(){
//   ESP_LOGI(TAG, "Create timer and operator");

//   //creates timer config with the values declared in header file
//   timer_config = (mcpwm_timer_config_t){
//     .group_id = 0,
//     .clk_src = MCPWM_TIMER_CLK_SRC_DEFAULT,
//     .resolution_hz = SERVO_TIMEBASE_RESOLUTION_HZ,
//     .period_ticks = SERVO_TIMEBASE_PERIOD,
//     .count_mode = MCPWM_TIMER_COUNT_MODE_UP,
//   };


//   ESP_ERROR_CHECK(mcpwm_new_timer(&timer_config, &timer));

//   operator_config = (mcpwm_operator_config_t){
//     .group_id = 0,
//   };
//   ESP_ERROR_CHECK(mcpwm_new_operator(&operator_config, &oper));

//   ESP_LOGI(TAG, "Connecting timer and operator");
  
//   ESP_ERROR_CHECK(mcpwm_operator_connect_timer(oper, timer));

//   ESP_LOGI(TAG, "Creating Comparator and generator from the operator");
  
//   comparator_config = (mcpwm_comparator_config_t ){
//     .flags.update_cmp_on_tez = true,
//   };
//   ESP_ERROR_CHECK(mcpwm_new_comparator(oper, &comparator_config, &comparator));

// }