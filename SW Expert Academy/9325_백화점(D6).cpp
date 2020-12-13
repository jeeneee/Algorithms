//
//  9325_백화점(D6).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/18.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: n개의 물건에서 연속된 d개의 물건을 공짜로 얻을 수 있으며 p원 안으로 가장 많은 물건을 사는 문제.
 해설: 연속으로 골라야 하므로 부분합과 세그먼트 트리를 이용했다.
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2000002;
long long psum[MAX], temp[MAX], tree[4200000];
long long p;
int n, d;

long long init(int node, int left, int right) {
	if (left == right)
		return tree[node] = temp[left];
	int mid = (left + right) >> 1;
	return tree[node] = max(init(node*2, left, mid),
							init(node*2+1, mid+1, right));
}

long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 0;
	if (left <= nodeLeft && nodeRight <= right) return tree[node];
	int mid = (nodeLeft + nodeRight) >> 1;
	return max(query(left, right, node*2, nodeLeft, mid),
			   query(left, right, node*2+1, mid+1, nodeRight));
}

long long query(int left, int right) {
	return query(left, right, 1, 0, n-d);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> p >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> psum[i];
			psum[i] += psum[i-1];
		}
		for (int i = d; i <= n; ++i)
			temp[i-d] = psum[i] - psum[i-d];
		
		init(1, 0, n-d);
		
		int l = 0, r = d, ans = 0, pos = 0;
		long long discount = 0, t = 0;
		while (r <= n) {
			t = temp[r-d];
			if (t > discount) {
				discount = t;
				pos = r-d;
			}
			if (psum[r] - psum[l] - discount > p) {
				++l;
				if (l >= r) ++r;
				if (pos < l) discount = query(l, r-d);
			} else {
				ans = max(ans, r-l);
				++r;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
