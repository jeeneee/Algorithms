//
//  9780_외계인 침공(D5).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/24.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: i번째 도시를 침공하면 i-1, i+1 도시를 침공할 수 없다.
 해설: 고르지 않거나 골랐을 경우 한 칸 뛰는 다이나믹 프로그래밍을 통해 해결하였다.
 알고리즘: DP
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
long long frog[MAX];
long long dp[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			dp[i] = 0;
			cin >> frog[i];
		}
		dp[0] = 0;
		dp[1] = frog[1];
		for (int i = 2; i <= n; ++i)
			// 한 칸 건너 뛰는 것과 침공할 경우 두 칸 전을 비교
			dp[i] = max(dp[i-1], dp[i-2] + frog[i]);
		cout << '#' << tc << ' ' << dp[n] << '\n';
	}
	return 0;
}
