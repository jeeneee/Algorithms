//
//  1395_스위치.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segmentTree {
	int n;
	vector<int> rangeSum;
	vector<bool> lazy;
	segmentTree(int _n) : n(_n) {
		rangeSum.resize(n * 4, 0);
		lazy.resize(n * 4, 0);
	}
	void updateLazy(int node, int nodeLeft, int nodeRight) {
		if (lazy[node]) {
			rangeSum[node] = nodeRight - nodeLeft + 1 - rangeSum[node];
			if (nodeLeft != nodeRight) {
				lazy[node*2] = !lazy[node*2];
				lazy[node*2+1] = !lazy[node*2+1];
			}
			lazy[node] = 0;
		}
	}
	int updateSum(int left, int right, int node, int nodeLeft, int nodeRight) {
		updateLazy(node, nodeLeft, nodeRight);
		
		if (right < nodeLeft || nodeRight < left)
			return rangeSum[node];
		
		if (left <= nodeLeft && nodeRight <= right) {
			rangeSum[node] = nodeRight - nodeLeft + 1 - rangeSum[node];
			if (nodeLeft != nodeRight) {
				lazy[node*2] = !lazy[node*2];
				lazy[node*2+1] = !lazy[node*2+1];
			}
			return rangeSum[node];
		}
		
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] = updateSum(left, right, node*2, nodeLeft, mid)
				+ updateSum(left, right, node*2+1, mid+1, nodeRight);
	}
	int updateSum(int left, int right) {
		return updateSum(left, right, 1, 1, n);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		updateLazy(node, nodeLeft, nodeRight);
		
		if (right < nodeLeft || nodeRight < left)
			return 0;
		
		if (left <= nodeLeft && nodeRight <= right)
			return rangeSum[node];
		
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node*2, nodeLeft, mid) +
				query(left, right, node*2+1, mid+1, nodeRight);
	}
	int query(int left, int right) {
		return query(left, right, 1, 1, n);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	segmentTree rsq(n);
	while (m--) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0)
			rsq.updateSum(a, b);
		else
			cout << rsq.query(a, b) << '\n';
	}
	return 0;
}
