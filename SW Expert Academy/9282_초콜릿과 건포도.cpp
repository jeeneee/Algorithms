//
//  9282_초콜릿과 건포도.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/03.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 건포도가 들어있는 NxM크기의 초콜릿을 N*M개의 초콜릿으로 분할시키는 문제.
 해설: 자를 때마다 기존 초콜릿에 들어있는 건포도만큼의 비용이 생기므로 메모이제이션이 필요하다.
	  빠르게 계산하기 위해 부분합을 이용한다.
 알고리즘: dfs + dp + 부분합
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 50 + 1;
int psum[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];
int n, m;

int dfs(int x, int y, int r, int c) {
	int &ret = dp[x][y][r][c];
	if (ret != -1) return ret;
	
	ret = INF;
	int sum = psum[x+r-1][y+c-1];
	sum -= psum[x-1][y+c-1] + psum[x+r-1][y-1] - psum[x-1][y-1];
	for (int k = 1; k < r; ++k)
		ret = min(ret, sum + dfs(x, y, k, c) + dfs(x+k, y, r-k, c));
	for (int k = 1; k < c; ++k)
		ret = min(ret, sum + dfs(x, y, r, k) + dfs(x, y+k, r, c-k));
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dp[i][j][1][1] = 0;
				scanf("%d", &psum[i][j]);
				psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
			}
		}
		printf("#%d %d\n", tc, dfs(1, 1, n, m));
	}
	return 0;
}
