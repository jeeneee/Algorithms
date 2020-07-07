//
//  1167_트리의 지름.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/07.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int farthestNode, maxDistance;
int n;

void dfs(int node, int dist) {
	for (int i = 0; i < graph[node].size(); ++i) {
		pair<int, int> next = graph[node][i];
		if (!visited[next.first]) {
			visited[next.first] = true;
			dfs(next.first, dist + next.second);
		}
	}
	
	if (dist > maxDistance) {
		maxDistance = dist;
		farthestNode = node;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	graph.resize(n+1);
	visited.resize(n+1);
	int from, to, dist;
	for (int i = 0; i < n; ++i) {
		cin >> from;
		while(1) {
			cin >> to;
			if (to == -1) break;
			cin >> dist;
			graph[from].push_back({ to, dist });
			graph[to].push_back({ from, dist });
		}
	}
	fill(visited.begin(), visited.end(), false);
	visited[1] = true;
	dfs(1, 0);
	fill(visited.begin(), visited.end(), false);
	visited[farthestNode] = true;
	dfs(farthestNode, 0);
	cout << maxDistance << endl;
	return 0;
}
