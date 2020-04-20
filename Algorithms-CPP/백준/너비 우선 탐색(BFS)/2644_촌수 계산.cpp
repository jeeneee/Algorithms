//
//  2644_촌수 계산.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];

int main() {
	int n, start, end, m, x, y;
	cin >> n >> start >> end >> m;
	while (m--) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int ans = 0;
	bool found = false;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int x = q.front();
			q.pop();
			if (x == end) {
				found = true;
				break;
			}
			for (auto& y : graph[x]) {
				if (!visited[y]) {
					q.push(y);
					visited[y] = true;
				}
			}
		}
		if (found) break;
		++ans;
	}
	if (!found) ans = -1;
	cout << ans << endl;
	return 0;
}
