//
//  16975_수열과 쿼리 21.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/02.
//  Copyright © 2020 장우진. All rights reserved.
//

/*
 문제: 구간으로 값을 업데이트하고 쿼리는 하나만 한다. 기존의 구간 합을 하나로만 받도록 바꿔 풀었다.
 알고리즘: 구간으로 값을 업데이트 하는 것이기에, Segment Tree with lazy propagation
 O(MlogN)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct SegmentTree {
	int n;
	vector<ll> rangeSum, lazy;
	SegmentTree(const vector<int>& array) {
		n = array.size();
		rangeSum.resize(n * 4);
		lazy.resize(n * 4);
		init(array, 1, 0, n-1);
	}
	ll init(const vector<int>& array, int node, int left, int right) {
		if (left == right)
			return rangeSum[node] = array[left];
		int mid = (left + right) / 2;
		return rangeSum[node] = init(array, node*2, left, mid) +
								init(array, node*2+1, mid+1, right);
	}
	void updateLazy(int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			rangeSum[node] += (nodeRight - nodeLeft + 1) * lazy[node];
			if (nodeLeft != nodeRight) {
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	ll update(int left, int right, int node, int nodeLeft, int nodeRight, int value) {
		updateLazy(node, nodeLeft, nodeRight);
		if (right < nodeLeft || nodeRight < left) return rangeSum[node];
		if (left <= nodeLeft && nodeRight <= right) {
			lazy[node] += value;
			updateLazy(node, nodeLeft, nodeRight);
			return rangeSum[node];
		}
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] = update(left, right, node*2, nodeLeft, mid, value) + update(left, right, node*2+1, mid+1, nodeRight, value);
	}
	ll update(int left, int right, int value) {
		return update(left, right, 1, 0, n-1, value);
	}
	ll query(int x, int node, int nodeLeft, int nodeRight) {
		updateLazy(node, nodeLeft, nodeRight);
		if (x < nodeLeft || nodeRight < x) return 0;
		if (nodeLeft == x && nodeRight == x)
			return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(x, node*2, nodeLeft, mid) + query(x, node*2+1, mid+1, nodeRight);
	}
	ll query(int x) {
		return query(x, 1, 0, n-1);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	SegmentTree tree(arr);
	cin >> m;
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			i--; j--;
			tree.update(i, j, k);
		} else {
			int x;
			cin >> x;
			x--;
			cout << tree.query(x) << '\n';
		}
	}
	return 0;
}
