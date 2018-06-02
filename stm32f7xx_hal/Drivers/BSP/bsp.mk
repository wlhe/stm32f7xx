# bsp.mk

BSP_PATH ?= .
OUTPUT ?= .output

DISC_DIR = STM32F769I-Discovery
BSP_SRC += \
	$(DISC_DIR)/stm32f769i_discovery.c \
	$(DISC_DIR)/stm32f769i_discovery_lcd.c \
	$(DISC_DIR)/stm32f769i_discovery_sdram.c \
	$(DISC_DIR)/stm32f769i_discovery_ts.c

BSP_SRC += \
	Components/otm8009a/otm8009a.c \
	Components/ft6x06/ft6x06.c

BSP_INC = \
	$(BSP_PATH)/$(DISC_DIR) \
	$(BSP_PATH)/Components/otm8009a \
	$(BSP_PATH)/Components/ft6x06

VPATH += \
	:$(BSP_PATH)/STM32F769I-Discovery \
	:$(BSP_PATH)/Components/otm8009a \
	:$(BSP_PATH)/Components/ft6x06


CFLAGS += $(addprefix -I, $(BSP_INC))

# export var
INCS += $(BSP_INC)
SRCS += $(BSP_SRC)
OBJS += $(addprefix $(OUTPUT)/,$(BSP_SRC:.c=.o))