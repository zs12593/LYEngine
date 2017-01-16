#ifndef LYENGINE_EVENTDISPATCHER_H
#define LYENGINE_EVENTDISPATCHER_H

#include "Event.h"
#include "EventListener.h"
#include <functional>

namespace ly {

class EventDispatcher {
public:
    static EventDispatcher *getInstance();

    static int dispatch(Event *event);

    static EventListener *registerEventListener(std::string eventName, std::function<void(Event *)> func,
                                                int priority = 0);

    static void unRegisterEventListener(EventListener *listener);

};

}


#endif //LYENGINE_EVENTDISPATCHER_H
