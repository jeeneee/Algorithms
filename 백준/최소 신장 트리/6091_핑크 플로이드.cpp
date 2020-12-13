//
//  6091_핑크 플로이드.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 가중치가 있는 트리에 플로이드-와셜 알고리즘을 적용한 인접 행렬이 주어지고 인접 리스트로 다시 표현하는 문제.
 해설: 거리에 대한 오름차 순으로 정렬하여 그리디하게 간선을 저장해준다. 여기서 다른 간선을 거치는 것을 막기 위해
	  disjoint-set을 이용한다.
 알고리즘: 최소 스패닝 트리(MST)
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pipii;
const int MAX = 1024 + 1;
int parent[MAX];
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
vector<vector<int>> graph;

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
	graph.resize(n+1);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		for (int j = i+1; j <= n; ++j) {
			int d; cin >> d;
			pq.push( {d, {i, j}} );
		}
	}
	int cnt = 0;
	while (cnt < n-1) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		if (find(u) == find(v)) continue;
		cnt++;
		merge(u, v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		cout << graph[i].size();
		sort(graph[i].begin(), graph[i].end());
		for (int j = 0; j < graph[i].size(); ++j)
			cout << ' ' << graph[i][j];
		cout << '\n';
	}
	return 0;
}
