//
//  16393_Lost Map.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pipii;
const int MAX = 2500 + 1;
int parent[MAX];
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
vector<pair<int, int>> graph;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u < v) swap(u, v);
	parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		for (int j = 1; j <= n; ++j) {
			int d; cin >> d;
			if (j > i) pq.push( {d, {i, j}} );
		}
	}
	int cnt = 0;
	while (cnt < n-1) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		if (find(u) == find(v)) continue;
		merge(u, v);
		graph.push_back( {u, v} );
		cnt++;
	}
	sort(graph.begin(), graph.end());
	for (auto& edge: graph)
		cout << edge.first << ' ' << edge.second << '\n';
	return 0;
}
