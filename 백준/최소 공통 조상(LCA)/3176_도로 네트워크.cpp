//
//  3176_도로 네트워크.cpp
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

const int INF = 123456789;
const int MAX = 100000 + 1;
const int max_depth = floor(log2(MAX));

vector<pii> graph[MAX];
int ac[MAX][17];
int mn[MAX][17];
int mx[MAX][17];
int depth[MAX];

void make_tree(int child, int parent, int d) {
	depth[child] = depth[parent] + 1;
	ac[child][0] = parent;
	mn[child][0] = d;
	mx[child][0] = d;
	for (int i = 1; i <= max_depth; ++i) {
		ac[child][i] = ac[ac[child][i-1]][i-1];
		mn[child][i] = min(mn[child][i-1], mn[ac[child][i-1]][i-1]);
		mx[child][i] = max(mx[child][i-1], mx[ac[child][i-1]][i-1]);
	}
	for (auto& ch : graph[child])
		if (ch.first != parent)
			make_tree(ch.first, child, ch.second);
}

int main() {
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < max_depth; ++j)
			mn[i][j] = INF;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);
		graph[u].push_back( {v, d} );
		graph[v].push_back( {u, d} );
	}
	
	depth[0] = -1;
	make_tree(1, 0, 0);
	
	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b, minn = INF, maxx = 0;
		scanf("%d %d", &a, &b);
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b])
				swap(a, b);
			for (int i = max_depth; i >= 0; --i)
				if (depth[a] <= depth[ac[b][i]]) {
					minn = min(minn, mn[b][i]);
					maxx = max(maxx, mx[b][i]);
					b = ac[b][i];
				}
		}
		if (a != b) {
			for (int i = max_depth; i >= 0; --i) {
				if (ac[a][i] != ac[b][i]) {
					minn = min(minn, min(mn[a][i], mn[b][i]));
					maxx = max(maxx, max(mx[a][i], mx[b][i]));
					a = ac[a][i];
					b = ac[b][i];
				}
			}
			minn = min(minn, min(mn[a][0], mn[b][0]));
			maxx = max(maxx, max(mx[a][0], mx[b][0]));
		}
		printf("%d %d\n", minn, maxx);
	}
	return 0;
}
