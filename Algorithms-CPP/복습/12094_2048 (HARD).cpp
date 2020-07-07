//
//  12094_2048 (HARD).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/07.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20;
int map[MAX][MAX];
int n, ans;

void moveBlock(int dir) {
	queue<int> q;
	if (dir == 0) { // 상
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n; ++i) {
				if (map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int now = q.front(); q.pop();
				if (map[idx][j] == 0) map[idx][j] = now;
				else if (map[idx][j] == now) map[idx++][j] <<= 1;
				else map[++idx][j] = now;
			}
		}
	}
	if (dir == 1) { // 하
		for (int j = 0; j < n; ++j) {
			for (int i = n-1; i >= 0; --i) {
				if (map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = n-1;
			while (!q.empty()) {
				int now = q.front(); q.pop();
				if (map[idx][j] == 0) map[idx][j] = now;
				else if (map[idx][j] == now) map[idx--][j] <<= 1;
				else map[--idx][j] = now;
			}
		}
	}
	if (dir == 2) { // 좌
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int now = q.front(); q.pop();
				if (map[i][idx] == 0) map[i][idx] = now;
				else if (map[i][idx] == now) map[i][idx++] <<= 1;
				else map[i][++idx] = now;
			}
		}
	}
	if (dir == 3) { // 우
		for (int i = 0; i < n; ++i) {
			for (int j = n-1; j >= 0; --j) {
				if (map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = n-1;
			while (!q.empty()) {
				int now = q.front(); q.pop();
				if (map[i][idx] == 0) map[i][idx] = now;
				else if (map[i][idx] == now) map[i][idx--] <<= 1;
				else map[i][--idx] = now;
			}
		}
	}
}

void dfs(int cnt) {
	int maxValue = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			maxValue = max(maxValue, map[i][j]);
	
	if (maxValue * (1 << (10-cnt)) <= ans) return;
	if (cnt == 10) {
		ans = max(ans, maxValue);
		return;
	}
	
	int c_map[MAX][MAX];
	memcpy(c_map, map, sizeof(map));
	for (int k = 0; k < 4; ++k) {
		moveBlock(k);
		bool flag = false;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (map[i][j] != c_map[i][j]) {
					flag = true;
					break;
				}
		if (flag) dfs(cnt+1);
		memcpy(map, c_map, sizeof(map));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			ans = max(ans, map[i][j]);
		}
	dfs(0);
	cout << ans << endl;
	return 0;
}
