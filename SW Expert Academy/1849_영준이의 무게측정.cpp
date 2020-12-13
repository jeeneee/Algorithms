//
//  1849_영준이의 무게측정.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/07.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 유니온 파인드 문제. 랭크를 잘 이용해야 한다. 다시 풀어보자.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
int parent[MAX];
int weight[MAX];
int level[MAX];
int n, m;

void init() {
	for (int i = 0; i <= n; ++i) {
		parent[i] = 0;
		weight[i] = 0;
		level[i] = 1;
	}
}

int find(int u) {
	if (!parent[u]) return u;
	int t = parent[u];
	parent[u] = find(parent[u]);
	weight[u] += weight[t];
	return parent[u];
}

void merge(int u, int v, int w) {
	int pu = find(u), pv = find(v);
	if (pu == pv) return;
	int diff = weight[v] - weight[u];
	if (level[pu] > level[pv]) {
		swap(pu, pv);
		w = -w;
		diff = -diff;
	}
	weight[pu] = w + diff;
	parent[pu] = pv;
	if (level[pu] == level[pv]) level[pv]++;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &n, &m);
		init();
		printf("#%d", tc);
		while (m--) {
			char op[3];
			int a, b;
			scanf("%s %d %d", op, &a, &b);
			if (op[0] == '!') {
				int w;
				scanf("%d", &w);
				merge(a, b, w);
			} else {
				if (find(a) != find(b))
					printf(" UNKNOWN");
				else {
					printf(" %d", weight[a] - weight[b]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
