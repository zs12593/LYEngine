#include "Game.h"
#include "event/EventManager.h"
#include <thread>

namespace ly {

Game *Game::getInstance() {
    static Game *instance;
    if (instance == nullptr)
        instance = new Game;
    return instance;
}

Game::Game() {
    _isRunning = false;
    _isPaused = false;
    _isExit = false;
    _isRendererPaused = false;
    _runningScene = nullptr;
    _deltaTime = -1;
}

Game::~Game() {
    delete (_runningScene);
}

void Game::run() {
    if (_isRunning) return;
    _isRunning = true;
    std::thread logic(&Game::logicLoop, this);
    logic.detach();
}

void Game::mainLoop() {
    if (_isRendererPaused || _isPaused) return;

    if (_runningScene)
        _runningScene->renderer(&_renderer);
    _renderer.renderer(_runningScene);
}

void Game::logicLoop() {
    while (_isExit) {
        if (_isPaused) continue;

        auto now = std::chrono::steady_clock::now();
        if (_deltaTime < 0)
            _deltaTime = 0;
        else
            _deltaTime =
                    std::chrono::duration_cast<std::chrono::microseconds>(now - _lastTime).count() /
                    1000000.0f;
        if (_runningScene) {
            EventManager::getInstance()->processInputEvent(_runningScene);
            _runningScene->update(_deltaTime);
        }
        _lastTime = now;
    }
}

void Game::pause() {
    _isPaused = true;
}

void Game::resume() {
    _isPaused = false;
}

void Game::setRunningScene(Scene *scene) {
    _runningScene = scene;
}

void Game::onBackground() {
    _isRendererPaused = true;
    if (_runningScene)
        _runningScene->onBackground();
}

void Game::onForeground() {
    if (_runningScene)
        _runningScene->onForeground();
    _isRendererPaused = false;
}

}






