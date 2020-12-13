//
//  9708_가장 긴 수열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/27.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 1 ≤ i < K인 i에 대해 ai < ai+1 이면서, ai이 ai+1의 약수여야 한다.
 알고리즘: DP
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
bool arr[MAX];
int n, dp[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		for (int i = 0; i < MAX; ++i) {
			arr[i] = false;
			dp[i] = 0;
		}
		
		cin >> n;
		int mn = MAX, mx = 0;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			arr[x] = dp[x] = 1;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		
		int ans = 0;
		for (int i = mn; i <= mx; ++i) {
			if (!arr[i]) continue;
			for (int j = i + i; j <= mx; j += i) {
				if (arr[j])
					dp[j] = max(dp[j], dp[i] + 1);
			}
			ans = max(ans, dp[i]);
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
