#include "Game.h"

namespace ly {
    static Game *s_Instance = nullptr;

    Game *Game::getInstance() {
        if (!s_Instance) {
            s_Instance = new(std::nothrow) Game;
            assert(s_Instance);
        }
        return s_Instance;
    }

    void Game::init() {
    }

    void Game::run() {
    }

    std::string Game::getString() {
        return "Hello";
    }


}
