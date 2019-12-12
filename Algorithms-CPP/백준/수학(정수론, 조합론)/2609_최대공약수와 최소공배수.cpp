//
//  2609_최대공약수와 최소공배수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/28.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';
    
    return 0;
}
