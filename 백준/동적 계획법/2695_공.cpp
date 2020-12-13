//
//  2695_공.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int K = 50;
const int N = 1000;

int dp[K+1][N+1]; // k개 n층

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i <= K; ++i) dp[i][1] = 1;
	for (int i = 1; i <= N; ++i) dp[1][i] = i;
	
	for (int i = 2; i <= K; ++i) {
		for (int j = 2; j <= N; ++j) {
			dp[i][j] = 1e9;
			for (int f = 1; f <= j; ++f)
				dp[i][j] = min(dp[i][j], max(dp[i-1][f-1], dp[i][j-f]) + 1);
		}
	}
	
	int T, k, n;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> k >> n;
		cout << dp[k][n] << '\n';
	}
	return 0;
}
