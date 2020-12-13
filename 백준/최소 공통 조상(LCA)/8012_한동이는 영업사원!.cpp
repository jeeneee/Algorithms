//
//  8012_한동이는 영업사원!.cpp
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

const int MAX = 30000 + 1;
const int max_depth = floor(log2(MAX));
int depth[MAX];
int ac[MAX][20];
vector<int> graph[MAX];

void make_tree(int child, int parent) {
	depth[child] = depth[parent] + 1;
	ac[child][0] = parent;
	for (int i = 1; i <= max_depth; ++i)
		ac[child][i] = ac[ac[child][i-1]][i-1];
	for (auto& ch : graph[child])
		if (ch != parent)
			make_tree(ch, child);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	depth[0] = -1;
	make_tree(1, 0);
	
	int m, ans = 0;
	cin >> m;
	vector<int> city(m+1);
	city[0] = 1;
	for (int i = 1; i <= m; ++i)
		cin >> city[i];
	
	for (int i = 0; i < m; ++i) {
		int a = city[i];
		int b = city[i+1];
		int depth_a = depth[a];
		int depth_b = depth[b];
		
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
		ans += depth_a + depth_b - 2 * depth[lca];
	}
	cout << ans << '\n';
	return 0;
}
