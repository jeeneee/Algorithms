//
//  10868_최솟값.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct segmentTree {
	int n;
	vector<int> rangeMin;
	segmentTree(const vector<int>& array) {
		n = (int)array.size();
		rangeMin.resize(n * 4);
		init(array, 1, 0, n-1);
	}
	int init(const vector<int>& array, int node, int left, int right) {
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		return rangeMin[node] = min(init(array, node*2, left, mid),
									init(array, node*2+1, mid+1, right));
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return INT_MAX;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node*2, nodeLeft, mid),
				   query(left, right, node*2+1, mid+1, nodeRight));
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	segmentTree rmq(arr);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << rmq.query(a, b) << '\n';
	}
	return 0;
}
