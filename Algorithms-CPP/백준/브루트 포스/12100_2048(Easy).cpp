//
//  12100_2048(Easy).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/05.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 블록들이 여러 개 있고 함께 움직여야 한다. 모든 경우의 수를 확인해봐야 하기 때문에 map을 유지하면서
	  이동해야 한다.
 알고리즘: dfs + bfs + 완전탐색
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20;
int map[MAX][MAX];
int n, ans;

void move(int dir) {
	queue<int> q;
	switch (dir) { // 동남서북
		case 0:
			for (int i = 0; i < n; ++i) {
				for (int j = n-1; j >= 0; --j) {
					if (map[i][j])
						q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = n-1;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					if (map[i][idx] == 0)
						map[i][idx] = x;
					else if (map[i][idx] == x)
						map[i][idx--] <<= 1;
					else {
						map[i][--idx] = x;
					}
				}
			}
			break;
		case 1:
			for (int j = 0; j < n; ++j) {
				for (int i = n-1; i >= 0; --i) {
					if (map[i][j])
						q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = n-1;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					if (map[idx][j] == 0)
						map[idx][j] = x;
					else if (map[idx][j] == x)
						map[idx--][j] <<= 1;
					else
						map[--idx][j] = x;
				}
			}
			break;
		case 2:
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (map[i][j])
						q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					if (map[i][idx] == 0)
						map[i][idx] = x;
					else if (map[i][idx] == x)
						map[i][idx++] <<= 1;
					else
						map[i][++idx] = x;
				}
			}
			break;
		case 3:
			for (int j = 0; j < n; ++j) {
				for (int i = 0; i < n; ++i) {
					if (map[i][j])
						q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					if (map[idx][j] == 0)
						map[idx][j] = x;
					else if (map[idx][j] == x)
						map[idx++][j] <<= 1;
					else
						map[++idx][j] = x;
				}
			}
			break;
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ans = max(ans, map[i][j]);
		return;
	}
	int copy_map[MAX][MAX];
	memcpy(copy_map, map, sizeof(map));
	for (int i = 0; i < 4; ++i) {
		move(i);
		dfs(cnt + 1);
		memcpy(map, copy_map, sizeof(copy_map));
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	dfs(0);
	cout << ans << endl;
	return 0;
}
