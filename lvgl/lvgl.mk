# lvgl.mk
LVGL_DIR ?= .

include $(LVGL_DIR)/lvgl/lv_core/lv_core.mk
include $(LVGL_DIR)/lvgl/lv_hal/lv_hal.mk
include $(LVGL_DIR)/lvgl/lv_objx/lv_objx.mk
include $(LVGL_DIR)/lvgl/lv_misc/lv_fonts/lv_fonts.mk
include $(LVGL_DIR)/lvgl/lv_misc/lv_misc.mk
include $(LVGL_DIR)/lvgl/lv_themes/lv_themes.mk
include $(LVGL_DIR)/lvgl/lv_draw/lv_draw.mk

VPATH += \
	$(LVGL_DIR)/lvgl/lv_core \
	$(LVGL_DIR)/lvgl/lv_hal \
	$(LVGL_DIR)/lvgl/lv_objx \
	$(LVGL_DIR)/lvgl/lv_misc \
	$(LVGL_DIR)/lvgl/lv_misc/lv_fonts \
	$(LVGL_DIR)/lvgl/lv_themes \
	$(LVGL_DIR)/lvgl/lv_draw

SRCS += $(CSRCS)

CFLAGS += -I$(LVGL_DIR)

# demo

include $(LVGL_DIR)/lv_examples/lv_apps/demo/demo.mk
VPATH += $(LVGL_DIR)/lv_examples/lv_apps/demo