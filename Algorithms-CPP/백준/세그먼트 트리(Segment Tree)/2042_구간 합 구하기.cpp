//
//  2042_구간 합 구하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/22.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 중간마다 배열의 값이 바뀔 때 업데이트를 하는 함수가 포함되어 있다.
 RangeSumQuery(RSQ)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct RSQ {
	int n;
	vector<long long> rangeSum;
	RSQ(const vector<long long>& array) {
		n = (int)array.size();
		rangeSum.resize(n * 4);
		init(array, 1, 0, n-1);
	}
	long long init(const vector<long long>& array, int node, int left, int right) {
		if (left == right)
			return rangeSum[node] = array[left];
		int mid = (left + right) / 2;
		return rangeSum[node] = init(array, node * 2, left,
									 mid) + init(array, node * 2 + 1, mid + 1, right);
	}
	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || index > nodeRight)
			return rangeSum[node];
		if (nodeLeft == nodeRight)
			return rangeSum[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	}
	long long update(int index, int newValue) {
		return update(index, newValue, 1, 0, n-1);
	}
	long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return 0;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node*2, nodeLeft,
					 mid) + query(left, right, node*2+1, mid+1, nodeRight);
	}
	long long query(int left, int right) {
		return query(left, right, 1, 0, n-1);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	RSQ rsq(arr);

	// query & update
	for (int i = 0; i < m + k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		b--;
		if (a == 1)
			rsq.update(b, c);
		else if (a == 2) {
			c--;
			cout << rsq.query(b, c) << '\n';
		}
	}
	return 0;
}
