//
//  1949_[모의 SW 역량테스트] 등산로 조성.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/30.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 가장 높은 위치에서 낮은 곳으로 내려간다. 도중에 현재 위치보다 높거나 같은 곳을 만나면 최대 k만큼
	  한번만 깎을 수 있으며 깎인 값이 현재 값보다 낮으면 더 진행할 수 있다.
 해설: 전형적인 백트래킹 문제. k만큼 깎아서 현재 값보다 낮다면 현재 값보다 1 작게 설정한다.
	  이전 값을 알아야 하므로 매개변수에 전달해준다. 조건문을 조심하자 (if, else if, else)
 알고리즘: 백트래킹
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0 ,0 ,-1, 1};
const int MAX = 8;
bool visited[MAX][MAX];
int map[MAX][MAX];
int n, k, ans;

void dfs(int x, int y, int value, int cnt, bool cut) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visited[nx][ny]) continue;
		if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
			if (map[nx][ny] < value) {
				visited[nx][ny] = true;
				dfs(nx, ny, map[nx][ny], cnt+1, cut);
				visited[nx][ny] = false;
			} else if (map[nx][ny] >= value && !cut) {
				if (map[nx][ny] - k < value) {
					visited[nx][ny] = true;
					dfs(nx, ny, value-1, cnt+1, true);
					visited[nx][ny] = false;
				}
			}
			ans = max(ans, cnt);
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> k;
		int highest = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				highest = max(highest, map[i][j]);
			}
		}
		ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (map[i][j] == highest) {
					visited[i][j] = true;
					dfs(i, j, map[i][j], 1, false);
					visited[i][j] = false;
				}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
