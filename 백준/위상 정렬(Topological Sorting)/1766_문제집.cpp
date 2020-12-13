//
//  1766_문제집.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/10.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int in[32001];

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	vector<vector<int>> edge(n+1);
	
	while (m--) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		in[b]++;
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; ++i)
		if (!in[i])
			pq.push(i);

	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();
		
		printf("%d ", x);
		
		for (auto next : edge[x]) {
			if (--in[next] == 0)
				pq.push(next);
		}
	}
	printf("\n");
	return 0;
}
