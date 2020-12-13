//
//  15686_치킨 배달.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/07.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 단순한 조합 문제. 거리를 미리 구해놓으면 좀 더 빠를 것이다. 큰 차이는 없다.
 알고리즘: dfs + 백트래킹 + 완전 탐색
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> home, chicken;
vector<pii> chosen;
const int INF = 987654321;
int n, m, ans = INF;

void dfs(int x, int cnt) {
	if (cnt == m) {
		int total = 0;
		for (auto& h: home) {
			int min_d = INF;
			for (auto& c: chosen) {
				int dx = abs(h.first - c.first);
				int dy = abs(h.second - c.second);
				min_d = min(min_d, dx + dy);
			}
			total += min_d;
		}
		ans = min(ans, total);
		return;
	}
	for (int i = x; i < chicken.size(); ++i) {
		chosen.push_back(chicken[i]);
		dfs(i+1, cnt+1);
		chosen.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			if (x == 1) home.push_back( {i, j} );
			else if (x == 2) chicken.push_back( {i, j} );
		}
	}
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}

