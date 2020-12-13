//
//  2117_[모의 SW 역량 테스트] 홈 방범 서비스.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/26.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: + 형태로 서비스를 제공하며 면적이 넓어질수록 비용이 증가한다. 회사에서 손해를 보지 않고 최대한 많은
	  집에서 서비스를 제공받을 수 있을 때, 집의 수를 구하는 문제.
 해설: 맵의 모든 점에서 BFS를 이용했다. 여기서 중요한 점은 "면적을 최대로 언제까지 증가시켜야 할까?" 인데
	  그림을 그려보면 알겠지만 최대 k+1까지 확인하면 된다.
 알고리즘: BFS
 */
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 20;
int map[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

int search(int x, int y) {
	int k = 1;
	int cost = 1;
	int house = map[x][y];
	int ret = 0;
	queue<pair<int, int>> q;
	q.push( {x, y} );
	visited[x][y] = true;
	while (!q.empty()) {
		if (k > n+1) break;
		if (house * m >= cost) ret = max(ret, house);
		int size = q.size();
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
					if (visited[nx][ny]) continue;
					visited[nx][ny] = true;
					house += map[nx][ny];
					q.push( {nx, ny} );
				}
			}
		}
		k++;
		cost = k * k + (k-1) * (k-1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				memset(visited, false, sizeof(visited));
				ans = max(ans, search(i, j));
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
