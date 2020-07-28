//
//  2266_금고 테스트.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501]; // k개 n층

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= k; ++i) dp[i][1] = 1;
	for (int i = 1; i <= n; ++i) dp[1][i] = i;

	for (int i = 2; i <= k; ++i) {
		for (int j = 2; j <= n; ++j) {
			dp[i][j] = 500;
			for (int f = 1; f <= j; ++f)
				dp[i][j] = min(dp[i][j], max(dp[i-1][f-1], dp[i][j-f]) + 1);
		}
	}
	
	cout << dp[k][n] << endl;
	
	return 0;
}
