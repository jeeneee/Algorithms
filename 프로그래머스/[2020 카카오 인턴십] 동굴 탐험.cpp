//
//  [2020 카카오 인턴십] 동굴 탐험.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/24.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> chk;
bool cycle;

void dfs(int cur) {
	if (cycle) return;
	chk[cur] = 0;
	for (auto& next: graph[cur]) {
		if (chk[next] == -1) dfs(next);
		else if (chk[next] == 0) {
			cycle = true;
			return;
		}
	}
	chk[cur] = 1;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	vector<vector<int>> temp(n);
	graph.resize(n);
	for (auto& p: path) {
		temp[p[0]].push_back(p[1]);
		temp[p[1]].push_back(p[0]);
	}
	queue<int> q;
	vector<bool> visited(n, false);
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto& next: temp[now]) {
			if (!visited[next]) {
				visited[next] = true;
				graph[now].push_back(next);
				q.push(next);
			}
		}
	}
	for (auto& o: order)
		graph[o[0]].push_back(o[1]);
	chk.assign(n, -1);
	cycle = false;
	dfs(0);
	return !cycle;
}

int main() {
	vector<vector<int>> path = {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}};
	vector<vector<int>> order = {{8,5},{6,7},{4,1}};
	cout << solution(9, path, order) << endl;
	return 0;
}
