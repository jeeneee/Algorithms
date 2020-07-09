//
//  19238_스타트 택시.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/09.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos { int x, y; };
struct Info { int idx, dist; };
struct Passenger { Pos src, dest; };

// 상좌우하
const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };
const int MAX = 20;
int map[MAX+2][MAX+2];
bool visited[MAX+2][MAX+2];
Passenger passenger[MAX * MAX + 1];
Pos taxi;
int n, m, fuel;

bool comp(Pos& a, Pos& b) {
	if (a.x == b.x) return a.y <= b.y;
	return a.x < b.x;
}

Info findPassenger() {
	int idx = 0, distance = 0;
	if (map[taxi.x][taxi.y] > 0) {
		idx = map[taxi.x][taxi.y];
		map[taxi.x][taxi.y] = 0;
		return { idx, 0 };
	}
	queue<Pos> q;
	vector<Pos> cand;
	memset(visited, false, sizeof(visited));
	q.push(taxi);
	visited[taxi.x][taxi.y] = true;
	
	while (!q.empty()) {
		int size = q.size();
		bool flag = false;
		distance++;
		while (size--) {
			Pos now = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if (map[nx][ny] >= 0 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
					if (map[nx][ny] > 0) {
						cand.push_back({ nx, ny });
						flag = true;
					}
				}
			}
		}
		if (flag) {
			sort(cand.begin(), cand.end(), comp);
			taxi = cand[0];
			idx = map[cand[0].x][cand[0].y];
			map[cand[0].x][cand[0].y] = 0;
			return { idx, distance };
		}
	}
	return { -1, -1 };
}

int sendPassenger(int idx) {
	memset(visited, false, sizeof(visited));
	queue<Pos> q;
	q.push(taxi);
	visited[taxi.x][taxi.y] = true;
	Pos dest = passenger[idx].dest;
	int distance = 0;
	
	while (!q.empty()) {
		int size = q.size();
		distance++;
		while (size--) {
			Pos now = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if (map[nx][ny] == -1 || visited[nx][ny]) continue;
				if (nx == dest.x && ny == dest.y) {
					taxi = dest;
					return distance;
				}
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	return -1;
}

int solve() {
	Info info;
	int dist;
	for (int i = 0; i < m; ++i) {
		info = findPassenger();
		fuel -= info.dist;
		if (info.idx == -1 || fuel < 0) return -1;
		
		dist = sendPassenger(info.idx);
		fuel -= dist;
		if (dist == -1 || fuel < 0) return -1;
		fuel += dist * 2;
	}
	return fuel;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(map, -1, sizeof(map));
	cin >> n >> m >> fuel;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			map[i][j] *= -1;
		}
	cin >> taxi.x >> taxi.y;
	for (int i = 1; i <= m; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		passenger[i] = { x1, y1, x2, y2 };
		map[x1][y1] = i;
	}
	cout << solve() << endl;
	return 0;
}
