# stm32.mk
HAL_PATH ?=
OUTPUT ?= .output

SRC_DIR = Src
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
	$(SRC_DIR)/stm32f7xx_hal_uart.c \
	$(SRC_DIR)/stm32f7xx_hal_usart.c \
	$(SRC_DIR)/stm32f7xx_hal_i2c.c \
	$(SRC_DIR)/stm32f7xx_hal_dma2d.c \
	$(SRC_DIR)/stm32f7xx_hal_dsi.c \
	$(SRC_DIR)/stm32f7xx_hal_ltdc.c \
	$(SRC_DIR)/stm32f7xx_hal_ltdc_ex.c \
	$(SRC_DIR)/stm32f7xx_hal_sdram.c

HAL_SRC += \
	$(SRC_DIR)/stm32f7xx_ll_fmc.c

HAL_INC += \
	$(HAL_PATH)/Inc \
	$(HAL_PATH)/Inc/Legacy \

DEFS += \
-DUSE_HAL_DRIVER \
-DSTM32F769xx

VPATH += :$(HAL_PATH)/Src

CFLAGS += $(HAL_DEF)
CFLAGS += $(addprefix -I, $(HAL_INC))

# export var
SRCS += $(HAL_SRC)
INCS += $(HAL_INC)
OBJS += $(addprefix $(OUTPUT)/,$(HAL_SRC:.c=.o))
