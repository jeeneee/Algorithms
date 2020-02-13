//
//  1010_다리 놓기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 30;
unsigned long long dp[MAX][MAX];

unsigned long long bino(int n, int k) {
	if (k == 0 || n == k) return 1;
	if (dp[n][k] != -1) return dp[n][k];
	return dp[n][k] = bino(n-1, k-1) + bino(n-1, k);
}

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
//		memset(dp, -1, sizeof(dp));
		cin >> m >> n;
//		cout << bino(n, m) << '\n';
		long long ans = 1;
		for (int i = 1; i <= m; ++i)
			ans = ans * (n - i + 1) / i;
		cout << ans << '\n';
	}
	return 0;
}
