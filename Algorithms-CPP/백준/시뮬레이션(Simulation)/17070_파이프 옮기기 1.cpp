//
//  17070_파이프 옮기기 1.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/13.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 파이프를 가로, 세로, 대각선으로 옮기는 문제. dx, dy 설정을 상태에 맞게 설정해주는 게 핵심.
 알고리즘: BFS
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pipe {
	int state; // 0=가로, 1=세로, 2=대각선
	int x, y;
};

const int dx[3][3] = {{0, 0, 1}, {0, 1, 1}, {0, 1, 1}};
const int dy[3][3] = {{1, 0, 1}, {0, 0, 1}, {1, 0, 1}};
const int MAX = 16;
int map[MAX][MAX];
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	queue<Pipe> q;
	q.push( {0, 0, 1} );
	int ans = 0;
	while (!q.empty()) {
		int state = q.front().state;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		for (int i = 0; i < 3; ++i) {
			int nx = x + dx[state][i];
			int ny = y + dy[state][i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) // 맵을 벗어났을 때
				continue;
			if (nx == x && ny == y) // +{0,0} 제거
				continue;
			if (map[nx][ny] == 1) // 벽에 닿았을 때
				continue;
			if (dx[state][i] == 1 && dy[state][i] == 1) // 대각선일 때
				if (map[nx][ny-1] == 1 || map[nx-1][ny] == 1) // 주변에 벽이 있으면
					continue;
			if (nx == n-1 && ny == n-1) { // 끝에 닿았을 때
				ans++;
				continue;
			}
			q.push( {i, nx, ny} );
		}
	}
	cout << ans << '\n';
	return 0;
}
