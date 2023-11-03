//
// Created by Mateusz Pawełko on 03/11/2023.
//

#ifndef CLI_GAME_VECTOR2D_H
#define CLI_GAME_VECTOR2D_H


class Vector2D {
private:
    int x;
    int y;
public:
    Vector2D(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Vector2D operator+(Vector2D const v2) {
        return {this->x + v2.x, this->y + v2.y};
    }

    Vector2D operator-(Vector2D const v2) {
        return {this->x - v2.x, this->y - v2.y};
    }
    Vector2D operator*(int mul) {
        return {this->x *mul, this->y *mul};
    }
};


#endif //CLI_GAME_VECTOR2D_H
