//
//  17435_합성함수와 쿼리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/26.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 ac가 꼭 조상이 아니어도 된다. 이것이 sparse table.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 500001 + 1;
const int max_depth = floor(log2(MAX));
int ac[MAX][19];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, q;
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> ac[i][0];
	// make sparse table
	for (int j = 1; j <= max_depth; ++j)
		for (int i = 1; i <= m; ++i)
			ac[i][j] = ac[ac[i][j-1]][j-1];
	// query
	cin >> q;
	while (q--) {
		int n, x;
		cin >> n >> x;
		while (n) {
			x = ac[x][(int)log2(n & -n)];
			n -= (n & -n);
		}
		cout << x << '\n';
	}
	return 0;
}
