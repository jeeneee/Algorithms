//
//  17086_아기 상어 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/13.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int MAX = 50;
int map[MAX][MAX];
bool visited[MAX][MAX];
int n, m, ans;

void bfs(int sx, int sy) {
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	q.push({{ sx, sy }, 0 });
	visited[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (map[x][y] == 1) {
			ans = max(ans, cnt);
			return;
		}
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;
			q.push({{ nx, ny }, cnt+1 });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 0) bfs(i, j);
	cout << ans << endl;
	return 0;
}
