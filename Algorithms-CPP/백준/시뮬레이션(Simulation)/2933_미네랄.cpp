//
//  2933_미네랄.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos { int x, y; };
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int MAX = 100;
char map[MAX][MAX+1];
bool visited[MAX][MAX];
int r, c, n;

bool throwBar(bool toLeft, int row) {
	if (toLeft) {
		for (int j = c-1; j >= 0; --j) {
			if (map[row][j] == 'x') {
				map[row][j] = '.';
				return true;
			}
		}
	} else {
		for (int j = 0; j < c; ++j) {
			if (map[row][j] == 'x') {
				map[row][j] = '.';
				return true;
			}
		}
	}
	return false;
}

void print() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> map[i][j];
	cin >> n;
	for (int k = 0; k < n; ++k) {
		int row;
		cin >> row;
		bool beShot = throwBar(k % 2, r - row);
		if (!beShot) continue;
		Pos p = { -1, -1 };
		memset(visited, false, sizeof(visited));
		vector<Pos> mineral;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (map[i][j] == 'x' && !visited[i][j]) {
					queue<Pos> q;
					vector<Pos> temp;
					q.push({ i, j });
					temp.push_back({ i, j });
					visited[i][j] = true;
					bool landed = false;
					while (!q.empty()) {
						Pos cur = q.front(); q.pop();
						for (int i = 0; i < 4; ++i) {
							int nx = cur.x + dx[i];
							int ny = cur.y + dy[i];
							if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
							if (map[nx][ny] == '.' || visited[nx][ny]) continue;
							visited[nx][ny] = true;
							q.push({ nx, ny });
							temp.push_back({ nx, ny });
							if (nx == r-1) landed = true;
						}
					}
					if (!landed) {
						p = { i, j };
						mineral = temp;
						break;
					}
				}
			}
		}
		if (p.x == -1) continue;
		for (Pos& t: mineral)
			map[t.x][t.y] = '.';
		bool flag = false;
		int cnt = 0;
		for (int i = 1; i < r; ++i) {
			for (Pos& t: mineral) {
				if (t.x + i >= r || map[t.x + i][t.y] == 'x') {
					flag = true;
					break;
				}
			}
			if (flag) break;
			cnt = i;
		}
		for (Pos& t: mineral)
			map[t.x + cnt][t.y] = 'x';
	}
	print();
	return 0;
}
