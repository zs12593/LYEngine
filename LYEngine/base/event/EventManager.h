#ifndef LYENGINE_EVENTMANAGER_H
#define LYENGINE_EVENTMANAGER_H

#include <vector>
#include <mutex>
#include <unordered_map>
#include "EventListener.h"
#include "../node/Scene.h"

using namespace std;

namespace ly {

class EventManager {
public:
    static EventManager *getInstance();

    void addEventListener(EventListener *listener);

    void removeEventListener(EventListener *listener);

    void processCustomEvent(CustomEvent *event);

    void processInputEvent(Scene *scene);

    void addInputEvent(InputEvent *event);

private:
    mutex _mutex;
    unordered_map<string, vector<EventListener *>> _allListener;
    vector<InputEvent *> _inputEvents;
};

}


#endif //LYENGINE_EVENTMANAGER_H
