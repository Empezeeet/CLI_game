#include "classes/Player.h"
#include "classes/renderer.h"
#include "classes/WorldGenerator.h"
#include "classes/InputHandler.h"

#include <chrono>




int main() {
    // Renderer
    clyde::Renderer renderer(100, 60, clyde::FPS_30);
    clyde::object_list objects = {};
    std::chrono::milliseconds timespan(renderer.fps);

    //World Generation
    worldGen::WorldGenerator worldGenerator;
    // Spawn
    clyde::object_list obj2 = renderer.generate_shape(2,2,worldGenerator.getMap()[0].width-2,worldGenerator.getMap()[0].height-2, 'r', ' ');
    objects = renderer.generate_shape(1,1,worldGenerator.getMap()[0].width,worldGenerator.getMap()[0].height, 'r', 'X');
    objects.insert(objects.end(), obj2.begin(), obj2.end());
    // Player
    Player::Bounds bounds{};
    Player::Player player(100, {worldGenerator.getMap()[0].width, worldGenerator.getMap()[0].height, 2, 3});
    InputHandler inputHandler(&player);
    while(1) {

        clyde::Object player_obj {player.position.x, player.position.y, player.getSprite()};
        clyde::Object rem_last {player.prev_pos.x, player.prev_pos.y, ' '};
        objects.push_back(player_obj);
        objects.push_back(rem_last);
        // Input Handling
        if(inputHandler.handleInput())break;
        // Rendering. DO NOT MODIFY BELOW.
        renderer.prepare_frame(objects);
        renderer.render_frame();
        std::this_thread::sleep_for(timespan);
    }
    return 0;
}
