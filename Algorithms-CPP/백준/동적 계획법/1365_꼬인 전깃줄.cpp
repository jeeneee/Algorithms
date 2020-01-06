//
//  1365_꼬인 전깃줄.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    dp.push_back(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            continue;
        }
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        *it = arr[i];
    }
    cout << n - (int)dp.size() << endl;
    
    return 0;
}
