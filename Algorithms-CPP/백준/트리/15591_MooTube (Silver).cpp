//
//  15591_MooTube (Silver).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/14.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 최대 노드 개수가 5000이므로 BFS를 통해 구할 수 있다. 수가 늘어나면 유니온 파인드를 고려할 수 있다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 5000;
vector<pair<int, int>> graph[MAX+1];
int N, Q;

int bfs(int k, int v) {
	int ret = 0;
	queue<int> q;
	vector<bool> visited(MAX+1, false);
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < graph[now].size(); ++i) {
			int adj = graph[now][i].first;
			int similarity = graph[now][i].second;
			if (!visited[adj] && similarity >= k) {
				visited[adj] = true;
				q.push(adj);
				++ret;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int p, q, r, k, v;
	cin >> N >> Q;
	for (int i = 0; i < N-1; ++i) {
		cin >> p >> q >> r;
		graph[p].push_back({ q, r });
		graph[q].push_back({ p, r });
	}
	for (int i = 0; i < Q; ++i) {
		cin >> k >> v;
		cout << bfs(k, v) << '\n';
	}
	return 0;
}
