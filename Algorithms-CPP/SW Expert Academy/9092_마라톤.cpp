//
//  9092_마라톤.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/19.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 포인트가 최대 500개 주어지고 k개의 포인트를 건너뛰어 최소 거리를 구하는 문제.
 해설: 완전 탐색으로 한다면 2^498의 경우의 수를 모두 탐색해야 하므로 동적계획법을 이용해야 한다.
	  현재 포인트를 기준점으로 건너뛸 횟수에 대해 다이나믹하게 프로그래밍한다.
 알고리즘: DP
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};
const int INF = 987654321;
const int MAX = 500;
Point point[MAX];
int dp[MAX][MAX];
int n, k;

inline int dist(int a, int b) {
	return abs(point[a].x - point[b].x) + abs(point[a].y - point[b].y);
}

// now=현재 포인트, cnt=건너뛸 횟수
int solve(int now, int cnt) {
	if (now == n-1) return 0;
	int &ret = dp[now][cnt];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int i = 0; i <= cnt; ++i) {
		int next = now + i + 1;
		if (next > n-1) break;
		ret = min(ret, dist(now, next) + solve(next, cnt-i));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> point[i].x >> point[i].y;
		memset(dp, -1, sizeof(dp));
		cout << '#' << tc << ' ' << solve(0, k) << '\n';
	}
	return 0;
}
