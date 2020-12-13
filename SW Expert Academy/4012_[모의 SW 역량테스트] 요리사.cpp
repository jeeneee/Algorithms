//
//  4012_[모의 SW 역량테스트] 요리사.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/01.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 전형적인 백트래킹 문제.
 해설: 중복이 생길 수 있으므로 0번째 요리는 방문을 표시하고 나머지 n/2-1개로 조합을 만든다.
	  두 개의 요리를 만드므로 반이 쪼개진다.
 알고리즘: dfs + 백트래킹
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 16;
int synergy[MAX][MAX];
bool team[16];
int n, ans;

int calc(const vector<int>& v) {
	int ret = 0;
	for (int i = 0; i < v.size(); ++i)
		for (int j = i+1; j < v.size(); ++j)
			ret += synergy[v[i]][v[j]] + synergy[v[j]][v[i]];
	return ret;
}

void dfs(int idx, int cnt) {
	if (cnt == n/2 - 1) {
		vector<int> A, B;
		for (int i = 0; i < n; ++i) {
			if (!team[i]) A.push_back(i);
			else B.push_back(i);
		}
		int synergy_A = calc(A);
		int synergy_B = calc(B);
		ans = min(ans, abs(synergy_A - synergy_B));
		return;
	}
	for (int i = idx; i < n; ++i) {
		team[i] = 1;
		dfs(i+1, cnt+1);
		team[i] = 0;
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> synergy[i][j];
		team[0] = 1;
		ans = 987654321;
		dfs(1, 0);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
