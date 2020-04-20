//
//  2468_안전 영역.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX = 100;
int map[MAX][MAX];
bool visited[MAX][MAX];
int n;

void bfs(int sx, int sy, int k) {
	queue<pair<int, int>> q;
	q.push( {sx, sy} );
	visited[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (map[nx][ny] >= k && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push( {nx, ny} );
			}
		}
	}
}

int main() {
	cin >> n;
	int lo = 101;
	int hi = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			lo = min(lo, map[i][j]);
			hi = max(hi, map[i][j]);
		}
	int ans = 0;
	for (int k = lo; k <= hi; ++k) {
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] >= k && !visited[i][j]) {
					bfs(i, j, k);
					++cnt;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}
