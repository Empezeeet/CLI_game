//
// Created by Empezeeet on 03/11/2023.
//

#ifndef CLI_GAME_INPUTHANDLER_H
#define CLI_GAME_INPUTHANDLER_H

#include <cstdlib>
#include "../headers/kbhit_alternative.h"
#include "../classes/Player.h"

class InputHandler {
private:
    PlayerN::Player* player;
public:
    explicit InputHandler(PlayerN::Player* player) : player(player) {

    }
    bool handleInput() {
        if((bool)kbhit()) {
            char c = (char)getchar();
            switch (c) {
                case '+': {
                    return true;
                }
                case 'w': {
                    player->move({0, -1});
                    break;
                }
                case 's': {
                    player->move({0, 1});
                    break;
                }
                case 'a': {
                    player->move({-1, 0});
                    break;
                }
                case 'd': {
                    player->move({1, 0});
                    break;
                }

            }

            
        }
        fseek(stdin,0,SEEK_END);
        return false;
    }
};


#endif //CLI_GAME_INPUTHANDLER_H
