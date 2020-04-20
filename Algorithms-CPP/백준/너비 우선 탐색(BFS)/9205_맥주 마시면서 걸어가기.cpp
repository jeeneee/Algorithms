//
//  9205_맥주 마시면서 걸어가기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};
Point p[102];
int d[102][102];
bool visited[102];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n+2; ++i)
			cin >> p[i].x >> p[i].y;
		for (int i = 0; i < n+2; ++i)
			for (int j = 0; j < n+2; ++j)
				d[i][j] = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
		queue<int> q;
		q.push(0);
		memset(visited, false, sizeof(visited));
		visited[0] = true;
		bool possible = false;
		while (!q.empty()) {
			int from = q.front();
			q.pop();
			if (from == n+1) {
				possible = true;
				break;
			}
			for (int to = 0; to < n+2; ++to)
				if (d[from][to] <= 1000 && !visited[to]) {
					visited[to] = true;
					q.push(to);
				}
		}
		if (possible) puts("happy");
		else puts("sad");
	}
	return 0;
}
