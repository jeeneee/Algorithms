//
//  Point.cpp
//  Algorithms-CPP
//
//  Created by 짱우 on 30/09/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include "Point.hpp"
#include <iostream>
using namespace std;

Point::Point(const int &xpos, const int &ypos): x(xpos), y(ypos){
}

int Point::GetX() const {
    return x;
}

int Point::GetY() const {
    return y;
}

bool Point::SetX(int xpos) {
    if (xpos < 0 || xpos > 100) {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(int ypos) {
    if (ypos < 0 || ypos > 100) {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    y = ypos;
    return true;
}
