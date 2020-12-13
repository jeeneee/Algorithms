//
//  11057_오르막 수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/02.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 1001
using namespace std;

int main() {
    int n, dp[10], sum;
    
    for (int i = 0; i < 10; ++i)
        dp[i] = 1;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        sum = dp[0];
        for (int j = 1; j < 10; ++j)
            dp[j] = (dp[j] + dp[j - 1]) % 10007;
    }
    
    cout << dp[9] << endl;
    
    return 0;
}
