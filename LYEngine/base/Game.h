#ifndef LYENGINE_GAME_H
#define LYENGINE_GAME_H

#include <functional>
#include <chrono>
#include "node/Scene.h"
#include "renderer/Renderer.h"

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

    float getDeltaTime() const { return _deltaTime; }

private:
    Game();

    ~Game();

    void logicLoop();

    bool _isRunning;
    bool _isPaused;
    bool _isRendererPaused;
    bool _isExit;
    std::chrono::steady_clock::time_point _lastTime;
    float _deltaTime;
    Scene *_runningScene;
    Renderer _renderer;
};

}

#endif //LYENGINE_GAME_H
