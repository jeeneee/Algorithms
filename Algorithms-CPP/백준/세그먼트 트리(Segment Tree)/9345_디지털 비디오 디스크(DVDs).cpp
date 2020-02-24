//
//  9345_디지털 비디오 디스크(DVDs).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 차례대로 정렬되어 있기 때문에 최소값, 최대값을 이용하면 풀 수 있다.
 */
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
	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node];
		if (nodeLeft == nodeRight)
			return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = min(update(index, newValue, node*2, nodeLeft, mid),
									update(index, newValue, node*2+1, mid+1, nodeRight));
	}
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n-1);
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
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		vector<int> arr(n), arr2(n);
		for (int i = 0; i < n; ++i) {
			arr[i] = i;
			arr2[i] = -i;
		}
		
		segmentTree rangeMinQuery(arr);
		segmentTree rangeMaxQuery(arr2);

		// query
		while (k--) {
			int q, a, b;
			scanf("%d %d %d", &q, &a, &b);
			if (q == 0) {
				rangeMinQuery.update(a, arr[b]);
				rangeMinQuery.update(b, arr[a]);
				rangeMaxQuery.update(a, arr2[b]);
				rangeMaxQuery.update(b, arr2[a]);
				swap(arr[a], arr[b]);
				swap(arr2[a], arr2[b]);
			} else {
				int minValue = rangeMinQuery.query(a, b);
				int maxValue = -rangeMaxQuery.query(a, b);
				if (minValue == a && maxValue == b)
					puts("YES");
				else
					puts("NO");
			}
		}
	}
	return 0;
}
