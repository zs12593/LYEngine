#ifndef LYENGINE_EVENTDISPATCHER_H
#define LYENGINE_EVENTDISPATCHER_H

#include "Event.h"

namespace ly {

class EventDispatcher {
public:
    static EventDispatcher *getInstance();

    static int dispatch(Event *event);

    static void removeEvent(int handle);

};

}


#endif //LYENGINE_EVENTDISPATCHER_H
