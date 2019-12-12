//
//  1541_잃어버린 괄호.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 10/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> num;
    vector<int> sign;   // 0: -, 1: +
    
    sign.push_back(1);
    int temp_num = 0;
    for (int i = 0; i < s.size(); ++i) {
        // when s[i] is sign
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '+')
                sign.push_back(1);
            else if (s[i] == '-')
                sign.push_back(0);
            num.push_back(temp_num);
            temp_num = 0;
        }
        // when s[i] is number
        else
            temp_num = temp_num * 10 + (s[i] - '0');
    }
    num.push_back(temp_num);
    
    int flag = 0, res = 0, temp_res = 0;
    for (int i = 0; i < sign.size(); ++i) {
        // +
        if (sign[i] == 1) {
            if (flag)
                temp_res += num[i];
            else
                res += num[i];
        }
        // -
        else {
            if (flag) {
                res -= temp_res;
                temp_res = num[i];
            }
                
            else {
                flag = 1;
                temp_res += num[i];
            }
        }
    }
    if (flag)
        res -= temp_res;

    cout << res << endl;
    
    return 0;
}
