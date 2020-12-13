//
//  14267_내리 갈굼.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/14.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 쿼리마다 출력을 하는 것이 아니기 때문에 매번 lazy를 저장해놓고 마지막에 루트에서 아래로 내려가며
	  가중치를 업데이트한다.
 알고리즘: lazy propagation
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;
vector<int> g[MAX];
int w[MAX];

void calc(int u) {
	for (auto& v : g[u]) {
		w[v] += w[u];
		calc(v);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int p; cin >> p;
		if (p != -1)
			g[p].push_back(i);
	}
	while (m--) {
		int i, c;
		cin >> i >> c;
		w[i] += c;
	}
	calc(1);
	for (int i = 1; i <= n; ++i)
		cout << w[i] << ' ';
	cout << '\n';
	return 0;
}
