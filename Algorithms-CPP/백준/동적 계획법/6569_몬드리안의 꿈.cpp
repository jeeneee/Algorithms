//
//  6569_몬드리안의 꿈.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/24.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <1648_격자판 채우기>와 같은 문제.
 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 11;
long long dp[MAX*MAX][1 << MAX];
long long ans[MAX+1][MAX+1];
int n, m;

// num=0부터 n*m-1까지의 칸, state=num칸부터 num+m-1칸까지의 상태
long long go(int num, int state) {
	// 기저 사례
	if (num == n*m && state == 0)
		return 1;
	if (num >= n*m)
		return 0;
	if (dp[num][state] != -1)
		return dp[num][state];
	
	long long& ret = dp[num][state];
	ret = 0;
	if (state & 1) { // 놓을 수 없는 경우 다음 칸으로 넘어간다.
		ret = go(num+1, (state >> 1));
	} else { // 2x1과 1x2를 채울 수 있다.
		ret = go(num+1, (state >> 1) | (1 << (m-1)));
		if ((num%m) != (m-1) && (state & 2) == 0)
			ret += go(num+2, state >> 2);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i <= MAX; ++i) {
		for (int j = 1; j <= MAX; ++j) {
			memset(dp, -1, sizeof(dp));
			n = i; m = j;
			ans[i][j] = go(0, 0);
		}
	}
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cout << ans[n][m] << '\n';
	}
	return 0;
}
