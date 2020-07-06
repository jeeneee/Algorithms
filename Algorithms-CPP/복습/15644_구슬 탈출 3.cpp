//
//  15644_구슬 탈출 3.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Ball {
	int rx, ry, bx, by;
	int cnt;
	string dir;
};

// LRUD
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };
const char dir[5] = { 'L', 'R', 'U', 'D' };
const int MAX = 10;
char map[MAX][MAX + 1];
bool visited[MAX][MAX][MAX][MAX];
int hx, hy;

int move(int &x, int &y, int d) {
	int cnt = 0;
	while (1) {
		x += dx[d]; y += dy[d];
		cnt++;
		if (map[x][y] == '#') {
			x -= dx[d]; y -= dy[d];
			cnt--;
			break;
		} else if (map[x][y] == 'O')
			break;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	Ball ball;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R') { ball.rx = i; ball.ry = j; }
			if (map[i][j] == 'B') { ball.bx = i; ball.by = j; }
			if (map[i][j] == 'O') { hx = i; hy = j; }
		}
	}
	ball.cnt = 0;
	ball.dir = "";
	queue<Ball> q;
	q.push(ball);
	visited[ball.rx][ball.ry][ball.bx][ball.by] = true;
	Ball ans;
	ans.cnt = 0;
	while (!q.empty()) {
		Ball cur = q.front();
		q.pop();
		if (cur.cnt > 10) break;
		if (cur.rx == hx && cur.ry == hy) { ans = cur; break; }
		for (int i = 0; i < 4; ++i) {
			int n_rx = cur.rx, n_ry = cur.ry;
			int n_bx = cur.bx, n_by = cur.by;
			int cntRed = move(n_rx, n_ry, i);
			int cntBlue = move(n_bx, n_by, i);

			if (n_bx == hx && n_by == hy) continue;
			
			if (n_rx == n_bx && n_ry == n_by) {
				if (cntRed < cntBlue) {
					n_bx -= dx[i]; n_by -= dy[i];
				} else {
					n_rx -= dx[i]; n_ry -= dy[i];
				}
			}
			
			if (!visited[n_rx][n_ry][n_bx][n_by]) {
				q.push({ n_rx, n_ry, n_bx, n_by, cur.cnt+1, cur.dir + dir[i] });
				visited[n_rx][n_ry][n_bx][n_by] = true;
			}
		}
	}
	if (ans.cnt == 0) cout << -1 << endl;
	else cout << ans.cnt << endl << ans.dir << endl;
	return 0;
}
