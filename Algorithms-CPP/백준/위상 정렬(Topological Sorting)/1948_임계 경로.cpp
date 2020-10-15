//
//  1948_임계 경로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/10/15.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, e;
vector<vector<pair<int, int>>> adj;
vector<bool> chk;
vector<int> cost;

void get_cost(int x) {
	for (auto next : adj[x]) {
		int nx = next.first;
		int nc = next.second;
		if (cost[nx] == 0) get_cost(nx);
		cost[x] = max(cost[x], cost[nx] + nc);
	}
}

void get_cnt(int x, int &cnt) {
	if (chk[x]) return;
	chk[x] = 1;
	for (auto next : adj[x]) {
		int nx = next.first;
		int nc = next.second;
		if (cost[x] - nc == cost[nx])
			get_cnt(nx, ++cnt);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	adj.resize(n+1);
	cost.resize(n+1);
	chk.resize(n+1);
	while (m--) {
		int s, e, c;
		cin >> s >> e >> c;
		adj[s].push_back({ e, c });
	}
	cin >> s >> e;

	int cnt = 0;
	get_cost(s);
	get_cnt(s, cnt);

	cout << cost[s] << endl << cnt << endl;
	return 0;
}

///*
// 위상정렬 + 역탐색
// */
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//const int MAX = 10001;
//int n, m, s, e;
//vector<pair<int, int>> adj[MAX];
//vector<pair<int, int>> radj[MAX];
//int cost[MAX];
//int indegree[MAX];
//bool chk[MAX];
//
//void dfs(int x, int &cnt) {
//	if (chk[x]) return;
//	chk[x] = 1;
//	for (auto next: radj[x])
//		if (cost[x] == cost[next.first] + next.second)
//			dfs(next.first, ++cnt);
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> n >> m;
//	while (m--) {
//		int s, e, c;
//		cin >> s >> e >> c;
//		adj[s].push_back({ e, c });
//		radj[e].push_back({ s, c });
//		indegree[e]++;
//	}
//	cin >> s >> e;
//	queue<int> q;
//	q.push(s);
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//		for (auto next : adj[x]) {
//			int nx = next.first;
//			int nc = next.second;
//			cost[nx] = max(cost[nx], cost[x] + nc);
//			if (--indegree[nx] == 0)
//				q.push(nx);
//		}
//	}
//	int cnt = 0;
//	dfs(e, cnt);
//
//	cout << cost[e] << endl << cnt << endl;
//
//	return 0;
//}
//
