#ifndef LYENGINE_GAME_H
#define LYENGINE_GAME_H

#include <functional>
#include "node/Scene.h"

namespace ly {

class Game {
public:
    static Game *getInstance();

    void run();

    void exit() { _isExit = true; }

    void pause();

    void resume();

    void onBackground();

    void onForeground();

    void mainLoop();

    void setRunningScene(Scene *scene);

    Scene *getRunningScene() { return _runningScene; }

private:
    Game();

    ~Game();

    void logicLoop();

    bool _isRunning;
    bool _isPaused;
    bool _isRendererPaused;
    bool _isExit;
    double _lastTime;
    Scene *_runningScene;
};

}

#endif //LYENGINE_GAME_H
