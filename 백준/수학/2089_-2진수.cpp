//
//  2089_-2진수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/13.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 ref: https://en.wikipedia.org/wiki/Negative_base#C++
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int dec;
    cin >> dec;
    
    if (dec == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    while (dec != 0) {
        const auto res = div(dec, -2);
        if (res.rem < 0)
            dec = res.quot + 1;
        else
            dec = res.quot;
        v.push_back(res.rem != 0);
    }
    
    for (int i = (int)v.size() - 1; i >= 0; --i)
        cout << v[i];
    cout << '\n';
    
    return 0;
}
