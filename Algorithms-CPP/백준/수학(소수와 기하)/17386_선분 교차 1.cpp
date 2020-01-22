//
//  17386_선분 교차 1.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/22.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 CCW를 이용한 선분 교차 판별
 ref: https://jason9319.tistory.com/358
 */

#include <iostream>
#include <vector>
using namespace std;

typedef struct _point {
    long long x;
    long long y;
} point;

int ccw(point a, point b, point c) {
    long long temp = a.x * b.y + b.x * c.y + c.x * a.y;
    temp -= a.y * b.x + b.y * c.x + c.y * a.x;
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

int main() {
    point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    
    int ccw_a = ccw(c, d, a);
    int ccw_b = ccw(c, d, b);
    int ccw_c = ccw(a, b, c);
    int ccw_d = ccw(a, b, d);
    
    if (ccw_a * ccw_b <= 0 && ccw_c * ccw_d <= 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    
    return 0;
}
