#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__

#ifdef _WIN32
/* Windows */
#include "gettimeofday.h"
#else
/* Linux */
#include <sys/time.h>
#endif

enum stopwatch_unit { sec=0, msec, usec };

class stopwatch_t {
public:
    stopwatch_t();
    virtual ~stopwatch_t();

    void start();
    void stop();
    void reset();
    void display(stopwatch_unit m_stopwatch_unit = msec);

protected:
    double elapsed_time;
    timeval start_time;
    timeval end_time;
};

#endif
