//
//  1212_8진수 2진수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/13.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    string octal;
    cin >> octal;
    
    if (octal == "0") {
        cout << 0 << '\n';
        return 0;
    }
    
    for (int i = 0; i < octal.length(); ++i) {
        vector<int> nums;
        int num = octal[i] - '0';
        int cnt = 0;
        while (num) {
            nums.push_back(num % 2);
            num /= 2;
            ++cnt;
        }
        if (i != 0)
            for (int i = 2 - cnt; i >= 0; --i) {
                nums.push_back(0);
                ++cnt;
            }
        while (cnt--)
            cout << nums[cnt];
    }
    cout << '\n';
    
    return 0;
}
