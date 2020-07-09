//
//  3190_뱀.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/09.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 뱀이 움직이는 과정에서 앞뒤로 변화가 생기므로 덱을 쓰는 것이 적절하다.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

// 동남서북
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
const int MAX = 100;
int map[MAX][MAX];

struct Pos { int x, y; };

deque<Pos> snake;
vector<pair<int, char>> dir;
int N, K, L;
int ans;

bool inRange(int x, int y) {
	return (0 <= x && x < N) && (0 <= y && y < N);
}

int solve() {
	snake.push_front({ 0, 0 });
	int snakeDir = 0;
	map[0][0] = 1; // 뱀은 1, 사과는 2
	int k = 0;
	int t = 1;
	while (1) {
		int nx = snake.front().x + dx[snakeDir];
		int ny = snake.front().y + dy[snakeDir];
		if (!inRange(nx, ny) || map[nx][ny] == 1) break;
		if (map[nx][ny] == 0) {
			map[snake.back().x][snake.back().y] = 0;
			snake.pop_back();
		}
		snake.push_front({ nx, ny });
		map[nx][ny] = 1;
		if (k < dir.size() && dir[k].first == t)
			snakeDir = (snakeDir + (dir[k++].second == 'L' ? 3 : 1)) % 4;
		t++;
	}
	return t;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		int x, y; cin >> x >> y;
		map[x-1][y-1] = 2;
	}
	cin >> L;
	dir.resize(L);
	for (int i = 0; i < L; ++i)
		cin >> dir[i].first >> dir[i].second;
	ans = solve();
	cout << ans << endl;
	return 0;
}
