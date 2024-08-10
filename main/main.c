#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "servo_motor.h"


// #define OUTPUT_PIN_1    GPIO_NUM_12  
//#define OUTPUT_PIN_2    GPIO_NUM_14  
#define INPUT_PIN_1    GPIO_NUM_17   
#define INPUT_PIN_2    GPIO_NUM_14   
#define INPUT_PIN_3     GPIO_NUM_27  
#define INPUT_PIN_4     GPIO_NUM_25  
#define SERVO_PIN       GPIO_NUM_5

void setup_gpio()
{
    //configure input pins
    gpio_config_t pin_config;
    pin_config.intr_type = GPIO_INTR_DISABLE;
    pin_config.mode = GPIO_MODE_INPUT;
    pin_config.pin_bit_mask = (1ULL << INPUT_PIN_1) | (1ULL << INPUT_PIN_2) | (1ULL << INPUT_PIN_3) | (1ULL << INPUT_PIN_4);
    pin_config.pull_up_en = GPIO_PULLUP_ENABLE;
    pin_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_config(&pin_config);
}


void app_main(void)
{
    setup_gpio();
    setup_pwm(SERVO_PIN);
    while(1)
    {
        uint8_t sensor01 = gpio_get_level(INPUT_PIN_1);
        uint8_t sensor02 = gpio_get_level(INPUT_PIN_2);        
        uint8_t sensor03 = gpio_get_level(INPUT_PIN_3);
        uint8_t sensor04 = gpio_get_level(INPUT_PIN_4);

        if(sensor01)
        {
            set_servo_angle(0); // Move to 0 degrees
            printf("Moving to 0 degrees\n");
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        else if(sensor02)
        {
            set_servo_angle(30); // Move to 30 degrees
            printf("Returning to 30 degrees\n");
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        else if(sensor03)
        {
            set_servo_angle(60); // Move to 60 degrees
            printf("Returning to 60 degrees\n");
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        else if(sensor04)
        {
            set_servo_angle(90); // Move to 90 degrees
            printf("Returning to 90 degrees\n");
            vTaskDelay(pdMS_TO_TICKS(500)); 
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}
