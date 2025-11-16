/* TODO:
 * - double buffer
 * - start working on a graphics library
 * - marking regions dirty
 * - z layering
 * - maybe drop TFT_eSPI
 * - better sprite management
 */
#include "data/dvdlogo.h"
#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr_dvdlogo = TFT_eSprite(&tft);

void print_manifesto();

void setup(void)
{
    tft.init();
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(0);

    tft.setTextFont(1);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(CC_DATUM);
    tft.setTextWrap(true);

    spr_dvdlogo.createSprite(DVDLOGO_WIDTH, DVDLOGO_HEIGHT);
    spr_dvdlogo.pushImage(0, 0, DVDLOGO_WIDTH, DVDLOGO_HEIGHT, (uint16_t *)dvdlogo);
}

int x = 10;
int y = 0;
int dx = 2;
int dy = 2;
int interval = 40;

void loop()
{
    // print_manifesto();

    // no double buffer yet
    tft.fillRect(x - dx, y - dy, spr_dvdlogo.width(), spr_dvdlogo.height(),
                 TFT_BLACK);
    spr_dvdlogo.pushSprite(x, y);
    delay(interval);
    x += dx;
    y += dy;
    if (x < 0) {
        x = 0;
        dx = -dx;
    }
    if (x + spr_dvdlogo.width() > tft.width()) {
        x = tft.width() - spr_dvdlogo.width();
        dx = -dx;
    }
    if (y + spr_dvdlogo.height() > tft.height()) {
        y = tft.height() - spr_dvdlogo.height();
        dy = -dy;
    }
    if (y < 0) {
        y = 0;
        dy = -dy;
    }
}

void print_manifesto()
{
    tft.setCursor(0, tft.width() * 0.5);
    tft.println("The industrial");
    tft.println("revolution and it's");
    tft.println("consequences have");
    tft.println("been a disaster for");
    tft.println("the human race");
}
