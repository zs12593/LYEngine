#ifndef LYENGINE_TEXTUREMANAGER_H
#define LYENGINE_TEXTUREMANAGER_H

#include "Texture.h"
#include <string>

namespace ly {

class TextureManager {
public:
    static Texture *loadTexture(std::string fiel);
};

}


#endif //LYENGINE_TEXTUREMANAGER_H
