//
//  16236_아기 상어.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pipii;
// 상좌우하
const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };
int map[22][22];
bool visited[22][22];

void print(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
	cin >> n;
	memset(map, -1, sizeof(map));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				pq.push({ 0, {i, j} });
				map[i][j] = 0;
			}
		}
	}
	int size = 2;
	int eaten = 0;
	int ans = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		// when shark eats fish
		if (0 < map[x][y] && map[x][y] < size) {
			ans += d;
			d = map[x][y] = 0;
			++eaten;
			if (eaten == size) { eaten = 0; ++size; }
			memset(visited, false, sizeof (visited));
			while (!pq.empty()) pq.pop();
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= map[nx][ny] && map[nx][ny] <= size && !visited[nx][ny]) {
				visited[nx][ny] = true;
				pq.push({ d+1, {nx, ny} });
			}
		}
	}
	cout << ans << endl;
	return 0;
}
