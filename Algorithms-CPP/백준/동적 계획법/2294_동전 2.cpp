//
//  2294_동전 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/05.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int *dp = new int[k + 1];
    int *coin = new int[n];
    for (int i = 1; i <= k; ++i) dp[i] = MAX;
    dp[0] = 0;
    
    for (int i = 0; i < n; ++i)
        cin >> coin[i];
    
    for (int i = 0; i < n; ++i)
        for (int j = coin[i]; j <= k; ++j)
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    
    printf("%d\n", dp[k] == MAX ? -1 : dp[k]);
    
    delete []dp;
    delete []coin;
    return 0;
}
