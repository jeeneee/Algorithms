//
//  2105_[모의 SW 역량테스트] 디저트 카페.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/31.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 디저트 카페를 순회하는데 대각선으로 갈 수 있고 출발 지점으로 다시 돌아와야 한다. 경로에 같은 숫자가
	  오면 안된다.
 해설: dfs 백트래킹 문제이다. 대각선을 우하, 좌하, 좌상, 우상 순서로 설정하고 dfs에서 방향을 그대로 가는 것과
	  +1(다음 방향)한 것으로 순회하였다. 처음에 출발 지점을 i, j로 들어갔는데 도착점인 출발점에 도착하여 visited가
	  다시 false가 되어 다른 경로에 출발점과 같은 숫자가 있는 경우 중복이 되어 시간을 오래 잡아먹었다.
	  해결 방법으로 i, j에서 다음 지점을 출발점으로 지정했다.
 알고리즘: 완전 탐색 dfs 백트래킹
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, -1, 1};
const int MAX = 20;
int map[MAX][MAX];
bool visited[101];
int n, ans;

bool inRange(int x, int y) {
	return ((0 <= x && x < n) && (0 <= y && y < n));
}

// x,y=현재위치, xx,yy=도착위치, d=방향, cnt=방문횟수
void dfs(int x, int y, int xx, int yy, int d, int cnt) {
	if (x == xx && y == yy) {
		ans = max(ans, cnt);
		return;
	}
	// 현재 방향 유지, 다음 방향 전환
	for (int i = d; i <= d+1; ++i) {
		if (i == 4) return;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inRange(nx, ny) && !visited[map[nx][ny]]) {
			visited[map[nx][ny]] = true;
			dfs(nx, ny, xx, yy, i, cnt+1);
			visited[map[nx][ny]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];
		
		ans = -1;
		for (int i = 0; i < n-2; ++i) { // 세로에 두 칸은 확보해야 한다.
			for (int j = 1; j < n-1; ++j) { // 가로 양쪽에 한 칸은 확보해야 한다.
				int nx = i + dx[0];
				int ny = j + dy[0];
				if (inRange(nx, ny) && (map[i][j] != map[nx][ny])) {
					visited[map[nx][ny]] = true;
					dfs(nx, ny, i, j, 0, 1); // 출발점으로 {nx, ny}를 넣어준다.
					visited[map[nx][ny]] = false;
				}
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}

