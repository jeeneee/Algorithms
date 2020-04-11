//
//  2814_최장 경로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/11.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 bfs로 하면 안된다. 돌아서 갈 경우 이미 방문 표시가 되어 최장 거리를 구할 수 없다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20 + 1;
vector<int> graph[MAX];
bool visited[MAX];
int ans;

void dfs(int vertex, int cnt) {
	visited[vertex] = true;
	for (auto& adj : graph[vertex])
		if (!visited[adj])
			dfs(adj, cnt+1);
	visited[vertex] = false;
	ans = max(ans, cnt);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		for (int i = 0; i < MAX; ++i)
			graph[i].clear();
		int n, m;
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		ans = 0;
		for (int i = 1; i <= n; ++i)
			dfs(i, 1);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
