//
// Created by Mateusz Pawełko on 03/11/2023.
//

#ifndef CLI_GAME_PLAYER_H
#define CLI_GAME_PLAYER_H

#include <array>
#include "../classes/inventory.h"
#include "../classes/Vector2D.h"

class Player {
private:

    unsigned short health = 100;
    Inventory inventory;
    Vector2D position {0, 0};
    short roomID=0; // Player room. 0=spawn
    char sprite = 'P';



public:
    Player(unsigned short hp) {
        this->health = hp;
        this->inventory =  Inventory();
    }
    void move(Vector2D direction) {
        this->position = this->position + direction;
    }
    void setSprite(char s) {
        this->sprite = s;
    }
    char getSprite() {
        return this->sprite;
    }




};



#endif //CLI_GAME_PLAYER_H
