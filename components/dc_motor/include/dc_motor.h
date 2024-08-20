#include <stdio.h>
#include "driver/ledc.h"

/*Define parameters ....*/


void setup_pwm(uint8_t ENA, uint8_t ENB);

void Forward(int speed);
void Right(int speed);
void Left(int speed);
void Backward(int speed);
void Stop();