//
//  17404_RGB거리 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/30.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 RGB거리 1과 다르게, 첫 집과 마지막 집도 이웃이다.
 그래서 첫 집의 색을 미리 정해서 3번을 돌린다.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000;
const int INF = 987654321;
int cost[MAX][MAX];
int dp[MAX][MAX];
int N;

int paint(int color) {
    switch (color) {
        case 0:
            dp[0][0] = cost[0][0];
            dp[0][1] = dp[0][2] = INF;
            break;
        case 1:
            dp[0][1] = cost[0][1];
            dp[0][0] = dp[0][2] = INF;
            break;
        case 2:
            dp[0][2] = cost[0][2];
            dp[0][0] = dp[0][1] = INF;
            break;
    }
    
    for (int i = 1; i < N; ++i) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }
    
    int res = INF;
    for (int i = 0; i < 3; ++i) {
        if (i == color) continue;
        res = min(res, dp[N-1][i]);
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    int ans = INF;
    for (int i = 0; i < 3; ++i) {
        memset(dp, 0, sizeof(dp));
        ans = min(ans, paint(i));
    }
    cout << ans << '\n';
    return 0;
}
