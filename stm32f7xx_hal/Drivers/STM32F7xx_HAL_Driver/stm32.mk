# .PHONY: all clean
HAL_PATH ?=
OUTPUT ?= .output
SRC_DIR = $(HAL_PATH)/Src
HAL_SRC = \
	$(SRC_DIR)/stm32f7xx_hal_cortex.c \
	$(SRC_DIR)/stm32f7xx_hal.c \
	$(SRC_DIR)/stm32f7xx_hal_rcc_ex.c \
	$(SRC_DIR)/stm32f7xx_hal_flash.c \
	$(SRC_DIR)/stm32f7xx_hal_dma_ex.c \
	$(SRC_DIR)/stm32f7xx_hal_rcc.c \
	$(SRC_DIR)/stm32f7xx_hal_i2c_ex.c \
	$(SRC_DIR)/stm32f7xx_hal_tim_ex.c \
	$(SRC_DIR)/stm32f7xx_hal_pwr_ex.c \
	$(SRC_DIR)/stm32f7xx_hal_pwr.c \
	$(SRC_DIR)/stm32f7xx_hal_dma.c \
	$(SRC_DIR)/stm32f7xx_hal_flash_ex.c \
	$(SRC_DIR)/stm32f7xx_hal_tim.c \
	$(SRC_DIR)/stm32f7xx_hal_gpio.c \
	$(SRC_DIR)/stm32f7xx_hal_i2c.c

HAL_INC += \
	$(HAL_PATH)/Inc \
	$(HAL_PATH)/Inc/Legacy \

DEFS += \
-DUSE_HAL_DRIVER \
-DSTM32F769xx

SRCS += $(HAL_SRC)
INCS += $(HAL_INC)
OBJS += $(addprefix $(OUTPUT)/,$(HAL_SRC:.c=.o))

CFLAGS += $(HAL_DEF)
CFLAGS += $(addprefix -I, $(HAL_INC))