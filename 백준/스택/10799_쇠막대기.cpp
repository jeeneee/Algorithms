//
//  10799_쇠막대기.cpp
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
    
    int bar = 0, razer = 0, res = 0;
    string bracket;
    
    cin >> bracket;
    
    for (int i = 0; i < bracket.size(); ++i) {
        if (bracket[i] == '(') {
            ++bar;
        }
        else {
            --bar;
            if (bracket[i - 1] == '(')
                res += bar;
            else
                ++razer;
        }
    }
    
    cout << res + razer << endl;
    
    return 0;
}
