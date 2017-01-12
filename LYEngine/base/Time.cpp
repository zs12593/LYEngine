#include "Time.h"

namespace ly {

double Time::getCurrentTime() {
    struct timespec clockRealTime;
    clock_gettime(CLOCK_MONOTONIC, &clockRealTime);
    double curTimeInSeconds = clockRealTime.tv_sec + (double) clockRealTime.tv_nsec / 1e9;
    return curTimeInSeconds;
}

}

