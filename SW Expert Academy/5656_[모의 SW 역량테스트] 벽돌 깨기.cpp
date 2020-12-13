//
//  5656_[모의 SW 역량테스트] 벽돌 깨기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/05.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 공이 떨어져서 벽돌의 숫자-1만큼 사방으로 퍼져 벽돌을 깬다.
 해설: 최대 12^4=20736 가지의 방법으로 공을 떨어뜨릴 수 있다. 백트래킹에서 지역 변수로 c_map을 정의하는 데
	  주의하자.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int map[15][12];
int N, W, H, ans;

bool inRange(int x, int y) {
	return (0 <= x && x < H) && (0 <= y && y < W);
}

void drop(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push( {{x, y}, map[x][y]} );
	map[x][y] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();
		for (int i = 1; i < k; ++i) {
			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j] * i;
				int ny = y + dy[j] * i;
				if (inRange(nx, ny) && map[nx][ny]) {
					q.push( {{nx, ny}, map[nx][ny]} );
					map[nx][ny] = 0;
				}
			}
		}
	}
}

void align() {
	for (int j = 0; j < W; ++j) {
		for (int i = H-1; i >= 0; --i) {
			if (map[i][j] == 0) {
				for (int k = i-1; k >= 0; --k) {
					if (map[k][j]) {
						map[i][j] = map[k][j];
						map[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == N) {
		int num = 0;
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j)
				if (map[i][j]) num++;
		ans = min(ans, num);
		return;
	}
	int c_map[15][12];
	memcpy(c_map, map, sizeof(map));
	for (int j = 0; j < W; ++j) {
		int x = 0, y = j;
		while (inRange(x, y) && map[x][y] == 0) x++;
		if (x == H) continue;
		drop(x, y);
		align();
		dfs(cnt+1);
		memcpy(map, c_map, sizeof(map));
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d %d", &N, &W, &H);
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j)
				scanf("%d", &map[i][j]);
		ans = INF;
		dfs(0);
		if (ans == INF) ans = 0;
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
