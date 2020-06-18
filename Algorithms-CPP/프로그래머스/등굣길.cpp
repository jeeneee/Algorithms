//
//  등굣길.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            bool pass = false;
            for (int k = 0; k < puddles.size(); ++k)
                if (puddles[k][0] == j && puddles[k][1] == i)
                    pass = true;
            if (pass) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
			cout << dp[i][j] << endl;
        }
    }
    return dp[n][m];
}

int main() {
	cout << solution(4, 3, {{2,2}}) << endl;
	return 0;
}
