//
//  [2017 카카오 코드 예선] 보행자 천국.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/08/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int MOD = 20170805;
int dp[2][501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (city_map[i][j] == 0) {
				dp[0][i + 1][j] = (dp[0][i + 1][j] + dp[0][i][j] + dp[1][i][j]) % MOD;
				dp[1][i][j + 1] = (dp[1][i][j + 1] + dp[0][i][j] + dp[1][i][j]) % MOD;
			} else if (city_map[i][j] == 2) {
				dp[0][i + 1][j] = (dp[0][i + 1][j] + dp[0][i][j]) % MOD;
				dp[1][i][j + 1] = (dp[1][i][j + 1] + dp[1][i][j]) % MOD;
			}
		}
	}
	
	return (dp[0][m - 1][n - 1] + dp[1][m - 1][n - 1]) % MOD;
}

int main() {
	vector<vector<int>> city_map = {
		{0, 2, 0, 0, 0, 2},
		{0, 0, 2, 0, 1, 0},
		{1, 0, 0, 2, 2, 0}
	};
	cout << solution(3, 6, city_map) << endl;
	return 0;
}
