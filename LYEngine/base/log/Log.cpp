#include "Log.h"

#define  LOG_TAG    "LYEngine"

namespace ly {

void Log::i(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, vl);
    va_end(vl);
}

void Log::v(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, fmt, vl);
    va_end(vl);
}

void Log::e(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, vl);
    va_end(vl);
}

void Log::d(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, vl);
    va_end(vl);
}

}