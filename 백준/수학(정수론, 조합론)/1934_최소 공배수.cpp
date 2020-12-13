//
//  1934_최소 공배수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/12.
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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    return 0;
}
