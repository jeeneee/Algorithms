//
//  3653_영화 수집.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/24.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 쿼리 수만큼 트리를 더 늘리는 게 포인트.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}
	int sum(int pos) {
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos -= (pos & -pos);
		}
		return ret;
	}
	void add(int pos, int val) {
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		FenwickTree tree(n + m);
		vector<int> floor(n + m);
		// init
		for (int i = 1; i <= n; ++i) {
			floor[i] = n - i + 1;
			tree.add(i, 1);
		}
		int next = n + 1;
		// query
		for (int i = 0; i < m; ++i) {
			int val;
			scanf("%d", &val);
			printf("%d ", tree.sum(n+m) - tree.sum(floor[val]));
			tree.add(floor[val], -1);
			floor[val] = next++;
			tree.add(floor[val], 1);
		}
		printf("\n");
	}
	return 0;
}
