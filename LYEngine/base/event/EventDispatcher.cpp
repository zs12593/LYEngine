#include "EventDispatcher.h"
#include <vector>
#include "EventManager.h"

namespace ly {

EventDispatcher *EventDispatcher::getInstance() {
    static EventDispatcher *instance;
    if (instance == nullptr)
        instance = new EventDispatcher;
    return instance;
}

int EventDispatcher::dispatch(Event *event) {
    if (event->isInputEvent()) {
        EventManager::getInstance()->addInputEvent(static_cast<InputEvent *>(event));
    } else if (event->isCustomEvent()) {
        EventManager::getInstance()->processCustomEvent(static_cast<CustomEvent *>(event));
    }
}

EventListener *EventDispatcher::registerEventListener(std::string eventName,
                                                      std::function<void()> func,
                                                      int priority) {
    EventListener *listener = new EventListener(eventName, func, priority);
    EventManager::getInstance()->addEventListener(listener);
    return nullptr;
}

void EventDispatcher::unRegisterEventListener(EventListener *listener) {
    EventManager::getInstance()->removeEventListener(listener);
}


}

