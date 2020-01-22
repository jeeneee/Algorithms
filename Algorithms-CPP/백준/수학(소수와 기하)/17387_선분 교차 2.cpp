//
//  17387_선분 교차 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/22.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 CCW
 두 선분이 평행할 때를 따로 처리해야 함.
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
    
    int ans;
    if (ccw_a * ccw_b <= 0 && ccw_c * ccw_d <= 0) {
        if (ccw_a * ccw_b == 0 && ccw_c * ccw_d == 0) {
            if (a.x > b.x) swap(a, b);
            if (c.x > d.x) swap(c, d);
            ans = (c.x <= b.x && a.x <= d.x);
        } else
            ans = 1;
    } else
        ans = 0;
    
    cout << ans << endl;
    
    return 0;
}
