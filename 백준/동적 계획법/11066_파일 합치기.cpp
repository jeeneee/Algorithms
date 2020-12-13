//
//  11066_파일 합치기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/07.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 https://js1jj2sk3.tistory.com/3?category=725178
 점화식을 잘 세워야 한다.
 위 블로그에서 참고하였으며, 풀이 1 (O(N^3))을 썼다. 풀이 3의 시간 복잡도는 O(N^2)이다.
 나중에 다시 풀어보기 바람.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cost(n + 1);
        vector<int> sum(n + 1, 0);
        vector<vector<int> > dp(n + 1, vector<int> (n + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        
        // dp[i,j] = min(i<=k<j){dp[i][k] + dp[k+1][j]} + psum[i][j]
        for (int d = 1; d < n; ++d) {
            for (int i = 1; i + d <= n; ++i) {
                int j = i + d;
                dp[i][j] = INF;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
                }
            }
        }
        cout << dp[1][n] << '\n';
    }
    
    return 0;
    
}
