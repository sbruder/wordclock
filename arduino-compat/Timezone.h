#ifndef TIMEZONE_H_INCLUDED
#define TIMEZONE_H_INCLUDED

#include <stdint.h>
#include <time.h>

enum week_t {Last, First, Second, Third, Fourth};
enum dow_t {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
enum month_t {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

struct TimeChangeRule {
    char abbrev[6];
    uint8_t week;
    uint8_t dow;
    uint8_t month;
    uint8_t hour;
    int offset;
};

class Timezone
{
    public:
        Timezone(TimeChangeRule dstStart, TimeChangeRule stdStart);
        time_t toLocal(time_t utc);
};
#endif
