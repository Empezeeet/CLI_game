//
// Created by Mateusz Pawełko on 04/11/2023.
//

#ifndef CLI_GAME_FUNCTIONS_H
#define CLI_GAME_FUNCTIONS_H

namespace funcs {
	/**
	 * Converts number to range. (Tests Passed)
	 * @param max number
	 * @param num number to convert
	 * @return unsigned short num in range
	 */
	unsigned short convertToRange(unsigned int max, unsigned int num) {
		if (num <= max) return num;
		return num%max;
	}
}


#endif //CLI_GAME_FUNCTIONS_H
