//
//  11438_LCA 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/17.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
const int max_depth = (int)floor(log2(MAX));
vector<int> graph[MAX];
int ac[MAX][20];
int depth[MAX];

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
	int n, m;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	depth[0] = -1;
	make_tree(1, 0);
	
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
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
		cout << lca << '\n';
	}
	return 0;
}
