#include "Log.h"
#include <new>
#include <sstream>
#include <android/log.h>

namespace ly {

static const int MAX_LOG_LENGTH = 16 * 1024;
static std::string sLogTag = "LYEngine";

void Log::setTag(const char *tag) {
    if (tag != nullptr)
        sLogTag = tag;
}


void Log::i(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    __android_log_print(ANDROID_LOG_INFO, sLogTag.c_str(), fmt, vl);
    va_end(vl);
}

void Log::v(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    __android_log_print(ANDROID_LOG_VERBOSE, sLogTag.c_str(), fmt, vl);
    va_end(vl);
}

void Log::e(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    __android_log_print(ANDROID_LOG_ERROR, sLogTag.c_str(), fmt, vl);
    va_end(vl);
}

void Log::d(const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    const char *text = _log(fmt, vl);
    __android_log_print(ANDROID_LOG_DEBUG, sLogTag.c_str(), "%s", text);
    delete[] text;
    va_end(vl);
}

void Log::log(int prio, const char *tag, const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    const char *text = _log(fmt, vl);
    __android_log_print(prio, tag, "%s", text);
    delete[] text;
    va_end(vl);
}

const char *Log::_log(const char *fmt, va_list args) {
    size_t bufSize = MAX_LOG_LENGTH;
    char *buf = nullptr;
    while (1) {
        buf = new(std::nothrow) char[bufSize];
        if (buf == nullptr) return "";
        int ret = vsnprintf(buf, bufSize - 3, fmt, args);
        if (ret < 0) {
            bufSize *= 2;
            delete[] buf;
        } else
            break;
    }
    return buf;
}

}

