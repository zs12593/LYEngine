#ifndef LYENGINE_GAME_H
#define LYENGINE_GAME_H

namespace ly {

class Game {
public:
    static Game *getInstance();

    void run();

private:
    Game();

    ~Game();

};

}

#endif //LYENGINE_GAME_H
