// 1.3" TFT Display (M130T)
// no CS pin
// 240x240, ST7789
// tft_setup.h

#ifndef __TFT_SETUP_H__
#define __TFT_SETUP_H__

#define USER_SETUP_LOADED 1
#define ST7789_DRIVER

#define TFT_WIDTH  240
#define TFT_HEIGHT 240

#define TFT_RGB_ORDER TFT_BGR

#define TFT_CS           -1
#define TFT_RST          17
#define TFT_DC           15
#define TFT_MOSI         23 // SDA
#define TFT_SCLK         18  // SCL
#define TFT_MISO         19
#define TFT_BL           22 // LED back-light
#define TFT_BACKLIGHT_ON HIGH

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

#define SPI_FREQUENCY       27000000
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY 2500000

#endif // __TFT_SETUP_H__
