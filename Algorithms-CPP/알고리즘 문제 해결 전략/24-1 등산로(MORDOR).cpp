//
//  24-1 등산로(MORDOR).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = 123456789;

struct RMQ {
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& array) {
		n = (int)array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n-1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return INF;
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node*2, nodeLeft, mid),
				   query(left, right, node*2+1, mid+1, nodeRight));
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1);
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, q, x;
		scanf("%d %d", &n, &q);
		vector<int> arr(n), arr2(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			arr[i] = x;
			arr2[i] = -x;
		}
		RMQ minRmq(arr), maxRmq(arr2);
		while (q--) {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d\n", -maxRmq.query(a, b) - minRmq.query(a, b));
		}
	}
	return 0;
}
