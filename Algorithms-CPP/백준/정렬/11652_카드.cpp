//
//  11652_카드.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define integer long long

bool compare(const pair<integer, int> &a,
             const pair<integer, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<integer> arr(n);
    vector<pair<integer, int> > v; // <수, 개수>
    
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    integer curNum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != curNum || v.empty()) {
            v.push_back( {arr[i], 0} );
            curNum = arr[i];
        }
        v.back().second++;
    }
    
    sort(v.begin(), v.end(), compare);
    
    cout << v[0].first << '\n';
    
    return 0;
}
