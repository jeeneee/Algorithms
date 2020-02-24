//
//  24-2 족보 탐험(FAMILYTREE).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/24.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000;
const int max_depth = floor(log2(MAX));
vector<int> graph[MAX];
int depth[MAX];
int ac[MAX][17];

void make_tree(int parent, int child) {
	depth[child] = depth[parent] + 1; // depth[0] = 0
	ac[child][0] = parent; // ac[0][0] = 0
	for (int i = 1; i <= max_depth; ++i)
		ac[child][i] = ac[ac[child][i-1]][i-1];
	for (auto &ch : graph[child])
		make_tree(child, ch);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(ac, -1, sizeof(ac));
		memset(depth, -1, sizeof(depth));
		for (int i = 0; i <= n; ++i)
			graph[i].clear();
		for (int ch = 1; ch <= n-1; ++ch) {
			int par;
			scanf("%d", &par);
			graph[par].push_back(ch);
		}
		depth[0] = -1;
		make_tree(0, 0);
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
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
			printf("%d\n", depth_a + depth_b - 2 * depth[lca]);
		}
	}
	return 0;
}
