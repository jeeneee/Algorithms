//
//  15681_트리와 쿼리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/16.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
int num[MAX];
vector<int> tree[MAX];

void dfs(int root) {
	num[root] = 1;
	for (int& ch : tree[root]) {
		if (!num[ch]) {
			dfs(ch);
			num[root] += num[ch];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m, root, u, v;
	cin >> n >> root >> m;
	
	for (int i = 0; i < n-1; ++i) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	dfs(root);
	
	while (m--) {
		int q;
		cin >> q;
		cout << num[q] << '\n';
	}
	return 0;
}
