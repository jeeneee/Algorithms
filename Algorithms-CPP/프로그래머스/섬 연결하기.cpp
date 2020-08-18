//
//  섬 연결하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/08/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	if (u > v) swap(u, v);
	parent[v] = u;
}

int solution(int n, vector<vector<int>> costs) {
	for (int i = 0; i < n; ++i) parent[i] = i;
	
	sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
		return a[2] < b[2];
	});
	
	int sum = 0;
	for (auto& cost: costs) {
		int u = find(cost[0]);
		int v = find(cost[1]);
		if (u != v) {
			merge(u, v);
			sum += cost[2];
		}
	}
	return sum;
}

int main() {
	vector<vector<int>> costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
	cout << solution(4, costs) << endl; // 4
	return 0;
}
