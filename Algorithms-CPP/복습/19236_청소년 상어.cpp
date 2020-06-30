//
//  19236_청소년 상어.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/30.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 상어가 매번 최대 3마리를 먹을 수 있으므로 맵을 유지시켜야 한다.
 맵과 물고기 상태를 복사하여 백트래킹을 이용하였다.
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Fish {
	int x, y;
	int d;
	bool alive;
};

const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int MAX = 4;
int ans;

bool inRange(int x, int y) {
	return (0 <= x && x < MAX) && (0 <= y && y < MAX);
}

void dfs(Fish shark, Fish* fish, int map[][4], int total) {
	ans = max(ans, total);
	for (int i = 1; i <= MAX * MAX; ++i) {
		if (!fish[i].alive) continue;
		for (int d = 0; d < 8; ++d) {
			int x = fish[i].x;
			int y = fish[i].y;
			int nd = (fish[i].d + d) % 8;
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (!inRange(nx, ny) || (nx == shark.x && ny == shark.y)) continue;
			int curIdx = map[x][y];
			int nextIdx = map[nx][ny];
			fish[nextIdx] = {x, y, fish[nextIdx].d, fish[nextIdx].alive};
			fish[curIdx] = {nx, ny, nd, true};
			swap(map[x][y], map[nx][ny]);
			break;
		}
	}
	int x = shark.x;
	int y = shark.y;
	int d = shark.d;
	
	for (int i = 1; i <= 3; ++i) {
		int nx = x + dx[d] * i;
		int ny = y + dy[d] * i;
		if (!inRange(nx, ny)) break;
		if (map[nx][ny] == 0) continue;
		
		Fish c_fish[MAX * MAX + 1];
		int c_map[MAX][MAX];
		for (int j = 1; j <= MAX * MAX; ++j)
			c_fish[j] = fish[j];
		for (int j = 0; j < MAX; ++j)
			for (int k = 0; k < MAX; ++k)
				c_map[j][k] = map[j][k];
		int score = c_map[nx][ny];
		c_map[nx][ny] = 0;
		c_fish[score].alive = false;
		shark.x = nx;
		shark.y = ny;
		shark.d = c_fish[score].d;
		dfs(shark, c_fish, c_map, total + score);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	Fish fish[MAX * MAX + 1];
	int map[MAX][MAX];
	int idx, dir;
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cin >> idx >> dir;
			fish[idx] = {i, j, dir-1, true};
			map[i][j] = idx;
		}
	}
	int score = map[0][0];
	map[0][0] = 0;
	fish[score].alive = false;
	ans = 0;
	dfs({ 0, 0, fish[score].d, true }, fish, map, score);
	cout << ans << endl;
	return 0;
}
