//
// Created by Empezeeet on 03/11/2023.
//

#ifndef CLI_GAME_INVENTORY_FUNCTIONS_H
#define CLI_GAME_INVENTORY_FUNCTIONS_H

#include <array>

namespace inventoryFunctions {

    struct FindData {
        bool success;
        unsigned short index;
        unsigned short count;
    };





    /**
    *
    * @param input
    * @return unsigned short. count of "empty" items
    */
    unsigned short emptyItemCount(std::array<std::array<unsigned short, 2>, 10> input) {
        unsigned short counter= 0;
        for (std::array<unsigned short, 2> item: input) {
            if (item == std::array<unsigned short,2 > {0,0}) {
                counter++;
            }
        }
        return counter;
    }
    /**
     * Finds index of first empty item in inventory
     * @param input
     * @return number >= 0 if success, -1 if failed
     */
    short firstEmptyIndex(std::array<std::array<unsigned short, 2>, 10> input) {
        short counter=0;
        for (std::array<unsigned short, 2> item: input) {
            counter++;
            if (item == std::array<unsigned short,2 > {0,0}) {
                return counter;
            }
        }
        return -1; // something went wrong OR inventory is full.
    }
    /**
     * Finds item in inventory and returns {true, index, count} or {false, 0, 0}
     * @param id of item
     * @param count of item
     * @param input inventory
     * @return FindData struct {bool success, unsigned short index, unsigned short count}
     */
    FindData findInInventory(unsigned short id, unsigned short count, std::array<std::array<unsigned short, 2>, 10> input) {
        for (unsigned short i=0; i<input.size(); i++) {
            if (input[i][0] == id) {
                // item is in inventory
                return {true, i, input[i][1]};
            }
        }
        return {false, 0, 0};
    }
}




#endif //CLI_GAME_INVENTORY_FUNCTIONS_H
