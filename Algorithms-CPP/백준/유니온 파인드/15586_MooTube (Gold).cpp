//
//  15586_MooTube (Gold).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/14.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 15591 문제는 5,000개이고 이 문제는 100,000개여서 브루트포스로 풀지 못한다.
 쿼리를 정렬하여 중복을 방지하는데 초점을 맞춘다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int p, q, r; };
struct Query { int k, v, idx; };

vector<Edge> edge;
vector<Query> query;
vector<int> parent, num, ans;
int N, Q;

int findParent(int u) {
	if (parent[u] == u) return u;
	return parent[u] = findParent(parent[u]);
}

void mergeParent(int u, int v) {
	u = findParent(u); v = findParent(v);
	if (u == v) return;
	parent[u] = v;
	num[v] += num[u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int p, q, r, k, v;
	cin >> N >> Q;
	parent.resize(N+1);
	num.assign(N+1, 1);
	ans.resize(Q);
	for (int i = 1; i <= N; ++i) parent[i] = i;
	for (int i = 0; i < N-1; ++i) {
		cin >> p >> q >> r;
		edge.push_back({ p, q, r });
	}
	for (int i = 0; i < Q; ++i) {
		cin >> k >> v;
		query.push_back({ k, v, i });
	}
	
	sort(edge.begin(), edge.end(), [](Edge& a, Edge& b) { return a.r > b.r; });
	sort(query.begin(), query.end(), [](Query& a, Query& b) { return a.k > b.k; });
	
	for (int i = 0, j = 0; i < query.size(); ++i) {
		while (j < edge.size() && edge[j].r >= query[i].k) {
			mergeParent(edge[j].p, edge[j].q);
			++j;
		}
		ans[query[i].idx] = num[findParent(query[i].v)] - 1;
	}
	
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';
	return 0;
}
