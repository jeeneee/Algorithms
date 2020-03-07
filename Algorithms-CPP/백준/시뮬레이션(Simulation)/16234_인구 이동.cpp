//
//  16234_인구 이동.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/07.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 인접한 국가의 인구가 특정 조건에 맞으면 서로 연합시키는 문제. dfs, bfs 모두 상관이 없지만
	  dfs에서 한번에 처리할 수 없다는 것을 간과했다. 좌표를 저장하고 dfs가 끝나면 그때 처리해줘야 함.
 알고리즘: dfs or bfs
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
int map[MAX][MAX];
bool visited[MAX][MAX];
int N, L, R;
int numOfLand, numOfPop;
vector<pair<int, int>> pos;

void dfs(int x, int y) {
	visited[x][y] = true;
	numOfLand++;
	numOfPop += map[x][y];
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ((0 <= nx && nx < N) && (0 <= ny && ny < N)) {
			int diff = abs(map[x][y] - map[nx][ny]);
			if (!visited[nx][ny] && L <= diff && diff <= R)
				dfs(nx, ny);
		}
	}
	pos.push_back( {x, y} );
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];
	int cnt = 0;
	while (1) {
		bool flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				numOfLand = numOfPop = 0;
				pos.clear();
				if (visited[i][j])
					continue;
				dfs(i, j);
				if (numOfLand == 1)
					continue;
				flag = true;
				for (auto& p: pos)
					map[p.first][p.second] = numOfPop / numOfLand;
			}
		}
		if (!flag)
			break;
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
