//
//  1005_ACM Craft.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/10.
//  Copyright © 2020 장우진. All rights reserved.
//
// 1st
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int delay[MAX];
int dp[MAX];
bool order[MAX][MAX];

int dfs(int dest, int n) {
	int &ref = dp[dest];
	if (ref != -1)
		return ref;
	
	int max_time = 0;
	for (int i = 1; i <= n; ++i) {
		if (order[i][dest] == 1)
			max_time = max(max_time, dfs(i, n));
	}
	return ref = max_time + delay[dest];
}

int main() {
	int t, n, k, x, y, w;
	scanf("%d", &t);
	while (t--) {
		memset(order, 0, sizeof(order));
		memset(dp, -1, sizeof(dp));
		
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &delay[i]);
		
		for (int i = 0; i < k; ++i) {
			scanf("%d %d", &x, &y);
			order[x][y] = 1;
		}
		
		scanf("%d", &w);
		
		printf("%d\n", dfs(w, n));
	}
	return 0;
}

// 2nd
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int delay[MAX];
int in[MAX];
int n;

int bfs(int dest, const vector<vector<int>>& v) {
	vector<int> ret(n+1, 0);
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (!in[i])
			q.push(i);
	
	while (in[dest] > 0) {
		int x = q.front();
		q.pop();
		for (auto next : v[x]) {
			ret[next] = max(ret[next], ret[x] + delay[x]);
			in[next]--;
			if (!in[next])
				q.push(next);
		}
	}
	return ret[dest] + delay[dest];
}

int main() {
	int t, k, x, y, w;
	scanf("%d", &t);
	while (t--) {
		memset(in, 0, sizeof(in));
		
		scanf("%d %d", &n, &k);
		vector<vector<int>> v(n+1);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &delay[i]);
		
		for (int i = 0; i < k; ++i) {
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			in[y]++;
		}
		
		scanf("%d", &w);
		
		printf("%d\n", bfs(w, v));
	}
	return 0;
}
