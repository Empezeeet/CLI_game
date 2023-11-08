//
// Created by Empezeeet on 03/11/2023.
//

#ifndef CLI_GAME_WORLDGENERATOR_H
#define CLI_GAME_WORLDGENERATOR_H

#include <array>
#include <ctime>
#include <vector>

#include "../classes/Vector2D.h"

namespace worldGen {
    struct Entrance {
        short side; // needed when generating new Room.
	    unsigned short x;
	    unsigned short y;
        // there are always 4 entrances, at every side, centered.
        bool locked; // do PlayerN need key to cross it?
        unsigned short id; // used to connect to enterance so PlayerN can walk between rooms.
    };

    struct Room {
        unsigned short width;
        unsigned short height;
        short type;
        unsigned int id;
        std::array<Entrance,4> entrances;
        // all rooms have 4 enterances but some enterances can be disabled or locked.

    };


    class WorldGenerator {
    private:
        std::vector<Room> map;
        unsigned short max_width;
        unsigned short max_height;

    public:

        WorldGenerator(unsigned short max_width, unsigned short max_height) : max_height(max_height), max_width(max_width) {
            std::srand(time(nullptr));
            // 1. generate start Room.
            // 2. when PlayerN tries to cross Entrance generate new but save previous.
            //  this way every Room is always connected (no softlock)

            // 1. generates spawn Room.
            generateRoom(rand()%10000+10000, 1, this->max_width-2, this->max_height-2, 0);
        }
		/**
		 *
		 * @param roomID
		 * @return Room with matching ID
		 */
		Room getRoomByID(unsigned int roomID) {
			for (Room room : this->map) {
				if (room.id == roomID) return room;
			}
		}
        /**
         * Returns map
         * @return vector<Room>
         */
        std::vector<Room> getMap() {
            return this->map;
        }
		/**
		 * Returns Entrances found by side
		 * @param side. side of Entrance.
		 * @param roomID. ID of room
		 * @return found Entrance
		 */
		Entrance getEntranceBySide(short side, unsigned int roomID) {
			for (Entrance enter: this->getRoomByID(roomID).entrances) {
				if (enter.side == side) return enter;
			}

		}
		short getSideFromPos(Vector2D entrancePos, unsigned int roomID) {
			Room room = this->getRoomByID(roomID);
			// check direciton
			if (entrancePos.x == room.width) {
				// right
				return 3;
			} else if (entrancePos.y == room.height) {
				// bottom
				return 4;
			} else if (entrancePos.x == 2) {
				//left
				return 1;
			} else if (entrancePos.y == 2) {
				// top
				return 2;
			}
		}
        /**
         * Generates Room at appends it into map vector.
         * @param enterid id of used Entrance
         * @param side side of used Entrance
         * @param w OPTIONAL width of Room else random
         * @param h OPTIONAL height of Room else random
         * @param roomID OPTIONAL ID of Room else random.
         */
        unsigned int generateRoom(unsigned short enterid,short side,unsigned short w=0,unsigned short h=0,int roomID=-1) {
            // If width, height or roomID not specified generate random.
			if (w == 0) w = rand() % 54+20;
            if (h == 0) h = rand() % 50+3; // Due to 1h >1W height must be smaller than width
            if (roomID==-1) roomID = rand()%10000+10000; // 5 digit number
            short randSide;
			// Entrance ID
            unsigned short randEID;
            std::array<Entrance, 4> entrances;
            entrances[0] = {side, false, enterid};
			// max 3 because above we specified first
            for (short i=1; i<4; i++) {
                do {
                    randSide = i+1;
                    randEID = rand()%10000+10000; // 5 digit number
                } while (side==randSide || randEID == enterid);
                entrances[i] = Entrance{randSide, false, randEID};
            }
            this->map.push_back({
                w,
                h,
                1, // default type
                (unsigned int)roomID,
                entrances
            });
			return roomID;
        }
    };
}



#endif //CLI_GAME_WORLDGENERATOR_H
