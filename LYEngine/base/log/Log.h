#ifndef LYENGINE_LOG_H
#define LYENGINE_LOG_H

#include <jni.h>
#include <asm/signal.h>

namespace ly {

class Log {
public:
    static void v(const char *fmt, ...);

    static void i(const char *fmt, ...);

    static void e(const char *fmt, ...);

    static void d(const char *fmt, ...);

    static void setTag(const char *tag);

    static void log(int prio, const char *tag, const char *fmt, ...);

private:
    static const char *_log(const char *fmt, va_list args);
};

}


#endif //LYENGINE_LOG_H
