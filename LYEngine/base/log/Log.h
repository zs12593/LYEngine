#ifndef LYENGINE_LOG_H
#define LYENGINE_LOG_H

#include <jni.h>
#include <android/log.h>

namespace ly {

class Log {
public:
    static void v(const char *fmt, ...);

    static void i(const char *fmt, ...);

    static void e(const char *fmt, ...);

    static void d(const char *fmt, ...);

};

}


#endif //LYENGINE_LOG_H
