//
//  2105_[모의 SW 역량테스트] 디저트 카페.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/13.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = { 1, 1, -1, -1 };
const int dy[] = { 1, -1, -1, 1 };
const int MAX = 20;
int map[MAX][MAX];
bool visited[101];
int n, ans;

bool isPossible(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n) && !visited[map[x][y]];
}

void dfs(int x, int y, int sx, int sy, int d, int cnt) {
	if (x == sx && y == sy) {
		ans = max(ans, cnt);
		return;
	}
	for (int i = 0; i < 2; ++i) {
		if (d + i >= 4) return;
		int nx = x + dx[d+i];
		int ny = y + dy[d+i];
		if (isPossible(nx, ny)) {
			visited[map[nx][ny]] = true;
			dfs(nx, ny, sx, sy, d+i, cnt+1);
			visited[map[nx][ny]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];
		ans = -1;
		for (int i = 0; i < n-2; ++i) {
			for (int j = 1; j < n-1; ++j) {
				int nx = i + dx[0];
				int ny = j + dy[0];
				if (isPossible(nx, ny)) {
					visited[map[nx][ny]] = true;
					dfs(nx, ny, i, j, 0, 1);
					visited[map[nx][ny]] = false;
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
