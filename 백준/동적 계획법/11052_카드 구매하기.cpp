//
//  11052_카드 구매하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/10.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int *card = new int[n + 1];
    int *dp = new int[n + 1] {0};

    for (int i = 1; i <= n; ++i)
        cin >> card[i];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], dp[i - j] + card[j]);
        }
    }

    cout << dp[n] << endl;
    
    delete []card;
    delete []dp;
    return 0;
}
