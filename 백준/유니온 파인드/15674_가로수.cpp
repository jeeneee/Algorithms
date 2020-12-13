//
//  15674_가로수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/26.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 어려웠던 문제. 다시 풀어보자. 특히 getMin부분.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
/*
 t1:: 은행 나무 심는 비용
 t2:: 플라타너스 나무 심는 비용
 tt1:: 루트 i에 해당하는 모든 은행 나무를 심는 비용
 tt2:: 루트 i에 해당하는 모든 플라타너스 나무를 심는 비용
 */
const int MAXN = 200000 + 1;
int n;
int parent[MAXN], level[MAXN], enemy[MAXN], t1[MAXN], t2[MAXN];
ll tt1[MAXN], tt2[MAXN], ans;

// 초기화
void init() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		level[i] = 1;
		enemy[i] = -1;
	}
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int merge(int u, int v) {
	if (u == -1 || v == -1) return max(u, v);
	u = find(u); v = find(v);
	if (u == v) return u;
	if (level[u] > level[v]) swap(u, v);
	if (level[u] == level[v]) level[v]++;
	// u를 v에 합치면서 비용도 함께 더한다.
	parent[u] = v;
	tt1[v] += tt1[u];
	tt2[v] += tt2[u];
	return v;
}

ll getMin(int u) {
	// 상대가 있는 경우 그에 맞게 최소값을 구해야한다.
	if (enemy[u] != -1)
		return min(tt1[u] + tt2[enemy[u]], tt1[enemy[u]] + tt2[u]);
	return min(tt1[u], tt2[u]);
}

void query(int c, int u, int v) {
	int a, b, root = 0;
	switch (c) {
		case 0: // same tree
			u = find(u); v = find(v);
			// 이미 같은 경우 종료
			if (u == v) return;
			// u, v와 연관된 비용을 제거
			ans -= (getMin(u) + getMin(v));
			a = merge(u, v); b = merge(enemy[u], enemy[v]);
			enemy[a] = b;
			if (b != -1) enemy[b] = a;
			// 합친 루트의 비용을 더한다.
			ans += getMin(a);
			break;
		case 1: // different tree
			u = find(u); v = find(v);
			if (u == enemy[v]) return;
			ans -= (getMin(u) + getMin(v));
			a = merge(u, enemy[v]); b = merge(v, enemy[u]);
			enemy[a] = b;
			enemy[b] = a;
			ans += getMin(a);
			break;
		case 2: // t1[u] = v
			root = find(u);
			ans -= getMin(root);
			tt1[root] = tt1[root] - t1[u] + v;
			t1[u] = v;
			ans += getMin(root);
			break;
		case 3: // t2[u] = v
			root = find(u);
			ans -= getMin(root);
			tt2[root] = tt2[root] - t2[u] + v;
			t2[u] = v;
			ans += getMin(root);
			break;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int d, q, c, a, b;
	cin >> n >> d;
	init();
	for (int i = 1; i <= n; ++i) {
		cin >> t1[i] >> t2[i];
		tt1[i] = t1[i]; tt2[i] = t2[i];
		ans += min(t1[i], t2[i]);
	}
	while (d--) {
		cin >> c >> a >> b;
		query(c, a, b);
	}
	cout << ans << '\n';
	
	cin >> q;
	while (q--) {
		cin >> c >> a >> b;
		query(c, a, b);
		cout << ans << '\n';
	}
	return 0;
}
