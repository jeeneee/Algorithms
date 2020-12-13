//
//  17471_게리맨더링.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/11.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 조합으로 두 구역으로 나눈 뒤 각 구역마다 BFS를 통해 모든 지역이 연결되었는지 확인한다.
 알고리즘: DFS + BFS
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 987654321;
const int MAX = 10;
vector<int> graph[MAX];
int district[MAX];
int num[MAX];
int N, ans = INF;

int calc(int team) {
	queue<int> q;
	int ret = 0;
	bool visited[MAX];
	memset(visited, false, sizeof(visited));
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		if (district[i] != team)
			visited[i] = true;
		else {
			ret += num[i];
			if (!flag) {
				q.push(i);
				flag = true;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		visited[x] = true;
		for (auto& adj : graph[x]) {
			if (district[adj] == team && !visited[adj])
				q.push(adj);
		}
	}
	for (int i = 0; i < N; ++i)
		if (!visited[i]) return INF;
	return ret;
}

void selectCand(int idx, int cnt, int M) {
	if (cnt == M) {
		int A = calc(0);
		int B = calc(1);
		if (A != INF && B != INF)
			ans = min(ans, abs(A - B));
		return;
	}
	for (int i = idx; i < N; ++i) {
		district[i] = 1;
		selectCand(i+1, cnt+1, M);
		district[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	for (int i = 0; i < N; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			graph[i].push_back(x-1);
		}
	}
	for (int i = 1; i <= N/2; ++i)
		selectCand(0, 0, i);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}
