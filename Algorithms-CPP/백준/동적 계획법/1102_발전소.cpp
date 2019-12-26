//
//  1102_발전소.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 16;
const int INF = 1234567890;
int N, P;
// 비용, 방문 배열
int cost[MAX_N][MAX_N], dp[1<<MAX_N];

int solve(int num, int status) {
    // 기저 사례 : P개 이상의 발전소가 정상인 경우
    if (num >= P)
        return 0;
    
    int &ret = dp[status];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 0; i < N; ++i) {
        // 가동중인 발전소에서
        if (status & (1<<i)) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                // 고장난 발전소를 최소비용으로 복구한다.
                if ((status & (1<<j)) == 0)
                    ret = min(ret, solve(num+1, status|(1<<j)) + cost[i][j]);
            }
        }
    }
    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> cost[i][j];
    string s;
    int cnt = 0, status = 0;
    cin >> s >> P;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'Y') {
            status |= (1<<i);
            ++cnt;
        }
    }
    
    // 가동된 발전소가 없는 경우
    if (cnt == 0) {
        // 가동할 필요가 없는 경우
        if (P == 0)
            cout << 0 << endl;
        // 불가능한 경우
        else
            cout << -1 << endl;
    }
    // 가동된 발전소를 통해 문제를 해결한다.
    else {
        fill_n(dp, 1<<MAX_N, -1);
        cout << solve(cnt, status) << endl;
    }
    
    return 0;
}

