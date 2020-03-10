//
//  17141_연구소 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/10.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 바이러스가 퍼지는 평범한 조합 문제(BFS를 곁들인).
	  완전 탐색으로 중간중간마다 빈 칸이 있는지 확인해야 한다.
 알고리즘: 백트래킹 + BFS
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX = 50;
const int INF = 987654321;
int map[MAX][MAX], c_map[MAX][MAX];
vector<pair<int, int>> virus;
int N, M;
int ans = INF;

void dfs(int x, int cnt) {
	if (cnt == M) {
		queue<pair<int, int>> q;
		bool alreadyCompleted = true;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				if (map[i][j] == 2)
					q.push( {i, j} );
				else if (map[i][j] == 0)
					alreadyCompleted = false;
			}
		// 이미 빈 칸이 없는 경우
		if (alreadyCompleted) {
			ans = 0;
			return;
		}
		int step = 0;
		bool hasZero = false;
		while (!q.empty()) {
			step++;
			int size = q.size();
			hasZero = false;
			// 단계별로 바이러스 확산
			while (size--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if ((0 <= nx && nx < N) && (0 <= ny && ny < N)) {
						if (map[nx][ny] == 0) {
							map[nx][ny] = 2;
							q.push( {nx, ny} );
						}
					}
				}
			}
			// 빈 칸 확인
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (map[i][j] == 0) {
						hasZero = true;
						break;
					}
				}
				if (hasZero) break;
			}
			// 빈 칸이 없는 경우 종료
			if (!hasZero)
				break;
		}
		if (hasZero) step = INF; // 여전히 빈 칸이 있는 경우
		ans = min(ans, step);
		return;
	}
	// 백트래킹
	for (int i = x; i < virus.size(); ++i) {
		memcpy(c_map, map, sizeof(map));
		map[virus[i].first][virus[i].second] = 2;
		dfs(i+1, cnt+1);
		memcpy(map, c_map, sizeof(map));
		map[virus[i].first][virus[i].second] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back( {i, j} );
				map[i][j] = 0;
			}
		}
	}
	dfs(0, 0);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}
