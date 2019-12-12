//
//  9465_스티커.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/02.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100001
using namespace std;

int dp[2][MAX];
int sticker[2][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t, n;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 0; i < 2; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> sticker[i][j];
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        for (int i = 2; i <= n; ++i) {
            dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + sticker[1][i];
        }
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
    return 0;
}
