//
//  19237_어른 상어.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/03.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 상어가 되돌아가는 방향도 우선 순위에 맞게 돌아가야 한다. 이 조건을 빼먹어 푸는 데 오래 걸렸다.
 if (... && prev_d == 1) <- 여기서 두 번째 조건
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 상하좌우
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
const int MAX = 20;

struct Shark {
	int x, y, d;
	bool alive;
	vector<int> dir[4];
};

struct Map {
	vector<int> v;
	int idx, sec;
};

int n, m, k;
Shark sharks[MAX * MAX + 1];
Map map[MAX][MAX];

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int idx;
			cin >> idx;
			if (idx > 0) {
				sharks[idx].x = i;
				sharks[idx].y = j;
				sharks[idx].alive = true;
			}
			map[i][j].idx = 0;
			map[i][j].sec = 0;
			map[i][j].v.clear();
		}
	}
	for (int i = 1; i <= m; ++i) {
		int d; cin >> d;
		sharks[i].d = --d;
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				int d; cin >> d;
				sharks[i].dir[j].push_back(--d);
			}
		}
	}
}

void setScent() {
	for (int i = 1; i <= m; ++i) {
		if (!sharks[i].alive) continue;
		int x = sharks[i].x;
		int y = sharks[i].y;
		map[x][y].idx = i;
		map[x][y].sec = k;
	}
}

void moveShark() {
	for (int i = 1; i <= m; ++i) {
		if (!sharks[i].alive) continue;
		int x = sharks[i].x;
		int y = sharks[i].y;
		int d = sharks[i].d;
		int j;
		int prev_x = -1, prev_y = -1, prev_d = -1;
		for (j = 0; j < 4; ++j) {
			int nd = sharks[i].dir[d][j];
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			// 되돌아가는 방향이 여러 개일 수 있다. 이 또한 우선순위 방향에 맞춰야 하므로
			// 두 번째 조건을 반드시 넣어줘야 한다.
			if (map[nx][ny].idx == i && prev_x == -1) {
				prev_x = nx;
				prev_y = ny;
				prev_d = nd;
			}
			if (map[nx][ny].sec == 0) {
				map[nx][ny].v.push_back(i);
				sharks[i].x = nx;
				sharks[i].y = ny;
				sharks[i].d = nd;
				break;
			}
		}
		// 네 방향 모두 갈 수 없는 경우 우선순위방향에 맞춰 돌아간다.
		if (j == 4) {
			map[prev_x][prev_y].v.push_back(i);
			sharks[i].x = prev_x;
			sharks[i].y = prev_y;
			sharks[i].d = prev_d;
		}
	}

}

void killShark() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j].v.empty()) continue;
			sort(map[i][j].v.begin(), map[i][j].v.end());
			for (int k = 1; k < map[i][j].v.size(); ++k)
				sharks[map[i][j].v[k]].alive = false;
			map[i][j].v.clear();
		}
	}
}

bool onlyOneAlive() {
	for (int i = 2; i <= m; ++i)
		if (sharks[i].alive) return false;
	return true;
}

void fadeOutScent() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j].sec) map[i][j].sec--;
			if (map[i][j].sec == 0) map[i][j].idx = 0;
		}
	}
}

void solution() {
	int t;
	for (t = 0; t <= 1000; ++t) {
		if (onlyOneAlive()) break;
		setScent();
		moveShark();
		killShark();
		fadeOutScent();
	}
	if (t > 1000) t = -1;
	cout << t << endl;
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}
