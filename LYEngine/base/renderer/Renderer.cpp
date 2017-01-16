#include "Renderer.h"

namespace ly {

void Renderer::renderer(Scene *scene) {

}

void Renderer::addRendererCommand(RendererCommand *command) {
    _commands.push_back(command);
}


}


