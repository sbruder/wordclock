#ifndef DISPLAY_DRIVER_DUMP_CLOCK_H
#define DISPLAY_DRIVER_DUMP_CLOCK_H

#include "IDisplayDriver.h"
#include "IAnimator.h"

class DisplayDriverDump : public IDisplayDriver
{
    public:
        void setup();

        virtual int width();
        virtual int height();

        virtual void setDots(uint8_t count, uint32_t color);

        virtual uint32_t getPixel(uint8_t x, uint8_t y);
        virtual void setPixel(uint8_t x, uint8_t y, uint32_t color);

        virtual void show();
};

#endif
