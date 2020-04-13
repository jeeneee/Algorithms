//
//  1249_보급로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/13.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX = 100;
int map[MAX][MAX];
bool visited[MAX][MAX];
int N;

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		memset(visited, false, sizeof(visited));
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%1d", &map[i][j]);
		
		priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
		pq.push( {map[0][0], {0, 0}} );
		int ans = 0;
		
		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (x == N-1 && y == N-1) {
				ans = cost;
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					pq.push( {cost + map[nx][ny], {nx, ny}} );
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
