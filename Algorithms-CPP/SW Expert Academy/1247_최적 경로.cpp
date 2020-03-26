//
//  1247_최적 경로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/26.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 회사 -> 최대 10개 고객 집 -> 집, 이 경로의 최단 거리를 구하는 문제
 해설: 백트래킹으로 풀었으나, 중복이 있기 때문에 시간이 오래 걸린다.
	  쓰인 경로를 저장하는 목적으로 비트 마스킹을 이용하고 이전 경로를 알아야 하기 때문에 함수에 매개변수로
	  이전 경로를 주었다.
 알고리즘: DFS + BackTracking, DFS + DP + Bit Masking
 */
// DFS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = 987654321;
vector<pii> pos;
vector<int> cand;
pii company, home;
bool visited[10];
int n, ans;

int dist(pii& a, pii& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int cnt) {
	if (cnt == n) {
		int d = 0;
		d += dist(company, pos[cand[0]]);
		for (int i = 0; i+1 < n; ++i)
			d += dist(pos[cand[i]], pos[cand[i+1]]);
		d += dist(pos[cand[n-1]], home);
		ans = min(ans, d);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		cand.push_back(i);
		dfs(cnt+1);
		cand.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		cin >> company.first >> company.second;
		cin >> home.first >> home.second;
		memset(visited, false, sizeof(visited));
		cand.clear();
		pos.clear();
		pos.resize(n);
		ans = INF;
		for (int i = 0; i < n; ++i)
			cin >> pos[i].first >> pos[i].second;
		dfs(0);
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
// DP
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 12;
const int INF = 987654321;
pii pos[MAX];
int d[MAX][MAX], dp[1<<MAX][MAX];
int n, ans;

int dist(pii& a, pii& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int move(int used, int prev) {
	if (used == (1<<(n+2))-4) return d[prev][1];
	int& ret = dp[used][prev];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 2; i <= n+1; ++i)
		ret = min(ret, d[prev][i] + move(used|(1<<i), i));
	return ret;
}

void init() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i <= n+1; ++i)
		cin >> pos[i].first >> pos[i].second;
	for (int i = 0; i <= n+1; ++i)
		for (int j = 0; j <= n+1; ++j)
			d[i][j] = dist(pos[i], pos[j]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		cout << "#" << tc << " " << move(0, 0) << '\n';
	}
	return 0;
}
