//
//  1373_2진수 8진수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/12.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    string binary;
    cin >> binary;
    int len = (int)binary.length();
    int add = 0;
    
    if (len % 3 != 0)
        add = 3 - len % 3;
    len += add;
    
    while (add--) binary.insert(binary.begin(), '0');
    
    for (int i = 0; i < len / 3; ++i) {
        int digit = 0;
        digit += (binary[3 * i] - '0') * 4;
        digit += (binary[3 * i + 1] - '0') * 2;
        digit += (binary[3 * i + 2] - '0');
        cout << digit;
    }
    cout << '\n';
    
    return 0;
}
