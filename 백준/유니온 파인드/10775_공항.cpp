//
//  10775_공항.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/04.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
int parent[MAX];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int g, p, cnt = 0;
	cin >> g >> p;
	for (int i = 1; i <= g; ++i) parent[i] = i;
	for (int i = 1; i <= p; ++i) {
		int x;
		cin >> x;
		x = find(x);
		if (x == 0) break;
		else {
			merge(x, x-1);
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
