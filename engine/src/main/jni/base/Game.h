#ifndef LYENGINE_GAME_H
#define LYENGINE_GAME_H

#include <assert.h>
#include <new>
#include <string>

using namespace std;

namespace ly {

    class Game {
    public:
        static Game *getInstance();

        void run();

        std::string getString();

    private:
        Game() { init(); };

        ~Game() { };

        void init();

    };

}
#endif //LYENGINE_GAME_H
