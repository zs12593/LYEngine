#ifndef LYENGINE_EVENT_H
#define LYENGINE_EVENT_H

namespace ly {

enum EventType {
    InputEvent,

};

class Event {
public:
    EventType setEventType(EventType eventType) {
        _eventType = eventType;
    }

    EventType getEventType() {
        return _eventType;
    }

    void *getUserData() {
        return _userData;
    }

    void setUserData(void *userData) {
        _userData = userData;
    }

protected:
    EventType _eventType;
    void *_userData;
};

}


#endif //LYENGINE_EVENT_H
