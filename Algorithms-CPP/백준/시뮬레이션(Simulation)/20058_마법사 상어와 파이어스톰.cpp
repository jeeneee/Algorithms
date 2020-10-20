//
//  20058_마법사 상어와 파이어스톰.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/10/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int dr[] = { 0, 1, 0, -1 };
const int dc[] = { 1, 0, -1, 0 };
const int MAX = 4096;
int map[MAX][MAX];
int mapSize;
int sum, maxCnt;
int n, q;

bool inRange(int row, int col) {
	return (0 <= row && row < mapSize) && (0 <= col && col < mapSize);
}

void rotate(int row, int col, int l) {
	vector<vector<int>> temp(l, vector<int>(l));
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < l; ++j)
			temp[i][j] = map[row + l - 1 - j][col + i];
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < l; ++j)
			map[row + i][col + j] = temp[i][j];
}

void melt() {
	vector<pair<int, int>> cand;
	for (int i = 0; i < mapSize; ++i) {
		for (int j = 0; j < mapSize; ++j) {
			if (map[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0; k < 4; ++k) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (!inRange(nr, nc)) continue;
				if (map[nr][nc]) cnt++;
			}
			if (cnt < 3) cand.push_back({ i, j });
		}
	}
	for (auto& c : cand)
		map[c.first][c.second]--;
}

void bfs() {
	for (int i = 0; i < mapSize; ++i) {
		for (int j = 0; j < mapSize; ++j) {
			if (map[i][j] != 0) {
				queue<pair<int, int>> q;
				q.push({ i, j });
				sum += map[i][j];
				map[i][j] = 0;
				int cnt = 1;
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int nr = r + dr[k];
						int nc = c + dc[k];
						if (!inRange(nr, nc)) continue;
						if (map[nr][nc]) {
							sum += map[nr][nc];
							map[nr][nc] = 0;
							q.push({ nr, nc });
							cnt++;
						}
					}
				}
				maxCnt = max(maxCnt, cnt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	mapSize = (int)pow(2, n);
	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
			cin >> map[i][j];
	for (int i = 0; i < q; ++i) {
		int l;
		cin >> l;
		int t = (int)pow(2, l);
		for (int i = 0; i < mapSize; i += t)
			for (int j = 0; j < mapSize; j += t)
				rotate(i, j, t);
		melt();
	}
	sum = maxCnt = 0;
	bfs();
	cout << sum << endl << maxCnt << endl;
	return 0;
}
