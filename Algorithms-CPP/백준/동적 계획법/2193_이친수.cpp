//
//  2193_이친수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/02.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long *dp = new long long[n];
    dp[0] = dp[1] = 1;
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[n - 1] << endl;
    
    return 0;
}
