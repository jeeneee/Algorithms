//
//  13460_구슬 탈출 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/05.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 두 개의 구슬을 동시에 움직이는 BFS문제이다. 방문 배열로 두 상태를 저장하는 것과 두 구슬이 겹칠 때
	  위치를 조정하는 것에 유의하자. 네 방향으로 최대 10번 움직이므로 4^10 = 2^20
 알고리즘: BFS
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10;
// right, down, left, up
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
char map[MAX][MAX+1];
bool visited[MAX][MAX][MAX][MAX];
int hx, hy;

struct Ball {
	int rx, ry, bx, by;
	int cnt;
};

void move(int& x, int& y, int dir) {
	while (1) {
		x += dx[dir]; y += dy[dir];
		if (map[x][y] == '#') {
			x -= dx[dir]; y -= dy[dir];
			break;
		} else if (map[x][y] == 'O')
			break;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Ball ball;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') {
				ball.rx = i; ball.ry = j;
			}
			else if (map[i][j] == 'B') {
				ball.bx = i; ball.by = j;
			}
			else if (map[i][j] == 'O') {
				hx = i; hy = j;
			}
		}
	}
	queue<Ball> q;
	ball.cnt = 0;
	q.push(ball);
	visited[ball.rx][ball.ry][ball.bx][ball.by] = true;
	int ans = -1;
	while (!q.empty()) {
		Ball cur = q.front();
		q.pop();
		if (cur.cnt > 10)
			break;
		if (cur.rx == hx && cur.ry == hy) {
			ans = cur.cnt;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int n_rx = cur.rx, n_ry = cur.ry;
			int n_bx = cur.bx, n_by = cur.by;
			move(n_rx, n_ry, i);
			move(n_bx, n_by, i);
			
			if (n_bx == hx && n_by == hy)
				continue;
			
			if (n_rx == n_bx && n_ry == n_by) {
				switch (i) {
					case 0:
						cur.ry > cur.by ? n_by-- : n_ry--;
						break;
					case 1:
						cur.rx > cur.bx ? n_bx-- : n_rx--;
						break;
					case 2:
						cur.ry > cur.by ? n_ry++ : n_by++;
						break;
					case 3:
						cur.rx > cur.bx ? n_rx++ : n_bx++;
						break;
				}
			}
			
			if (!visited[n_rx][n_ry][n_bx][n_by]) {
				Ball next = {n_rx, n_ry, n_bx, n_by, cur.cnt + 1};
				q.push(next);
				visited[n_rx][n_ry][n_bx][n_by] = true;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
