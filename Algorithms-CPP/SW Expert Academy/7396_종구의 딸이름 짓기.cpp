//
//  7396_종구의 딸이름 짓기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/16.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 알파벳으로 이루어진 맵 좌측 상단에서 우측 하단으로 이동하며 사전 순으로 가장 작은 이름을 구하는 문제.
 해설: 우선 순위 큐를 이용한 BFS
 */
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<string, pair<int, int>> pspii;
const int dx[] = {0, 1};
const int dy[] = {1, 0};
const int MAX = 2000;
char map[MAX][MAX+1];
bool visited[MAX][MAX];
int n, m;

string bfs() {
	string ret;
	priority_queue<pspii, vector<pspii>, greater<pspii>> pq;
	string temp;
	temp += map[0][0];
	pq.push( {temp, {0, 0}} );
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		string name = pq.top().first;
		pq.pop();
		if (x == n-1 && y == m-1) {
			ret = name;
			break;
		}
		for (int i = 0; i < 2; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < n && ny < m && !visited[nx][ny]) {
				visited[nx][ny] = true;
				pq.push( {name + map[nx][ny], {nx, ny}} );
			}
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", map[i]);
			for (int j = 0; j < m; ++j)
				visited[i][j] = false;
		}
		string name = bfs();
		cout << '#' << tc << ' ' << name << '\n';
	}
	return 0;
}
