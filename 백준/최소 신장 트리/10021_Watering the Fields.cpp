//
//  10021_Watering the Fields.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/15.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 크루스칼
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos { int x, y; };
struct Edge {
	int u, v, d;
	bool operator<(const Edge& e) const {
		return d < e.d;
	}
};
vector<Pos> fields;
vector<Edge> edges;
vector<int> parent;
int n, c;

int distance(Pos& a, Pos& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> c;
	fields.resize(n);
	parent.resize(n);
	for (int i = 0; i < n; ++i) parent[i] = i;
	for (int i = 0; i < n; ++i)
		cin >> fields[i].x >> fields[i].y;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			int d = distance(fields[i], fields[j]);
			if (d < c) continue;
			edges.push_back({ i, j, d });
		}
	}

	sort(edges.begin(), edges.end());
	
	int cnt = 0, ans = 0;
	for (auto& edge: edges) {
		int pu = find(edge.u), pv = find(edge.v);
		if (pu == pv) continue;
		parent[pv] = pu;
		++cnt;
		ans += edge.d;
		if (cnt == n-1) break;
	}
	if (cnt != n-1) ans = -1;
	cout << ans << endl;
	return 0;
}

