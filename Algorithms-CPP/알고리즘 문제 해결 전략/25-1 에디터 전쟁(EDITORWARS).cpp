//
//  25-1 에디터 전쟁(EDITORWARS).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/25.
//  Copyright © 2020 장우진. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; ++i) parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v) {
		if (u == -1 || v == -1) return max(u, v);
		u = find(u); v = find(v);
		if (u == v) return u;
		if (rank[u] > rank[v]) swap(u, v);
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
		size[v] += size[u];
		return v;
	}
	bool dis(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	bool ack(int u, int v) {
		u = find(u); v = find(v);
		if (enemy[u] == v) return false;
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1) enemy[b] = a;
		return true;
	}
};

int maxParty(const BipartiteUnionFind& buf, int n) {
	int ret = 0;
	for (int node = 0; node < n; ++node) {
		if (buf.parent[node] == node) {
			int enemy = buf.enemy[node];
			if (enemy > node) continue;
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		BipartiteUnionFind buf(n);
		int idx = 1;
		bool flag = false;
		for (int i = 1; i <= m; ++i) {
			string op;
			int a, b;
			cin >> op >> a >> b;
			if (op == "ACK") {
				if (!buf.ack(a, b)) {
					if (!flag)
						idx = i;
					flag = true;
				}
			} else {
				if (!buf.dis(a, b)) {
					if (!flag)
						idx = i;
					flag = true;
				}
			}
		}
		if (flag) {
			cout << "CONTRADICTION AT " << idx << '\n';
		} else {
			cout << "MAX PARTY SIZE IS " << maxParty(buf, n) << '\n';
		}
	}
	return 0;
}
