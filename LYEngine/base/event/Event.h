#ifndef LYENGINE_EVENT_H
#define LYENGINE_EVENT_H

#include <string>
#include "../node/Node.h"

namespace ly {

class Event {
public:
    enum EventType {
        INPUT,
        CUSTOM,
    };

    const EventType eventType;

    Event(EventType type) : eventType(type) { }

    bool isInputEvent() { return eventType == INPUT; };

    bool isCustomEvent() { return eventType == CUSTOM; };

    void *getUserData() { return _userData; }

    void setUserData(void *userData) { _userData = userData; }

protected:
    void *_userData;
};

class InputEvent : public Event {
public:
    enum InputAction {
        KeyDown, KeyUp, // KEY
        TouchDown, TouchUp, TouchCancel, // TOUCH
    };

    const InputAction action;

    InputEvent(InputAction action) : Event(INPUT), action(action) { }

    void setHandledNode(InputEventNode *node) { _handledNode = node; }

    InputEventNode *getHandledNode() { return _handledNode; }

private:
    InputEventNode *_handledNode;
};

class TouchEvent : public InputEvent {
public:
    const int ids[];
    const float x[];
    const float y[];

    TouchEvent(InputAction action, int ids[], float x[], float y[])
            : InputEvent(action), ids(ids), x(x), y(y) {
    }
};

class KeyEvent : public InputEvent {
public:
    const int keyCode;

    KeyEvent(InputAction action, int keyCode) : InputEvent(action), keyCode(keyCode) { }
};

class CustomEvent : public Event {
public:
    const std::string eventName;

    CustomEvent(std::string eventName) : Event(CUSTOM), eventName(eventName) { }
};

}


#endif //LYENGINE_EVENT_H
