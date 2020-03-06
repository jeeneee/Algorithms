//
//  15685_드래곤 커브.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 10세대에 해당하는 모든 방향들을 저장하는 것이 핵심.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 동북서남
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
int pattern[4][1024];
bool map[101][101];

void make_pattern() {
	pattern[0][0] = 0;
	pattern[1][0] = 1;
	pattern[2][0] = 2;
	pattern[3][0] = 3;
	for (int d = 0; d < 4; ++d) {
		for (int g = 1; g <= 10; ++g) {
			int i = pow(2, g-1);
			int j = i - 1;
			for (; j >= 0; --j, ++i)
				pattern[d][i] = (pattern[d][j] + 1) % 4;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	make_pattern();
	while (n--) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		map[x][y] = 1;
		for (int i = 0; i < (int)pow(2, g); ++i) {
			x += dx[pattern[d][i]];
			y += dy[pattern[d][i]];
			map[x][y] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
				++ans;
	cout << ans << '\n';
	return 0;
}
