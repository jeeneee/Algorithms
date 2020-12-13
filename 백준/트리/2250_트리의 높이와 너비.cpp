//
//  2250_트리의 높이와 너비.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/15.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 중위 순회가 이 문제의 핵심이다. 중위 순회를 통해 x좌표를 알 수 있기 때문이다.
 돌면서 최소값과 최대값을 구하면 끝.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int INF = 987654321;
const int MAX = 10000 + 1;
int n, x;
int parent[MAX];
int minn[MAX], maxx[MAX];
pii tree[MAX];

void dfs(int root, int level) {
	if (tree[root].first > 0)
		dfs(tree[root].first, level + 1);
	minn[level] = min(minn[level], x);
	maxx[level] = max(maxx[level], x);
	++x;
	if (tree[root].second > 0)
		dfs(tree[root].second, level + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int root, left, right;
		cin >> root >> left >> right;
		tree[root] = make_pair(left, right);
		if (left != -1) parent[left] = root;
		if (right != -1) parent[right] = root;
	}
	int root = 0;
	for (int i = 1; i <= n; ++i) if (!parent[i]) root = i;
	
	x = 1;
	fill(minn, minn + MAX, INF);
	dfs(root, 1);
	
	int level = 0, width = 0;
	for (int i = 1; i <= n; ++i) {
		if (maxx[i] - minn[i] + 1 > width) {
			level = i;
			width = maxx[i] - minn[i] + 1;
		}
	}
	cout << level << ' ' << width << '\n';
	return 0;
}
