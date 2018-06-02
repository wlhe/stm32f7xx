/* gui_lvgl.c
 * Implement
 * https://github.com/littlevgl/lv_examples/tree/master/lv_tutorial/0_porting
*/
#include "stm32f769i_discovery.h"
#include "stm32f769i_discovery_lcd.h"
#include "stm32f769i_discovery_ts.h"
#include "otm8009a.h"
#include "lvgl/lvgl.h"
#include "demo.h"

#define LCD_HOR_RES LV_HOR_RES
#define LCD_VER_RES LV_VER_RES
#define POS_CHECK(x1, y1, x2, y2)   \
    do { \
        if ((x2) < 0 || (y2) < 0 || \
            (x1) > LCD_HOR_RES - 1 || (y1) > LCD_VER_RES - 1) return; \
        if ((x1) < 0) (x1) = 0; \
        if ((y1) < 0) (y1) = 0; \
        if ((x2) > LCD_HOR_RES - 1) (x2) = LCD_HOR_RES - 1; \
        if ((y2) > LCD_VER_RES - 1) (y2) = LCD_VER_RES - 1; \
    } while (0);

static void ex_disp_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/
    POS_CHECK(x1, y1, x2, y2);

    int32_t x;
    int32_t y;
    for(y = y1; y <= y2; y++) {
        for(x = x1; x <= x2; x++) {
            /* Put a pixel to the display. For example: */
            /* put_px(x, y, *color_p)*/
            BSP_LCD_DrawPixel(x, y,  ((color_p->full) | 0xFF000000));
            color_p++;
        }
    }

    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_flush_ready();
}

/* Write a pixel array (called 'map') to the a specific area on the display
 * This function is required only when LV_VDB_SIZE == 0 in lv_conf.h*/
static void ex_disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/
    POS_CHECK(x1, y1, x2, y2);

    int32_t x;
    int32_t y;
    for(y = y1; y <= y2; y++) {
        for(x = x1; x <= x2; x++) {
            /* Put a pixel to the display. For example: */
            /* put_px(x, y, *color_p)*/
            BSP_LCD_DrawPixel(x, y,  ((color_p->full) | 0xFF000000));
            color_p++;
        }
    }
}

/* Write a pixel array (called 'map') to the a specific area on the display
 * This function is required only when LV_VDB_SIZE == 0 in lv_conf.h*/
static void ex_disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2,  lv_color_t color)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/
    POS_CHECK(x1, y1, x2, y2);

    uint32_t old = BSP_LCD_GetTextColor();
    BSP_LCD_SetTextColor(color.full | 0xFF000000);
    BSP_LCD_FillRect(x1, y1, x2 - x1 + 1, y2 - y1 + 1);
    BSP_LCD_SetTextColor(old);
}

/* Read the touchpad and store it in 'data'
 * REaturn false if no more data read; true for ready again */
static bool ex_tp_read(lv_indev_data_t *data)
{
    /* Read your touchpad */
    /* data->state = LV_INDEV_STATE_REL or LV_INDEV_STATE_PR */
    /* data->point.x = tp_x; */
    /* data->point.y = tp_y; */
    static int16_t last_x = 0;
    static int16_t last_y = 0;

    static TS_StateTypeDef  TS_State;
    BSP_TS_GetState(&TS_State);
    if(TS_State.touchDetected != 0) {
        data->point.x = TS_State.touchX[0];
        data->point.y = TS_State.touchY[0];
        last_x = data->point.x;
        last_y = data->point.y;
        data->state = LV_INDEV_STATE_PR;
    } else {
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_REL;
    }

    return false;   /*false: no more data to read because we are no buffering*/
}

// Call lv_task_handler(); in loop
// Call lv_tick_inc(1); in 1 ms interrupt (usually systick)
void HAL_SYSTICK_Callback(void)
{
    lv_tick_inc(1);
}

static void bsp_init(void)
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_TS_Init(OTM8009A_800X480_WIDTH, OTM8009A_800X480_HEIGHT);
}

void lvgl_init(void)
{
    bsp_init();

    lv_init();

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    disp_drv.disp_flush = ex_disp_flush;
    disp_drv.disp_fill = ex_disp_fill;
    disp_drv.disp_map = ex_disp_map;

    lv_disp_drv_register(&disp_drv);

    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = ex_tp_read;
    lv_indev_drv_register(&indev_drv);

}

void lvgl_run(void)
{
    demo_create();
}
