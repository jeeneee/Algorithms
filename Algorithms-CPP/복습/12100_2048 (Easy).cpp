//
//  12100_2048 (Easy).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/07.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20;
int map[MAX][MAX];
int n, ans;

void moveBlock(int dir) {
	queue<int> q;
	switch (dir) {
		case 0: // 상
			for (int j = 0; j < n; ++j) {
				for (int i = 0; i < n; ++i) {
					if (map[i][j]) q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (q.size() && cur == q.front()) {
						q.pop();
						map[idx++][j] = (cur << 1);
					}
					else map[idx++][j] = cur;
				}
			}
			break;
		case 1: // 하
			for (int j = 0; j < n; ++j) {
				for (int i = n-1; i >= 0; --i) {
					if (map[i][j]) q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = n-1;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (q.size() && cur == q.front()) {
						q.pop();
						map[idx--][j] = (cur << 1);
					}
					else map[idx--][j] = cur;
				}
			}
			break;
		case 2: // 좌
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (map[i][j]) q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (q.size() && cur == q.front()) {
						q.pop();
						map[i][idx++] = (cur << 1);
					}
					else map[i][idx++] = cur;
				}
			}
			break;
		case 3: // 우
			for (int i = 0; i < n; ++i) {
				for (int j = n-1; j >= 0; --j) {
					if (map[i][j]) q.push(map[i][j]);
					map[i][j] = 0;
				}
				int idx = n-1;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (q.size() && cur == q.front()) {
						q.pop();
						map[i][idx--] = (cur << 1);
					}
					else map[i][idx--] = cur;
				}
			}
			break;
	}
}

void dfs(int cnt) {
	if (cnt >= 5) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ans = max(ans, map[i][j]);
		return;
	}
	int c_map[MAX][MAX];
	memcpy(c_map, map, sizeof(map));
	for (int i = 0; i < 4; ++i) {
		moveBlock(i);
		dfs(cnt+1);
		memcpy(map, c_map, sizeof(map));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	ans = 0;
	dfs(0);
	cout << ans << endl;
	return 0;
}
