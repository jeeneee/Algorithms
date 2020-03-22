//
//  1890_점프.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/21.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 dfs + dp
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
int map[MAX][MAX];
long long dp[MAX][MAX];
int n;

long long dfs(int x, int y) {
	long long &ret = dp[x][y];
	if (ret != -1) return ret;
	if (x == n-1 && y == n-1) return 1;
	ret = 0;
	if (x + map[x][y] < n)
		ret += dfs(x + map[x][y], y);
	if (y + map[x][y] < n)
		ret += dfs(x, y + map[x][y]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << '\n';
	return 0;
}
