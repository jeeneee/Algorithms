//
//  1427_소트인사이드.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 09/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> v;

int main() {
    string s;
    cin >> s;
    int n = stoi(s);
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end());
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        cout << v[i];
    }
    cout << endl;
    
    return 0;
}

