# STM32 drivers makefile
#
DRV_PATH ?= Drivers

DRV_INC += \
	$(DRV_PATH)/CMSIS/Include \
	$(DRV_PATH)/CMSIS/Device/ST/STM32F7xx/Include
INCS += $(DRV_INC)

CFLAGS += $(addprefix -I, $(DRV_INC))

HAL_PATH = $(DRV_PATH)/STM32F7xx_HAL_Driver
include $(HAL_PATH)/stm32.mk
