//
//  5427_불.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/22.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct coord {
	int x, y;
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 1000;
char map[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

int bfs(queue<coord>& sq, queue<coord>& fq) {
	int step = 0;
	while (!fq.empty() || !sq.empty()) {
		step++;
		int fq_size = fq.size();
		while (fq_size--) {
			int x = fq.front().x;
			int y = fq.front().y;
			fq.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
					if (map[nx][ny] != '#' && map[nx][ny] != '*') {
						map[nx][ny] = '*';
						fq.push( {nx, ny} );
					}
				}
			}
		}
		int sq_size = sq.size();
		while (sq_size--) {
			int x = sq.front().x;
			int y = sq.front().y;
			sq.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) return step;
				if (map[nx][ny] == '.' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					sq.push( {nx, ny} );
				}
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		queue<coord> sq, fq;
		memset(visited, false, sizeof(visited));
		cin >> m >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					sq.push( {i, j} );
					visited[i][j] = true;
				}
				else if (map[i][j] == '*') fq.push( {i, j} );
			}
		}
		int ans = bfs(sq, fq);
		if (ans) cout << ans << '\n';
		else cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}
