#include "EventDispatcher.h"

namespace ly {

EventDispatcher *EventDispatcher::getInstance() {
    static EventDispatcher *instance;
    if (instance == nullptr)
        instance = new EventDispatcher;

    return instance;
}

int EventDispatcher::dispatch(Event *event) {

}

void EventDispatcher::removeEvent(int handle) {

}


}

