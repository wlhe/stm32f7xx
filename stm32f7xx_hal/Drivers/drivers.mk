# STM32 drivers makefile
#
DRV_PATH ?= Drivers

DRV_SRC += \

DRV_INC += \
	$(DRV_PATH)/CMSIS/Include \
	$(DRV_PATH)/CMSIS/Device/ST/STM32F7xx/Include \

CFLAGS += $(addprefix -I, $(DRV_INC))

# var
INCS += $(DRV_INC)
SRCS += $(DRV_SRC)

HAL_PATH = $(DRV_PATH)/STM32F7xx_HAL_Driver
include $(HAL_PATH)/stm32.mk

BSP_PATH = $(DRV_PATH)/BSP
include $(BSP_PATH)/bsp.mk
