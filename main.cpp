#include "classes/Player.h"
#include "classes/renderer.h"
#include "classes/WorldGenerator.h"
#include "classes/InputHandler.h"


#include "classes/renderer_extension.h"
#include <chrono>




int main() {
    // Renderer
    clyde::Renderer renderer(100, 60, clyde::FPS_30);
    clyde::object_list objects = {};
    std::chrono::milliseconds timespan(renderer.fps);

    //World Generation
    worldGen::WorldGenerator worldGenerator(renderer.width, renderer.height);
    // Spawn
    clyde::object_list obj2 = renderer.generate_shape(2,2,worldGenerator.getMap()[0].width-2,worldGenerator.getMap()[0].height-2, 'r', ' ');
    objects = renderer.generate_shape(1,1,worldGenerator.getMap()[0].width,worldGenerator.getMap()[0].height, 'r', 'X');
    objects.insert(objects.end(), obj2.begin(), obj2.end());
	unsigned int roomID = 0;


    // PlayerN
    PlayerN::Bounds bounds {worldGenerator.getMap()[0].width, worldGenerator.getMap()[0].height, 2, 3};
    PlayerN::Player player(
            100,
            bounds,
			&worldGenerator
            );
    // Generate entrances
    clyde::object_list entr = clyde::generate_entrances(worldGenerator.getMap()[0]);
    objects.insert(objects.end(), entr.begin(), entr.end());

    //                     {top}, {bot}, {left}, {right}
    std::array<worldGen::Entrance, 4> newEntrances = {{
		    {2,(unsigned short)ceil((double)worldGenerator.getMap()[0].width/2), 2},
		    {4,(unsigned short)ceil((double)worldGenerator.getMap()[0].width/2), (unsigned short)worldGenerator.getMap()[0].height},
		    {1,2,(unsigned short)ceil((double)worldGenerator.getMap()[0].height/2)},
		    {3,(unsigned short)worldGenerator.getMap()[0].width,(unsigned short)ceil((double)worldGenerator.getMap()[0].height/2)},
	}};
	player.changeEntrances(newEntrances);

    InputHandler inputHandler(&player);
	// Generate text that idicates spawn
	clyde::object_list text = renderer.generate_text(4, 2, "Hello World!");
	objects.insert(objects.end(), text.begin(), text.end());

    while(true) {
		// check is player in new room
		if (roomID != player.getRoomID()) {
			// Player entered new room.
			worldGen::Room newRoom = worldGenerator.getRoomByID(player.getRoomID());
			obj2 = renderer.generate_shape(2,2,newRoom.width-2,newRoom.height-2, 'r', ' ');
			objects = renderer.generate_shape(1,1,newRoom.width,newRoom.height, 'r', 'X');
			objects.insert(objects.end(), obj2.begin(), obj2.end());
			bounds = {
					newRoom.width,
					newRoom.height,
					2,
					3
			};
			player.setBounds(bounds);
			// Render Entrances and update
			newEntrances = {{
					                {2,(unsigned short)ceil((double)newRoom.width/2), 2},
					                {4,(unsigned short)ceil((double)newRoom.width/2), (unsigned short)newRoom.height},
					                {1,2,(unsigned short)ceil((double)newRoom.height/2)},
					                {3,(unsigned short)newRoom.width,(unsigned short)ceil((double)newRoom.height/2)},
			                }};
			player.changeEntrances(newEntrances);
			entr = clyde::generate_entrances(newRoom);
			objects.insert(objects.end(), entr.begin(), entr.end());

		}



        // player sprite rendering.
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
