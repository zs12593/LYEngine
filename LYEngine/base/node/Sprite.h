#ifndef LYENGINE_SPRITE_H
#define LYENGINE_SPRITE_H

#include <base/texture/Texture.h>
#include "Node.h"

namespace ly {

class Sprite : public Node {
public:
    Sprite();

    Sprite(std::string file);

    virtual void renderer(Renderer *renderer);

    Texture *getTexture() { return _texture; }

private:
    void init();

    Texture *_texture;
};

}

#endif //LYENGINE_SPRITE_H
