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

#include "time.h"

#define ITERATIONS 12000

#define EE_TICKS_PER_SEC 1000

#define COMPILER_VERSION "IAR Embedded Workbench -ARM 7.80.2"
#define COMPILER_FLAGS  "-Ohs -no_size_constraints"

#include "main.h"
#include "stm32f7xx_hal.h"
#include "usart.h"
#include "gpio.h"

#define PRINTF_HUART    huart1

void hardware_init(void);




#endif/*__PLAT_HARDWARE_H*/