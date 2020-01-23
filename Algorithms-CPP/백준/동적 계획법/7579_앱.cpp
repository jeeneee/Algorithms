//
//  7579_앱.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 냅색(napsack) 변형 문제
 각 앱의 최대 cost가 100이고 최대 앱 수가 100이기 때문에 전체 최대 cost는 10000임을 파악하고
 dp를 이용해 해결한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bytes[101];
int cost[101];
    // dp[i] = i(cost)로 얻을 수 있는 최대의 bytes
int dp[10001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &bytes[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &cost[i]);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 10000; j >= cost[i]; --j) {
            dp[j] = max(dp[j], dp[j-cost[i]] + bytes[i]);
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= 10000 ; ++i) {
        if (dp[i] >= m) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}



    //// dp[i][j] = i번째 앱까지 중 j(cost)로 얻을 수 있는 최대의 bytes
    //int dp[101][10001];
    //
    //int main() {
    //    int n, m;
    //    scanf("%d %d", &n, &m);
    //    for (int i = 0; i < n; ++i)
    //        scanf("%d", &bytes[i]);
    //    for (int i = 0; i < n; ++i)
    //        scanf("%d", &cost[i]);
    //
    //    dp[0][cost[0]] = bytes[0];
    //    int ans = INF;
    //    for (int i = 1; i < n; ++i) {
    //        for (int j = 0; j <= 10000; ++j) {
    //            if (j >= cost[i])
    //                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + bytes[i]);
    //            dp[i][j] = max(dp[i][j], dp[i-1][j]);
    //            if (dp[i][j] >= m)
    //                ans = min(ans, j);
    //        }
    //    }
    //
    //    printf("%d\n", ans);
    //
    //    return 0;
    //}
