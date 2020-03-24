//
//  2819_격자판의 숫자 이어 붙이기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/24.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 BFS
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int map[4][4];
set<int> s;

void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push( {{x, y}, map[x][y]} );
	int cnt = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int num = q.front().second;
			q.pop();
			if (cnt == 7) {
				s.insert(num);
				continue;
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((0 <= nx && nx < 4) && (0 <= ny && ny < 4)) {
					q.push( {{nx, ny}, num * 10 + map[nx][ny]} );
				}
			}
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int cc;
	cin >> cc;
	for (int c = 1; c <= cc; ++c) {
		s.clear();
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> map[i][j];
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				bfs(i, j);
		cout << "#" << c << " " << s.size() << "\n";
	}
	return 0;
}
