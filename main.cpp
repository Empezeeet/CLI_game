#include "classes/Player.h"
#include "classes/renderer.h"
#include "classes/WorldGenerator.h"

#include "headers/kbhit_alternative.h"
#include <chrono>
#include <thread>
#include <stdio.h>




int main() {
    // Renderer
    clyde::Renderer renderer(64, 32, clyde::FPS_30);
    clyde::object_list objects = {};
    std::chrono::milliseconds timespan(renderer.fps);
    // Player
    Player player(100);
    //World Generation
    worldGen::WorldGenerator worldGenerator;
    // Spawn
    clyde::object_list obj2 = renderer.generate_shape(2,2,worldGenerator.getMap()[0].width-2,worldGenerator.getMap()[0].height-2, 'r', ' ');
    objects = renderer.generate_shape(1,1,worldGenerator.getMap()[0].width,worldGenerator.getMap()[0].height, 'r', 'X');
    objects.insert(objects.end(), obj2.begin(), obj2.end());

    while(1) {


        clyde::Object player_obj {6, 6, player.getSprite()};
        objects.push_back(player_obj);
        if((bool)kbhit()) {
            char c = getchar();
            if (c == '+') break;
            player.setSprite(c);
            fseek(stdin,0,SEEK_END);
        }
        // Rendering. DO NOT MODIFY BELOW.
        renderer.prepare_frame(objects);
        renderer.render_frame();
        std::this_thread::sleep_for(timespan);
    }
    return 0;
}
