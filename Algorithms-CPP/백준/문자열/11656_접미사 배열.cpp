//
//  11656_접미사 배열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> v;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i)
        v.push_back(s.substr(i));
    
    sort(v.begin(), v.end());
    
    for (string &i: v)
        cout << i << '\n';

    return 0;
}
