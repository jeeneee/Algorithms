//
//  11658_구간 합 구하기 3.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/02.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 배열의 값이 바뀔 때, 펜윅 트리로 2차원 구간 합을 구하는 문제.
	  기존 배열의 값에 업데이트할 값을 더하는 것이 아닌 변경하는 문제이므로 업데이트 시에 유의해야 한다.
	  1차원 배열과 비교하자면 for문이 하나 더 추가 된 것과 sum을 구할 때 부분합을 이용해 구하는 것
	  말고는 별 차이가 없다.
 알고리즘: Fenwick Tree
 O(MlogN)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree {
	int n;
	vector<vector<int>> rangeSum;
	FenwickTree(int _n) : n(_n+1) {
		rangeSum.assign(n, vector<int>(n));
	}
	// [x][y]
	void update(int x, int y, int value) {
		for (int i = x; i < n; i += (i&-i))
			for (int j = y; j < n; j += (j&-j))
				rangeSum[i][j] += value;
	}
	int query(int x, int y) {
		int ret = 0;
		for (int i = x; i > 0; i -= (i&-i))
			for (int j = y; j > 0; j -= (j&-j))
				ret += rangeSum[i][j];
		return ret;
	}
	int query(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x1-1, y2)
				- query(x2, y1-1) + query(x1-1, y1-1);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	FenwickTree tree(n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int value;
			cin >> value;
			tree.update(i, j, value);
		}
	while (m--) {
		int op;
		cin >> op;
		if (op == 0) { 		// update
			int x, y, c;
			cin >> x >> y >> c;
			int temp = tree.query(x, y, x, y);
			tree.update(x, y, c - temp);
		} else { 			// query
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << tree.query(x1, y1, x2, y2) << '\n';
		}
	}
	return 0;
}
