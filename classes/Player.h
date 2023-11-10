//
// Created by Empezeeet on 03/11/2023.
//

#ifndef CLI_GAME_PLAYER_H
#define CLI_GAME_PLAYER_H

#include <array>
#include "../classes/inventory.h"
#include "../classes/Vector2D.h"
#include "../classes/WorldGenerator.h"
#include "../headers/functions.h"
#define MAX_ETR 4
namespace PlayerN {

    struct Bounds {
        int max_x;
        int max_y;
        int min_x;
        int min_y;
    };

    class Player {
    private:

        unsigned short health = 100;
        Inventory inventory;

        char sprite = 'P';
        Bounds bounds;
        std::array<worldGen::Entrance, 4> entrances;
		worldGen::WorldGenerator* wgen_ptr;
        unsigned int roomID = 0; // default, spawn


    public:
        Vector2D position {3, 3}; // {0, 0} is Top Left corner (by defualt off bounds
        Vector2D prev_pos {2, 2};

        Player(unsigned short hp, Bounds bounds, worldGen::WorldGenerator* wgen_ptr) : bounds(bounds) {
			this->wgen_ptr = wgen_ptr;
            this->health = hp;
            this->inventory =  Inventory();
        }
        void changeEntrances(std::array<worldGen::Entrance, 4> newEntrances) {
            this->entrances = newEntrances;
        }
        void handleEntrance() {
            
        }




        void move(Vector2D direction) {
			bool roomExists = false;
            Vector2D newPos = this->position + direction;
            short safeCount=0;
            // TODO: fix because not efficient.
            // if newPos is out of bounds then don't make move
            //  BUT if newPos is in Entrance (technically out of bounds) then make it possible.
            for(worldGen::Entrance entr : this->entrances) {
                if (safeCount >= MAX_ETR) break;

                // if newPos is not in entrance then skip.
				if ((Vector2D){entr.x, entr.y} != newPos) continue;

                unsigned int newRoomID;

                // player wants to use Entrance.
                // TODO: 0. Check if room exists then do not generate new but enter existing one.
                // 1. Generate new Room
                // 2. Teleport player there AND CHANGE ITS POSITION
                // 3. Update bounds.
                short side = wgen_ptr->getSideFromPos({entr.x, entr.y}, this->roomID);

                // 0. Check if room exists. NOT EFFICIENT ENOUGH
                /**for(worldGen::Room room : wgen_ptr->getMap()) {
                    for(worldGen::Entrance entrance : room.entrances) {
                        if (entr.id == entrance.id && room.id != this->roomID) {
                            // room exists, do not generate but teleport to existing room
                            roomExists = true;
                            newRoomID = room.id;
                        }
                    }
                }
                
                
                if (!roomExists)*/ newRoomID = wgen_ptr->generateRoom(wgen_ptr->getEntranceBySide(side, this->roomID).id, side);
                this->roomID = newRoomID;
                worldGen::Room newRoom = wgen_ptr->getRoomByID(newRoomID);
                this->position = {int(newRoom.width/2), int(newRoom.height/2)};
                return;



				
			}
            // check is new position in bounds. 
            if (newPos.x <= bounds.max_x-1 && newPos.y <= bounds.max_y-1 &&
                newPos.x >= bounds.min_x && newPos.y >= bounds.min_y-1) {
                this->prev_pos = position;
                this->position = newPos;
            }

        }

        void setSprite(char s) {
            this->sprite = s;
        }
        char getSprite() const {
            return this->sprite;
        }
		unsigned int getRoomID() {
			return this->roomID;
		}
		void setBounds(Bounds newBounds) {
			this->bounds = newBounds;
		}




    };

}



#endif //CLI_GAME_PLAYER_H
