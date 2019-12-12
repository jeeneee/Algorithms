//
//  10820_문자열 분석.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;

    while (getline(cin, str)) {
        int lower = 0, upper = 0, digit = 0, space = 0;
        
        for (int i = 0; str[i] != 0; ++i) {
            if (str[i] >= 'a' && str[i] <= 'z')
                ++lower;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                ++upper;
            else if (str[i] >= '0' && str[i] <= '9')
                ++digit;
            else
                ++space;
        }
        cout << lower << ' ' << upper << ' ' << digit << ' ' << space << endl;
    }

    return 0;
}
