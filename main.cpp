#include "classes/player.h"
#include "classes/renderer.h"
#include "classes/InputHandler.h"

#include <thread>
#include <chrono>

int main() {

    clyde::Renderer renderer(64, 32, clyde::FPS_30);
    clyde::object_list objects = {};
    std::chrono::milliseconds timespan(renderer.fps);
    while(1) {

    }

    return 0;
}
