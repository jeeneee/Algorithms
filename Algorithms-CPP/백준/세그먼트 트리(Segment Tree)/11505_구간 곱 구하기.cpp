//
//  11505_구간 곱 구하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

struct segmentTree {
	int n;
	vector<int> rangeSum;
	segmentTree(const vector<int>& array) {
		n = (int)array.size();
		rangeSum.resize(n * 4);
		init(array, 1, 0, n-1);
	}
	int init(const vector<int>& array, int node, int left, int right) {
		if (left == right)
			return rangeSum[node] = array[left];
		int mid = (left + right) / 2;
		return rangeSum[node] = (long long)init(array, node*2, left,
												mid) * init(array, node*2+1, mid+1, right) % MOD;
	}
	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || index > nodeRight)
			return rangeSum[node];
		if (nodeLeft == nodeRight)
			return rangeSum[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] = (long long)update(index, newValue, node*2, nodeLeft, mid) * update(index, newValue, node*2+1, mid+1, nodeRight) % MOD;
	}
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n-1);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return 1;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return (long long)query(left, right, node*2, nodeLeft,
					 mid) * query(left, right, node*2+1, mid+1, nodeRight) % MOD;
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	segmentTree rmq(arr);

	// query & update
	for (int i = 0; i < m + k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		b--;
		if (a == 1)
			rmq.update(b, c);
		else if (a == 2) {
			c--;
			cout << rmq.query(b, c) << '\n';
		}
	}
	return 0;
}
