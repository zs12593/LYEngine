#include "Sprite.h"

namespace ly {

Sprite::Sprite() {
    init();
}

Sprite::Sprite(std::string file) {
    init();
}

void Sprite::init() {

}

void Sprite::renderer(Renderer *renderer) {

    Node::renderer(renderer);
}

}
