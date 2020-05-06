//
//  2xn 타일링.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/05.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long dp[60001];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
        dp[i] = (dp[i-2] + dp[i-1]) % 1000000007;
    return dp[n];
}
