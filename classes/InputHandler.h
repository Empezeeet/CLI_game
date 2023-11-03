//
// Created by Mateusz Pawełko on 03/11/2023.
//

#ifndef CLI_GAME_INPUTHANDLER_H
#define CLI_GAME_INPUTHANDLER_H

#include "../classes/Player.h"
#include <stdio.h>
class InputHandler {
private:
    Player* cplayer;
public:
    InputHandler(Player* player) : cplayer(player) {


        mainloop();

    }
    void mainloop() {
        while (1) {
            cplayer->setSprite(getchar());
        }

    }
};


#endif //CLI_GAME_INPUTHANDLER_H
