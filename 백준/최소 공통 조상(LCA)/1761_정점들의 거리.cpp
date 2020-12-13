//
//  1761_정점들의 거리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/17.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 40000 + 1;
const int max_depth = floor(log2(MAX));
int depth[MAX];
int dist[MAX];
int ac[MAX][16];
vector<pii> graph[MAX];

void make_tree(int child, int parent, int d) {
	depth[child] = depth[parent] + 1;
	dist[child] = dist[parent] + d;
	ac[child][0] = parent;
	for (int i = 1; i <= max_depth; ++i)
		ac[child][i] = ac[ac[child][i-1]][i-1];
	for (auto& ch : graph[child])
		if (ch.first != parent)
			make_tree(ch.first, child, ch.second);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		graph[u].push_back( {v, d} );
		graph[v].push_back( {u, d} );
	}
	
	depth[0] = -1;
	make_tree(1, 0, 0);
	
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		int dist_a = dist[a];
		int dist_b = dist[b];
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b])
				swap(a, b);
			for (int i = max_depth; i >= 0; --i)
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
		}
		
		int lca = a;
		
		if (a != b) {
			for (int i = max_depth; i >= 0; --i) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		int ans = dist_a + dist_b - 2 * dist[lca];
		cout << ans << '\n';
	}
	return 0;
}
