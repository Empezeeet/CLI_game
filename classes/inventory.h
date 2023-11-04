//
// Created by Empezeeet on 03/11/2023.
//

#ifndef CLI_GAME_INVENTORY_H
#define CLI_GAME_INVENTORY_H


#include "../headers/inventory_functions.h"
using namespace inventoryFunctions;
class Inventory {
private:
    // [ (id, count) ... ]
    std::array<std::array<unsigned short, 2>, 10> inventory = { };
public:
    Inventory() {

    }
    /**
     * Adds item to inventory.
     * @param id
     * @param count
     * @return boolean. Depends on successful execution.
     */
    bool addToInventory(unsigned short id, unsigned short count) {
        // TODO: Inventory doesn't support stacking
        //  if u have {2, 12} amd add {2, 1} then you have 2 different items.

        // 1. check is inventory full (guard)
        // 2. put item in inventory (at end)
        if (0 == emptyItemCount(inventory)) return false;
        // TODO: to fix above error, check here is item in inventory already.

        short first_empty_index = firstEmptyIndex(inventory);
        if (first_empty_index == -1) return false;//this can be strange error...
        inventory.at(first_empty_index) = {id, count};
        return true;
    }
    /**
     * Removes from inventory OR subtracts count of items.
     * @param id
     * @param count
     * @return true, if successfuly removed or false
     */
    bool removeFromInventory(unsigned short id, unsigned short count) {
        // 1.find item with id. if not return false;
        FindData isInInventory = findInInventory(id, count, inventory);
        if (!isInInventory.success) return false;
        // 2. remove count OR if count > item.count then remove from inventory
        if (count >= isInInventory.count) {
            inventory[isInInventory.index] = {0, 0};
            // 3. format inventory so non-empty items are near each other.

        } else {
            inventory[isInInventory.index][1] -= count;
        }
        return true;


    }
};

#endif //CLI_GAME_INVENTORY_H
