//
// Created by Mateusz Pawełko on 03/11/2023.
//

#ifndef CLI_GAME_WORLDGENERATOR_H
#define CLI_GAME_WORLDGENERATOR_H

#include <array>
#include <ctime>
namespace worldGen {
    struct entrance {
        short side; // needed when generating new room.
        // there are always 4 entrances, at every side, centered.
        bool locked; // do Player need key to cross it?
        unsigned short id; // used to connect to enterance so Player can walk between rooms.
    };

    struct room {
        unsigned short width;
        unsigned short height;
        short type;
        unsigned int id;
        std::array<entrance,4> entrances;
        // all rooms have 4 enterances but some enterances can be disabled or locked.

    };


    class WorldGenerator {
    private:
        std::vector<room> map;

    public:

        WorldGenerator() {
            std::srand(time(nullptr));
            // 1. generate start room.
            // 2. when Player tries to cross entrance generate new but save previous.
            //  this way every room is always connected (no softlock)
            generateRoom(rand()%10000+10000, 1, 15, 15);
        }
        /**
         * Returns map
         * @return vector<room>
         */
        std::vector<room> getMap() {
            return this->map;
        }
        /**
         * Generates room at appends it into map vector.
         * @param enterid id of used entrance
         * @param side side of used entrance
         * @param w OPTIONAL width of room else random
         * @param h OPTIONAL height of room else random
         */
        void generateRoom(unsigned short enterid,short side,unsigned short w=0,unsigned short h=0 ) {
            if (w == 0) w = rand() % 54+4;
            if (h==0) h = rand() % 54+4;
            unsigned int id = rand()%10000+10000; // 5 digit number
            short randSide;
            unsigned short randEID;
            std::array<entrance, 4> entrances;
            entrances[0] = {side, false, enterid};
            for (short i=1; i<4; i++) {
                do {
                    randSide = rand()%5+1;
                    randEID = rand()%10000+10000;
                } while (side==randSide || randEID == enterid);
                entrances[i] = entrance{randSide, false, randEID};
            }
            this->map.push_back({
                w,
                h,
                1, // default type
                id,
                entrances
            });
        }
    };
}



#endif //CLI_GAME_WORLDGENERATOR_H
