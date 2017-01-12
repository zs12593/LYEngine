#include "Game.h"
#include "event/EventManager.h"
#include "Time.h"
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
    _lastTime = Time::getCurrentTime();
}

Game::~Game() {
}

void Game::run() {
    if (_isRunning) return;
    _isRunning = true;
    std::thread logic(logicLoop);
    logic.detach();
}

void Game::mainLoop() {
    if (_isRendererPaused || _isPaused) return;

}

void Game::logicLoop() {
    while (_isExit) {
        if (_isPaused) continue;

        double time = Time::getCurrentTime();
        if (_runningScene) {
            EventManager::getInstance()->processInputEvent(_runningScene);
            _runningScene->update((float) (time - _lastTime));
        }
        _lastTime = time;
    }
}

void Game::pause() {
    _isPaused = true;
}

void Game::resume() {
    _isPaused = false;
}

void Game::setRunningScene(Scene *scene) {

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






