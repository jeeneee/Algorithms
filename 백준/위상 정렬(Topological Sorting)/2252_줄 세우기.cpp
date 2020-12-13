//
//  2252_줄 세우기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/09.
//  Copyright © 2020 장우진. All rights reserved.
//
// 두 방법 모두 40ms로, 실행 시간은 같게 나왔다.
// 첫 번째 방법: dfs로 키가 큰 녀석으로 들어가 작은 녀석을 탐색하고 방문하지 않은(순서를 알 수 없는)
// 녀석들은 방문 배열(visited)로 알아내 마지막에 임의로 출력하였다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 32000 + 1;

int n, m;
int visited[MAX];
vector<vector<int>> student(MAX);

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < student[x].size(); ++i) {
		int next = student[x][i];
		if (!visited[next])
			dfs(next);
	}
	printf("%d ", x);
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		student[b].push_back(a);
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!student[i].empty() && !visited[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!visited[i])
			printf("%d ", i);
	printf("\n");
	return 0;
}

// 두 번째 방법: 작은 녀석들을 먼저 출력한다. 그러므로 큐를 이용하며, 들어오는 간선을 하나씩 제거한다.
// 만일 큐가 비었을 때까지도 모든 노드의 위상이 정렬되어 있지 않다면 싸이클이 있음에 자명한다.

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 32000 + 1;
int in[MAX];

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	vector<vector<int> > student(n+1);

	while (m--) {
		scanf("%d %d", &a, &b);
		student[a].push_back(b);
		in[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (!in[i]) // in이 0이라는 것은 키가 더 작은 녀석이 없다는 뜻
			q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		printf("%d ", x);

		for (auto next : student[x]) {
			--in[next]; // 들어오는 간선 하나가 없어졌다고 볼 수 있다
			if (in[next] == 0)
				q.push(next);
		}
	}
	printf("\n");
	return 0;
}

