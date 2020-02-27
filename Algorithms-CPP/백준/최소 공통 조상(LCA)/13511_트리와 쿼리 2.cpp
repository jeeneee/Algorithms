//
//  13511_트리와 쿼리 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/27.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 가중치가 있는 트리 + k번째 수를 구하는 쿼리를 포함한다.
 거리는 기존처럼 depth[u] + depth[v] - 2 * depth[lca]로 구하면 되고,
 k번째 수는 u와 v가 한 가지에 있는 지에 따라 두 개의 상황으로 나누어 구한다.
 여기서는 다른 문제와 다르게 k를 조정하여 u 또는 v에서 k 조상만큼 올라가게 되는데,
 올라가는 과정에서 k값을 바꾸며 진행한다. 이렇게 하면 정답의 depth를 먼저 구하고 풀지 않아도 된다.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 100000 + 1;
const int max_depth = floor(log2(MAX));
int ac[MAX][17], parent[MAX], depth[MAX];
ll dist[MAX]; // 여기서 dist는 루트 1에서의 거리이다.
vector<pii> graph[MAX];

void makeTree(int child, int parent, int d) {
	depth[child] = depth[parent] + 1;
	dist[child] = dist[parent] + d;
	ac[child][0] = parent;
	for (int i = 1; i <= max_depth; ++i)
		ac[child][i] = ac[ac[child][i-1]][i-1];
	// dfs
	for (auto& ch : graph[child])
		if (ch.first != parent)
			makeTree(ch.first, child, ch.second);
}

int getLCA(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);
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
	return lca;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		graph[u].push_back( {v, d} );
		graph[v].push_back( {u, d} );
	}
	
	depth[0] = -1;
	makeTree(1, 0, 0);
	
	cin >> m;
	while (m--) {
		int op, u, v, k;
		cin >> op;
		// u에서 v로 가는 경로의 비용을 출력
		if (op == 1) {
			cin >> u >> v;
			cout << dist[u] + dist[v] - 2 * dist[getLCA(u, v)] << '\n';
		} else { // u에서 v로 가는 k번째 수를 출력
			int ans = 0;
			cin >> u >> v >> k;
			int lca = getLCA(u, v);
			// 한 가지에 있을 경우
			if (depth[u] - depth[lca] >= k - 1) {
				k--;
				// k 조상만큼 올라간다. depth를 구할 필요가 없다.
				for (int i = max_depth; i >= 0; --i)
					if ((1 << i) <= k) {
						k -= (1 << i);
						u = ac[u][i];
					}
				ans = u;
			} else {
				// 아래를 보면 알 수 있듯이 u부터 v까지의 노드 수에서 k를 뺀다.
				// u에서 출발하고 다른 가지에 있다는 것을 알기 때문에 v에서 k조상만큼 올라가면 된다
				k = depth[u] + depth[v] - 2 * depth[lca] - k + 1;
				for (int i = max_depth; i >= 0; --i)
					if ((1 << i) <= k) {
						k -= (1 << i);
						v = ac[v][i];
					}
				ans = v;
			}
			cout << ans << '\n';
		}
	}
}
