//
// Created by Mateusz Pawełko on 03/11/2023.
//

#ifndef CLI_GAME_PLAYER_H
#define CLI_GAME_PLAYER_H

#include <array>
#include "../classes/inventory.h"
#include "../classes/Vector2D.h"
namespace Player {

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

        short roomID=0; // Player room. 0=spawn
        char sprite = 'P';
        Bounds bounds;


    public:
        Vector2D position {3, 3};
        Vector2D prev_pos {2, 2};

        Player(unsigned short hp, Bounds bounds) : bounds(bounds) {
            this->health = hp;
            this->inventory =  Inventory();
        }
        void move(Vector2D direction) {

            Vector2D newPos = this->position + direction;
            // if newPos is out of bounds then don't make move.
            if (newPos.x <= bounds.max_x-1 && newPos.y <= bounds.max_y-1 &&
                newPos.x >= bounds.min_x && newPos.y >= bounds.min_y-1) {
                this->prev_pos = position;
                this->position = newPos;
            }

        }
        void setSprite(char s) {
            this->sprite = s;
        }
        char getSprite() {
            return this->sprite;
        }




    };

}



#endif //CLI_GAME_PLAYER_H
