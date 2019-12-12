//
//  Point.hpp
//  Algorithms-CPP
//
//  Created by 짱우 on 30/09/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

class Point {
private:
    int x;
    int y;
    
public:
    Point(const int &xpos, const int &ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};
#endif /* Point_hpp */
