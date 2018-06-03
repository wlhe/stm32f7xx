.PHONY: all clean

TARGET = linux_fb
OUTPUT = .output

CC = gcc
LD = gcc

# drivers
LVGL_DIR = ..
include $(LVGL_DIR)/example.mk
include $(LVGL_DIR)/lvgl.mk
include $(LVGL_DIR)/lv_drivers/display/display.mk
include $(LVGL_DIR)/lv_drivers/indev/indev.mk
VPATH += $(LVGL_DIR)/lv_drivers/display
VPATH += $(LVGL_DIR)/lv_drivers/indev

CFLAGS += -std=gnu99

CSRCS += \
	main.c

OBJS = $(addprefix $(OUTPUT)/,$(notdir $(CSRCS:.c=.o)))

$(OUTPUT)/%.o: %.c Makefile | $(OUTPUT)
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo CC $< $@

$(TARGET) : $(OBJS)
	@$(LD) $(OBJS) $(LDFLAGS) -o $@

$(OUTPUT):
	@echo make dir
	mkdir -p ./.output

all: $(TARGET)

clean:
	rm -f $(TARGET)
	rm -rf $(OUTPUT)