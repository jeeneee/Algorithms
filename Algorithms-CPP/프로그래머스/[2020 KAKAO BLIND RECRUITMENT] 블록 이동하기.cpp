//
//  [2020 KAKAO BLIND RECRUITMENT] 블록 이동하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/13.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 BFS 문제이지만 어려운 문제. 로봇이 두 칸을 차지하고 상하좌우로 움직일 수 있고 시계, 반시계 방향으로
 90도 회전할 수 있어 복잡하다. 움직이는 데 총 8가지의 경우의 수가 있으며 큐에는 두 좌표와 두 방향을 넣어준다.
 방문 배열은 모든 좌표에 대해 네 방향을 확인해야 하므로 102x102x4(102인 이유는 코드의 간결함을 위해
 1로 패딩을 주었다) 크기의 배열을 정의한다. 회전에 관련된 코드에서 for문 두개와 방향을 정하는 계산법, 그리고
 대각선에 존재하는 rx, ry 계산에 유의한다.
 */
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Robot {
	int x[2], y[2];
	int d[2];
};

// 우하좌상
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool chk[102][102][4];

int solution(vector<vector<int>> board) {
	memset(chk, false, sizeof(chk));
	int n = board.size();
	vector<vector<int>> map(n+2, vector<int>(n+2, 1));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			map[i][j] = board[i-1][j-1];
	
	queue<Robot> q;
	q.push( {1, 1, 1, 2, 0, 2} );
	chk[1][1][0] = chk[1][2][2] = true;
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Robot a = q.front();
			q.pop();
			if ((a.x[0] == n && a.y[0] == n) || (a.x[1] == n && a.y[1] == n))
				return cnt;
			// 상하좌우
			for (int i = 0; i < 4; ++i) {
				int nx1 = a.x[0] + dx[i], nx2 = a.x[1] + dx[i];
				int ny1 = a.y[0] + dy[i], ny2 = a.y[1] + dy[i];
				int d1 = a.d[0], d2 = a.d[1];
				if (map[nx1][ny1] || map[nx2][ny2]) continue;
				if (chk[nx1][ny1][d1] || chk[nx2][ny2][d2]) continue;
				chk[nx1][ny1][d1] = chk[nx2][ny2][d2] = true;
				q.push( {nx1, nx2, ny1, ny2, d1, d2} );
			}
			// 회전
			for (int i = -1; i <= 1; ++i) {
				if (i == 0) continue;
				for (int j = 0; j < 2; ++j) {
					int x = a.x[j], y = a.y[j];
					int prev_d = a.d[j];
					int d = (a.d[j] + i + 4) % 4;
					int oppo_d = (d + 2) % 4;
					
					int nx = x + dx[d], ny = y + dy[d];
					int rx = nx + dx[prev_d], ry = ny + dy[prev_d];
					// (x,y), (nx,ny), (rx,ry)
					if (map[nx][ny] || map[rx][ry]) continue;
					if (chk[x][y][d] || chk[nx][ny][oppo_d]) continue;
					chk[x][y][d] = chk[nx][ny][oppo_d] = true;
					q.push( {x, nx, y, ny, d, oppo_d} );
				}
			}
		}
		++cnt;
	}
	return -1;
}

int main() {
	vector<vector<int>> board = {
		{0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0},
		{0, 1, 0, 1, 1},
		{1, 1, 0, 0, 1},
		{0, 0, 0, 0, 0}
	};
	cout << solution(board) << endl;
	return 0;
}
