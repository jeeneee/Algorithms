//
//  9084_동전.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/06.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n;
        int *coin = new int[n];
        
        for (int i = 0; i < n; ++i)
            cin >> coin[i];
        
        cin >> m;
        int *dp = new int[m + 1] {0};
        dp[0] = 1;
        
        for (int i = 0; i < n; ++i)
            for (int j = coin[i]; j <= m; ++j)
                dp[j] += dp[j - coin[i]];
        
        cout << dp[m] << '\n';
        
        delete []coin;
        delete []dp;
    }
    
    return 0;
}
