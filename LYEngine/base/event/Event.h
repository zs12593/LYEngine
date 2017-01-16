#ifndef LYENGINE_EVENT_H
#define LYENGINE_EVENT_H

#include <string>
#include "../Value.h"

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
        TouchDown, TouchMove, TouchUp, TouchCancel, // TOUCH
    };

    const InputAction action;

    InputEvent(InputAction action) : Event(INPUT), action(action) { }
};

class TouchEvent : public InputEvent {
public:
    const int count;
    const int* ids;
    const float* x;
    const float* y;

    TouchEvent(InputAction action, int count, int ids[], float x[], float y[])
            : count(count), InputEvent(action), ids(ids), x(x), y(y) {
    }

    ~TouchEvent() {
        delete[] ids;
        delete[] x;
        delete[] y;
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

    Value *getValues() const { return _values; }

    int getValuesCount() { return count; }

    void setValues(Value *_vals, int count) {
        _values = _vals;
        this->count = count;
    }

private:
    Value *_values;
    int count;
};

}


#endif //LYENGINE_EVENT_H
