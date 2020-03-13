//
//  17069_파이프 옮기기 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/13.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <17070_파이프 옮기기 1>에서 n이 두 배로 늘어났다. 완전탐색으로 하면 시간초과이기 때문에
	  동적 계획법을 써야 한다. 조건에 맞게 다이나믹 프로그래밍.
 알고리즘: 동적 계획법
 O(N^2)
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 32;
bool map[MAX][MAX];
long long dp[MAX][MAX][3];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	dp[0][1][0] = 1; // 가로
	dp[0][1][1] = 0; // 세로
	dp[0][1][2] = 0; // 대각선
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j+1 < n && !map[i][j+1])
				dp[i][j+1][0] += dp[i][j][0] + dp[i][j][2];
			if (i+1 < n && !map[i+1][j])
				dp[i+1][j][1] += dp[i][j][1] + dp[i][j][2];
			if (i+1 < n && j+1 < n && !map[i+1][j+1])
				if (!map[i][j+1] && !map[i+1][j] && !map[i+1][j+1])
					dp[i+1][j+1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
		}
	}
	cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2] << '\n';
	return 0;
}
