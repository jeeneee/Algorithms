//
//  2293_동전 1.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/15.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>

int main() {
    int n, k, value;
    scanf("%d%d", &n, &k);
    std::vector<int> coin;
    int *dp = new int[k + 1]{0};
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        if (value <= k)
            coin.push_back(value);
    }
    
    dp[0] = 1;
    for (int i = 0; i < coin.size(); ++i) {
        for (int j = coin[i]; j <= k; ++j) {
            dp[j] += dp[j - coin[i]];
        }
    }
    printf("%d\n", dp[k]);
    
    delete []dp;
    return 0;
}
