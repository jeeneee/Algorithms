//
//  2745_진법 변환.cpp
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
    string n;
    int b;
    cin >> n >> b;
    int len = (int)n.length();
    int ans = 0, digit;
    for (int i = 0; i < len; ++i) {
        if (n[i] >= '0' && n[i] <= '9') digit = n[i] - 48;
        else digit = n[i] - 55;
        ans += digit * pow(b, len - i - 1);
    }
    
    cout << ans << endl;
    
    return 0;
}
