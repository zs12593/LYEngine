#include "EventManager.h"

namespace ly {

EventManager *EventManager::getInstance() {
    static EventManager *instance;
    if (instance == nullptr)
        instance = new EventManager;
    return instance;
}

void EventManager::removeEventListener(EventListener *listener) {
    if (listener == nullptr) return;
    _mutex.lock();
    vector<EventListener *> lis = _allListener[listener->eventName];
    vector<EventListener *>::iterator iter;
    for (iter = lis.begin(); iter != lis.end(); iter++) {
        if (*iter == listener) {
            lis.erase(iter);
            break;
        }
    }
    _mutex.unlock();
}

void EventManager::addEventListener(EventListener *listener) {
    if (listener == nullptr) return;
    _mutex.lock();
    vector<EventListener *> lis = _allListener[listener->eventName];
    lis.push_back(listener);
    _mutex.unlock();
}

void EventManager::processCustomEvent(CustomEvent *event) {
    if (event == nullptr) return;

    vector<EventListener *> lis = _allListener[event->eventName];
    vector<EventListener *>::iterator iter;
    for (iter = lis.begin(); iter != lis.end(); iter++)
        (*iter)->onEvent(event);
    delete event;
}

void EventManager::processInputEvent(Scene *scene) {
    _mutex.lock();
    vector<InputEvent *> cloneEvents;
    cloneEvents.insert(cloneEvents.end(), _inputEvents.begin(), _inputEvents.end());
    _inputEvents.clear();
    _mutex.unlock();
    vector<InputEvent *>::iterator iter;
    while (iter != cloneEvents.end()) {
        InputEvent::InputAction action = (*iter)->action;
        if (action <= InputEvent::KeyUp) {
            scene->handleKeyEvent((KeyEvent *) (*iter));
        } else if (action >= InputEvent::TouchDown && action <= InputEvent::TouchCancel) {
            scene->handleTouchEvent((TouchEvent *) (*iter));
        }
        delete (*iter);
        iter = cloneEvents.begin();
    }
}

void EventManager::addInputEvent(InputEvent *event) {
    _mutex.lock();
    if (event)
        _inputEvents.push_back(event);
    _mutex.unlock();
}


}



