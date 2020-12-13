//
//  1226_미로1.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/13.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// 좌우상하
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int N = 16;
int map[N][N];

int main() {
	int T = 10;
	for (int tc = 1; tc <= T; ++tc) {
		int a;
		scanf("%d", &a);
		queue<pair<int, int>> q;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) q.push( {i, j} );
			}
		bool possible = false;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (map[x][y] == 3) {
				possible = true;
				break;
			}
			map[x][y] = 1;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((nx >= 0 && nx < N) && (ny >= 0 && ny < N)) {
					if (map[nx][ny] == 1) continue;
					q.push( {nx, ny} );
				}
			}
		}
		printf("#%d %d\n", tc, possible);
	}
	return 0;
}
