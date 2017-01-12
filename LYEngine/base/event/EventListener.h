#ifndef LYENGINE_EVENTLISTENER_H
#define LYENGINE_EVENTLISTENER_H

#include <functional>
#include <string>
#include "Event.h"

namespace ly {

class EventListener {
public:
    const std::string eventName;

    EventListener(std::string name, std::function<void(Event *)> callback, int priority) :
            eventName(name), _priority(priority), _callback(callback) { }

    void setPriority(int priority) {
        _priority = priority;
    }

    int getPriority() {
        return _priority;
    }

    void onEvent(Event *event) {
        if (_callback)
            _callback(event);
    }

private:
    int _priority;
    std::function<void(Event *)> _callback;
};

}


#endif //LYENGINE_EVENTLISTENER_H
