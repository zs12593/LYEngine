#ifndef LYENGINE_RENDERER_H
#define LYENGINE_RENDERER_H

#include "RendererCommand.h"
#include <mutex>
#include <vector>

namespace ly {

class Scene;

class Renderer {
public:
    void renderer(Scene *scene);

    void addRendererCommand(RendererCommand *command);

private:
    std::mutex _mutex;
    std::vector<RendererCommand *> _commands;
};

}


#endif //LYENGINE_RENDERER_H
