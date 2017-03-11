/**
 ******************************************************************************
 * @file    
 * @author  wind
 * @version
 * @date
 * @brief
 ******************************************************************************
 */

#ifndef __PLAT_HARDWARE_H
#define __PLAT_HARDWARE_H

#define ITERATIONS 12000

#define EE_TICKS_PER_SEC 1000

#define COMPILER_VERSION "IAR Embedded Workbench -ARM 7.80.4"
#define COMPILER_FLAGS "-Ohs -no_size_constraints"

#include "main.h"
#include "stm32f7xx_hal.h"
#include "usart.h"
#include "gpio.h"

#define PLAT_GETTIME() HAL_GetTick()

#define PRINTF_HUART huart3

void hardware_init(void);
void hardware_final(void);

#endif /*__PLAT_HARDWARE_H*/
