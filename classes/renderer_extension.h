//
// Created by Empezeeet on 03/11/2023.
//

#ifndef CLI_GAME_RENDERER_EXTENSION_H
#define CLI_GAME_RENDERER_EXTENSION_H

#include "../classes/renderer.h"
#include "../classes/WorldGenerator.h"
namespace clyde {
    clyde::object_list generate_entrances(worldGen::Room room) {
        clyde::object_list entrances = {};
        //TODO: this is shit. fix this (counter system)
        int counter=1;
        int counter2=1;
        for (int i=1; i<=4; i++) {


            // iterate over all 4 entrances
            // iterate over all 3 blocks of Entrance

            // 1. get direction of Entrance (horizontal or vertical) (we got always 2 of them)
            // 2. get center (if block cannot be centered get the closest block to center)
            // 3. set block -1 center and set block +1 center and set block center

            // Step 1.
            if (i%2==0) {
                // horizontal (upper and bottom sides)
                unsigned short center = ceil((double)room.width/2);
                entrances.push_back({center, counter==1 ? 1 : room.height, 'O'});
                entrances.push_back({center-1, counter==1 ? 1 : room.height, 'O'});
                entrances.push_back({center+1, counter==1 ? 1 : room.height, 'O'});
                counter++;
            } else {
                // vertical (left and right sides)
                unsigned short center = ceil((double)room.height/2);
                entrances.push_back({counter2==1 ? 1 : room.width,center, 'O'});
                entrances.push_back({counter2==1 ? 1 : room.width,center+1, 'O'});
                entrances.push_back({counter2==1 ? 1 : room.width,center-1, 'O'});
                counter2++;
            }




        }
        return entrances;
    }

}


#endif //CLI_GAME_RENDERER_EXTENSION_H
