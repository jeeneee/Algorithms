//
//  24-3 삽입 정렬 시간 재기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/24.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}
	int sum(int pos) {
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos-1);
		}
		return ret;
	}
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

long long countMoves(const vector<int>& A) {
	FenwickTree tree(1000000);
	long long ret = 0;
	for (auto& a : A) {
		ret += tree.sum(999999) - tree.sum(a);
		tree.add(a, 1);
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		printf("%lld\n", countMoves(arr));
	}
	return 0;
}
