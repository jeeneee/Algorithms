//
//  10999_구간 합 구하기 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 업데이트 시에 한 원소만 더하는 것이 아닌 한 구간의 원소들을 다 더하는 것임으로,
 lazy propagation을 이용해야 한다.
 lazy라는 말 그대로 게으르게 한번에 아래까지 더하는 것이 아닌 아래까지 내려가야 할 경우가 생길 때에만
 더해주고 자식 노드로 보내주는 식이다.
 */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

struct segmentTree {
	int n;
	vector<ll> rangeSum;
	vector<ll> lazy;
	segmentTree(const vector<int>& array) {
		n = (int)array.size();
		rangeSum.resize(n * 4);
		lazy.resize(n * 4, 0);
		init(array, 1, 0, n-1);
	}
	ll init(const vector<int>& array, int node, int left, int right) {
		if (left == right)
			return rangeSum[node] = array[left];
		int mid = (left + right) / 2;
		return rangeSum[node] = init(array, node*2, left, mid) + init(array, node*2+1, mid+1, right);
	}
	ll update(int i, int j, ll toPlus, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			rangeSum[node] += (nodeRight - nodeLeft + 1) * lazy[node];
			if (nodeLeft != nodeRight) {
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		
		if (j < nodeLeft || nodeRight < i)
			return rangeSum[node];
		
		if (i <= nodeLeft && nodeRight <= j) {
			rangeSum[node] += (nodeRight - nodeLeft + 1) * toPlus;
			if (nodeLeft != nodeRight) {
				lazy[node*2] += toPlus;
				lazy[node*2+1] += toPlus;
			}
			return rangeSum[node];
		}
		
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] = update(i, j, toPlus, node*2, nodeLeft, mid) + update(i, j, toPlus, node*2+1, mid+1, nodeRight);
	}
	ll update(int i, int j, ll toPlus) {
		return update(i, j, toPlus, 1, 0, n-1);
	}
	ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			rangeSum[node] += (nodeRight - nodeLeft + 1) * lazy[node];
			if (nodeLeft != nodeRight) {
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (right < nodeLeft || nodeRight < left)
			return 0;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node*2, nodeLeft, mid) + query(left, right, node*2+1, mid+1, nodeRight);
	}
	ll query(int left, int right) {
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
	
	segmentTree rsq(arr);
	
	for (int i = 0; i < m+k; ++i) {
		int a, b, c;
		ll d;
		cin >> a >> b >> c;
		b--; c--;
		// update
		if (a == 1) {
			cin >> d;
			rsq.update(b, c, d);
		} else {
			cout << rsq.query(b, c) << '\n';
		}
	}
	return 0;
}
