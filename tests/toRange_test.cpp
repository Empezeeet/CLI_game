//
// Created by Mateusz Pawełko on 04/11/2023.
//
#include "../headers/functions.h"
#include <iostream>

int main() {
	auto t1 = funcs::convertToRange(4, 1+2);
	auto t2 = funcs::convertToRange(4, 2+2);
	auto t3 = funcs::convertToRange(4, 3+2);
	auto t4 = funcs::convertToRange(4, 4+2);
	std::cout << "EXP: t1,t2,t3,t4 == 3 4 1 2" << std::endl;
	std::cout << "GOT: t1,t2,t3,t4 == "<<t1<< " " << t2 << " " <<t3 << " " << t4;
	if (t1 == 3 && t2 == 4 && t3==1 && t4==2) {
		return 0;
	} else {
		return 1;
	}

}