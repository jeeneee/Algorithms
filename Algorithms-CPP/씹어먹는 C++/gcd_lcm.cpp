//
//  gcd_lcm.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 11/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

// 최대 공약수
int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
// 최소 공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
