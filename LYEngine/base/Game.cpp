#include "Game.h"

namespace ly {

Game *Game::getInstance() {
    static Game *instance;
    if (instance == nullptr)
        instance = new Game;
    return instance;
}

Game::Game() {

}

Game::~Game() {

}

void Game::run() {

}

}






