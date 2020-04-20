//
//  2573_빙산.cpp
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
const int MAX = 300;
int map[MAX][MAX], c_map[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

void melt() {
	memcpy(c_map, map, sizeof(map));
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (map[x][y] > 0) {
				int cnt = 0;
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (map[nx][ny] == 0)
						++cnt;
				}
				c_map[x][y] -= cnt;
				if (c_map[x][y] < 0) c_map[x][y] = 0;
			}
		}
	}
	memcpy(map, c_map, sizeof(map));
}

void mark(int sx, int sy) {
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
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] > 0 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push( {nx, ny} );
			}
		}
	}
}

// 1=모두 녹음, 2=땅 하나, 3=땅 두 개 이상
int check() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(visited, false, sizeof(visited));
	bool flag = false;
	bool noLand = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] > 0 && !visited[i][j]) {
				noLand = false;
				mark(i, j);
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (noLand) return 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] > 0 && !visited[i][j])
				return 3;
	return 2;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	int ans = 0;
	while (1) {
		++ans;
		melt();
		int res = check();
		if (res == 1) {
			ans = 0;
			break;
		}
		else if (res == 3)
			break;
	}
	cout << ans << '\n';
}
