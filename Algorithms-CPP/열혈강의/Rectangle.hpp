//
//  Rectangle.hpp
//  Algorithms-CPP
//
//  Created by 짱우 on 30/09/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Point.hpp"
#include <stdio.h>

class Rectangle {
private:
    Point upLeft;
    Point lowRight;
    
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
    void ShowRecInfo() const;
};
#endif /* Rectangle_hpp */
