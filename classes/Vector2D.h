//
// Created by Empezeeet on 03/11/2023.
//

#ifndef CLI_GAME_VECTOR2D_H
#define CLI_GAME_VECTOR2D_H


class Vector2D {


public:
    int x;
    int y;
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
    bool operator==(Vector2D& other) {
        if (this->x == other.x && this->y == other.y) return true;
        return false;
    }
    bool operator!=(Vector2D& other) {
        if (this->x == other.x && this->y == other.y) return false;
        return true;
    }

};


#endif //CLI_GAME_VECTOR2D_H
