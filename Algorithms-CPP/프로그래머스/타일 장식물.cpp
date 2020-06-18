//
//  타일 장식물.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    vector<long long> dp(N+1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= N; ++i)
        dp[i] = dp[i-2] + dp[i-1];
    answer = (dp[N] + dp[N-1]) * 2;
    return answer;
}
