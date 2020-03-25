//
//  5650_[모의 SW 역량테스트] 핀볼 게임.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/25.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 핀볼 시뮬레이션
 알고리즘: BFS
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
// 동북서남
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int MAX = 100 + 2;
int map[MAX][MAX];
pair<pii, pii> wormhole[5];
int n, ans;

void go(int x, int y, int d) {
	int xx = x, yy = y;
	int cnt = 0;
	while (1) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (map[nx][ny] == -1 || (nx == xx && ny == yy)) {
			ans = max(ans, cnt);
			return;
		}
		if (1 <= map[nx][ny] && map[nx][ny] <= 5) {
			if (map[nx][ny] == 1) {
				if (d == 2) d = 1;
				else if (d == 3) d = 0;
				else d = (d + 2) % 4;
			} else if (map[nx][ny] == 2) {
				if (d == 1) d = 0;
				else if (d == 2) d = 3;
				else d = (d + 2) % 4;
			} else if (map[nx][ny] == 3) {
				if (d == 0) d = 3;
				else if (d == 1) d = 2;
				else d = (d + 2) % 4;
			} else if (map[nx][ny] == 4) {
				if (d == 0) d = 1;
				else if (d == 3) d = 2;
				else d = (d + 2) % 4;
			} else if (map[nx][ny] == 5) {
				d = (d + 2) % 4;
			}
			cnt++;
		} else if (6 <= map[nx][ny] && map[nx][ny] <= 10) {
			int x1 = wormhole[map[nx][ny] - 6].first.first;
			int y1 = wormhole[map[nx][ny] - 6].first.second;
			int x2 = wormhole[map[nx][ny] - 6].second.first;
			int y2 = wormhole[map[nx][ny] - 6].second.second;
			if (nx == x1 && ny == y1) {
				nx = x2; ny = y2;
			} else {
				nx = x1; ny = y1;
			}
		}
		x = nx;
		y = ny;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
 		cin >> n;
		for (int i = 0; i <= n+1; ++i)
			for (int j = 0; j <= n+1; ++j)
				map[i][j] = 5;
		for (int i = 0; i < 5; ++i)
			wormhole[i] = {{0, 0}, {0, 0}};
		ans = 0;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> map[i][j];
				if (map[i][j] >= 6) {
					if (wormhole[map[i][j] - 6].first.first == 0)
						wormhole[map[i][j] - 6].first = {i, j};
					else
						wormhole[map[i][j] - 6].second = {i, j};
				}
			}
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 0; k < 4; ++k)
					if (map[i][j] == 0)
						go(i, j, k);
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
