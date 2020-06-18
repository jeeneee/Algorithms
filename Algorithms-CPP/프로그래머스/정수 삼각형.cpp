//
//  정수 삼각형.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    int answer = 0;
    vector<vector<int>> dp(n, vector<int> (n, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    for (int i = 0; i < n; ++i)
        answer = max(answer, dp[n-1][i]);
    return answer;
}
