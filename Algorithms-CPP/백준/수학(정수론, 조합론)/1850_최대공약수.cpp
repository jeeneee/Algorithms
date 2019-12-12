//
//  1850_최대공약수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/12.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

#define ull unsigned long long

ull gcd(ull a, ull b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ull a, b;
    cin >> a >> b;
    
    ull digits = gcd(a, b);
    
    while(digits--)
        cout << 1;
    cout << '\n';
    
    return 0;
}
