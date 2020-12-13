//
//  10875_뱀.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/20.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 직선 교차 여부 확인에 ccw까지 쓸 필요가 없다. 단순 계산.
 마지막엔 강제로 선에 부딪히게 한다.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Line {
	int x1, y1, x2, y2;
	int dir;
	Line(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d) {
		dir = x1 == x2 ? 0 : 1; // 0=가로, 1=세로
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
	}
};

// 우하좌상
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
const int INF = 1e9;
vector<Line> lines;
int L, N;
long long ans;

int moveSnake(int x, int y, char dir) {
	int ret = INF;
	for (auto& line: lines) {
		if (line.dir == 0) { // 가로
			switch (dir) {
				case 0:
					if (x == line.x1 && y < line.y1)
						ret = min(ret, line.y1 - y);
					break;
				case 1:
					if (line.y1 <= y && y <= line.y2 && x < line.x1)
						ret = min(ret, line.x1 - x);
					break;
				case 2:
					if (x == line.x1 && line.y1 < y)
						ret = min(ret, y - line.y1);
					break;
				case 3:
					if (line.y1 <= y && y <= line.y2 && line.x1 < x)
						ret = min(ret, x - line.x1);
					break;
			}
		}
		else { // 세로
			switch (dir) {
				case 0:
					if (line.x1 <= x && x <= line.x2 && y < line.y1)
						ret = min(ret, line.y1 - y);
					break;
				case 1:
					if (y == line.y1 && x < line.x1)
						ret = min(ret, line.x1 - x);
					break;
				case 2:
					if (line.x1 <= x && x <= line.x2 && line.y1 < y)
						ret = min(ret, y - line.y1);
					break;
				case 3:
					if (y == line.y1 && line.x1 < x)
						ret = min(ret, x - line.x1);
					break;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> L >> N;
	int a = -L-1, b = L+1;
	lines.push_back({ a, a, a, b });
	lines.push_back({ a, a, b, a });
	lines.push_back({ a, b, b, b });
	lines.push_back({ b, a, b, b });
	int x = 0, y = 0, snake_dir = 0;
	for (int i = 0; i <= N; ++i) {
		int t = INF;
		char dir;
		if (i < N) cin >> t >> dir;
		int movingTime = moveSnake(x, y, snake_dir);
		if (movingTime <= t) {
			ans += movingTime;
			break;
		}
		ans += t;
		int nx = x + dx[snake_dir] * t;
		int ny = y + dy[snake_dir] * t;
		lines.push_back({ x, y, nx, ny });
		snake_dir = (snake_dir + (dir == 'L' ? 3 : 1)) % 4;
		x = nx; y = ny;
	}
	cout << ans << endl;
	return 0;
}
