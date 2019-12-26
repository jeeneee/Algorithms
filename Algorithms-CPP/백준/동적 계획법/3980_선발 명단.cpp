//
//  3980_선발 명단.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 11;
const int MIN = -1234567890;
int stat[N][N];
int dp[N][1<<N];

int solve(int num, int pos) {
    if (num == N) return 0;
    int &ret = dp[num][pos];
    if (ret != -1) return ret;
    
    ret = MIN;
    for (int i = 0; i < N; ++i) {
        if (stat[i][num] && ((pos & 1<<i) == 0))
            ret = max(ret, solve(num+1, pos|1<<i) + stat[i][num]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> stat[i][j];
            }
            fill_n(dp[i], 1<<N, -1);
        }
        int pos = 0;
        cout << solve(0, pos) << '\n';
    }
    return 0;
}
