/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN_R = 14;
const int BTN = 17;
const int MOTOR_A  = 21;
const int MOTOR_B  = 20;
const int MOTOR_C  = 19;
const int MOTOR_D  = 18;

int main() {
  stdio_init_all();
  int vezes_virar = 360/0.176;

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

  gpio_init(MOTOR_A);
  gpio_set_dir(MOTOR_A, GPIO_OUT);
  gpio_init(MOTOR_B);
  gpio_set_dir(MOTOR_B, GPIO_OUT);
  gpio_init(MOTOR_C);
  gpio_set_dir(MOTOR_C, GPIO_OUT);
  gpio_init(MOTOR_D);
  gpio_set_dir(MOTOR_D, GPIO_OUT);

  while (true) {
    if(!gpio_get(BTN)){
        gpio_put(LED_PIN_R, 1);
        for (int i = 0;i<vezes_virar/4;i++){
          gpio_put(MOTOR_A, 1);
          busy_wait_ms(10);
          gpio_put(MOTOR_A, 0);
          gpio_put(MOTOR_B, 1);
          busy_wait_ms(10);
          gpio_put(MOTOR_B, 0);
          gpio_put(MOTOR_C, 1);
          busy_wait_ms(10);
          gpio_put(MOTOR_C, 0);
          gpio_put(MOTOR_D, 1);
          busy_wait_ms(10);
          gpio_put(MOTOR_D, 0);
          printf("Esta girando \n");
        } 
        gpio_put(LED_PIN_R, 0);
        while (!gpio_get(BTN)){
      }
      printf("vezes_virar: %d\n", vezes_virar);
      printf("vezes entra no for %d\n", vezes_virar/4);
    }
  }
}
