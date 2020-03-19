//
//  2887_행성 터널.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/19.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 3차원에 존재하는 최대 10만 개의 행성을 모두 연결시키는 문제이다. 총 N-1개의 터널이 필요하며,
	  비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)이다.
 해설: 문제에서 보다시피 각 축의 최소값이 비용이 된다. 따라서 세 축을 기준으로 정렬하여 3*(N-1)개의
	  간선을 만들고 크루스칼 알고리즘을 이용하면 끝이다.
 알고리즘: 정렬 + 크루스칼 알고리즘
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int parent[MAX];

struct Point {
	int x, y, z, idx;
};
struct Edge {
	int cost, from, to;
	bool operator < (const Edge& e) const {
		return cost < e.cost;
	}
};
bool cmpx(const Point& a, const Point& b) {
	return a.x < b.x;
}
bool cmpy(const Point& a, const Point& b) {
	return a.y < b.y;
}
bool cmpz(const Point& a, const Point& b) {
	return a.z < b.z;
}

int getParent(int u) {
	if (u == parent[u]) return u;
	return parent[u] = getParent(parent[u]);
}

void unionParent(int u, int v) {
	u = getParent(u); v = getParent(v);
	if (u < v) swap(u, v);
	parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y >> v[i].z;
		v[i].idx = i;
		parent[i] = i;
	}
	vector<Edge> edge;
	sort(v.begin(), v.end(), cmpx);
	for (int i = 0; i+1 < n; ++i)
		edge.push_back( {v[i+1].x - v[i].x, v[i].idx, v[i+1].idx} );
	
	sort(v.begin(), v.end(), cmpy);
	for (int i = 0; i+1 < n; ++i)
		edge.push_back( {v[i+1].y - v[i].y, v[i].idx, v[i+1].idx} );
	
	sort(v.begin(), v.end(), cmpz);
	for (int i = 0; i+1 < n; ++i)
		edge.push_back( {v[i+1].z - v[i].z, v[i].idx, v[i+1].idx} );
	
	sort(edge.begin(), edge.end());
	
	int ans = 0;
	for (auto& e : edge) {
		if (getParent(e.from) == getParent(e.to)) continue;
		unionParent(e.from, e.to);
		ans += e.cost;
	}
	cout << ans << '\n';
	return 0;
}
