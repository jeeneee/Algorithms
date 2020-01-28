//
//  12852_1로 만들기 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/27.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000 + 1;
int dp[MAX];
int par[MAX];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        dp[i] = n - i;
        par[i] = i + 1;
    }
    par[n] = 0;
    for (int i = n; i > 0; --i) {
        if (i != n && dp[i+1] < dp[i]) {
            dp[i] = dp[i+1] + 1;
            par[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i / 2] > dp[i] + 1) {
            dp[i / 2] = dp[i] + 1;
            par[i / 2] = i;
        }
        if (i % 3 == 0 && dp[i / 3] > dp[i] + 1) {
            dp[i / 3] = dp[i] + 1;
            par[i / 3] = i;
        }
    }
    cout << dp[1] << '\n';
    
    vector<int> v;
    int x = 1;
    v.push_back(x);
    while (par[x]) {
        v.push_back(par[x]);
        x = par[x];
    }
    
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << ' ';
    cout << '\n';
    
    return 0;
}
