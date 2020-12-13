//
//  4179_불!.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/22.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부,
	  그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다. 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
 해설: 지훈이의 위치와 불의 위치를 서로 다른 큐에 저장하여 관리한다. 불의 위치는 map을 이용하고, 지훈이의
	  방문은 방문 배열로 관리한다.
 알고리즘: BFS
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct coord {
	int x, y;
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 1000;
char map[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
queue<coord> jq, fq;

int bfs() {
	int step = 0;
	while (!fq.empty() || !jq.empty()) {
		step++;
		int fq_size = fq.size();
		while (fq_size--) {
			int x = fq.front().x;
			int y = fq.front().y;
			fq.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
					if (map[nx][ny] != '#' && map[nx][ny] != 'F') {
						map[nx][ny] = 'F';
						fq.push( {nx, ny} );
					}
				}
			}
		}
		int jq_size = jq.size();
		while (jq_size--) {
			int x = jq.front().x;
			int y = jq.front().y;
			jq.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) return step;
				if (map[nx][ny] == '.' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					jq.push( {nx, ny} );
				}
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				jq.push( {i, j} );
				visited[i][j] = true;
			}
			else if (map[i][j] == 'F') fq.push( {i, j} );
		}
	}
	int ans = bfs();
	if (ans) cout << ans << '\n';
	else cout << "IMPOSSIBLE" << '\n';
	return 0;
}
