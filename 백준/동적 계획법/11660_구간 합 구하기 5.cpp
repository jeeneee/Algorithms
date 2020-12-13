//
//  11660_구간 합 구하기 5.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 1025;
int psum[MAX][MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> psum[i][j];
			psum[i][j] += psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1];
		}
	while (m--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int res = psum[x2][y2];
		res = res - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
		cout << res << '\n';
	}
	return 0;
}
