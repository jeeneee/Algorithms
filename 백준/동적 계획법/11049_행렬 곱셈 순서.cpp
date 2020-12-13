//
//  11049_행렬 곱셈 순서.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/05.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 500 + 1;
int m[MAX][2]; // {r, c}
int dp[MAX][MAX];

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &m[i][0], &m[i][1]);
    }
    
    for (int j = 2; j <= n; ++j) {
        for (int i = j-1; i >= 1; --i) {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] +
                               m[i][0] * m[k][1] * m[j][1]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    
    return 0;
}
