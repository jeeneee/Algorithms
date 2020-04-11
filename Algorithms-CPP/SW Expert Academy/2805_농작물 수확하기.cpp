//
//  2805_농작물 수확하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX = 50;
int map[MAX][MAX];
bool visited[MAX][MAX];

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%1d", &map[i][j]);
				visited[i][j] = false;
			}
		}
		queue<pair<int, int>> q;
		q.push( {n/2, n/2} );
		visited[n/2][n/2] = true;
		int sum = map[n/2][n/2];
		for (int i = 0; i < n/2; ++i) {
			int size = q.size();
			while (size--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (!visited[nx][ny]) {
						visited[nx][ny] = true;
						q.push( {nx, ny} );
						sum += map[nx][ny];
					}
				}
			}
		}
		printf("#%d %d\n", tc, sum);
	}
	return 0;
}
