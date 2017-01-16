#include "FirstScene.h"

void gameEnter() {
    ly::Game::getInstance()->getInstance()->setRunningScene(new FirstScene());
}
