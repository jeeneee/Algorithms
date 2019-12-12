//
//  2565_전깃줄.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/14.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    int *dp = new int[n];
    fill(dp, dp + n, 1);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end());
    
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i].second > v[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }
    
    cout << n - maxLen << '\n';
    
    delete []dp;
    return 0;
}
