//
//  16236_아기 상어.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/09.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제:
	1. 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
	2. 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
	3. 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
		1) 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
		2) 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
	위 조건에서 3.2)조건을 구현하는 데 가장 어려움을 겪었다. 하지만 말 그대로 비교 연산자를 만들면 된다.
	구조체를 이용해 우선순위 큐를 구현할 것이므로 cmp 또한 구조체로 만든다.
 알고리즘: 우선순위 큐 + 완전 탐색 + BFS
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int MAX = 20;
int map[MAX][MAX];
bool visited[MAX][MAX];

struct Shark {
	int d, x, y;
};

struct cmp {
	bool operator () (const Shark& a, const Shark& b) const {
		if (a.d == b.d) {
			if (a.x == b.x) return a.y > b.y;
			return a.x > b.x;
		}
		return a.d > b.d;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	priority_queue<Shark, vector<Shark>, cmp> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				q.push( {0, i, j} );
				map[i][j] = 0;	// 상어의 초기 위치를 0으로 초기화해야 한다.
			}
		}
	}
	int size = 2, eaten = 0, ans = 0;
	while (!q.empty()) {
		int d = q.top().d;
		int x = q.top().x;
		int y = q.top().y;
		q.pop();
		if (map[x][y] < size && map[x][y] != 0) {
			map[x][y] = 0;	// 먹었으니 0으로 초기화
			ans += d;
			eaten++;
			memset(visited, 0, sizeof(visited));	// 방문 배열 초기화
			visited[x][y] = 1;
			d = 0;	// 거리 초기화
			while (!q.empty()) q.pop();	// 큐의 모든 원소를 빼낸다.
			if (eaten == size) {	// 자신의 크기만큼 먹었다면 크기 증가
				size++;
				eaten = 0;
			}
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
				if (map[nx][ny] > size || visited[nx][ny])
					continue;
				q.push( {d+1, nx, ny} );
				visited[nx][ny] = 1;	// 방문을 여기서 체크한다.
			}
		}
	}
	cout << ans << endl;
	return 0;
}
