//
//  3036_링.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/29.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n, firstNum;
    cin >> n >> firstNum;
    
    for (int i = 1; i < n; ++i) {
        int num;
        cin >> num;
        cout << firstNum / gcd(firstNum, num);
        cout << "/";
        cout << num / gcd(firstNum, num) << '\n';
    }
    
    return 0;
}
