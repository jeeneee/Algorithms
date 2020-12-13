//
//  17281_야구(⚾).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/17.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 야구 문제인데 각 타자들의 이닝별 결과를 갖고 최대 점수를 획득하는 문제. 여기서 4번째 타자는 0번 선수로
	  이미 정해져있다.
 해설: 조합이 아닌 순열을 써야하고 4번째 타자는 도중에 0번 선수로 넣는다. 안타, 2루타, 3루타는 서로 같은 방법으로
	  해결하면 된다. 아웃과 홈런을 따로 처리한다.
 알고리즘: 백트래킹 DFS 순열
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 50;
int stat[MAX][9];
bool visited[9];
vector<int> order;
int n, ans;

void dfs(int cnt) {
	if (cnt == 8) {
		int score = 0;
		int turn = 0; // 턴
		int base[4]; // 홈, 1루, 2루, 3루 순
		for (int inning = 0; inning < n; ++inning) {
			int out = 0; // 이닝이 끝나면 아웃 초기화
			memset(base, 0, sizeof(base)); // 베이스도 비워져야 한다.
			while (out < 3) {
				int op = stat[inning][order[turn % 9]]; // 턴은 경기가 끝날 때까지 유지
				switch (op) {
					case 0: // 아웃
						out++;
						break;
					case 4: // 홈런
						base[0] = 1;
						for (int i = 0; i < 4; ++i) {
							score += base[i];
							base[i] = 0;
						}
						break;
					default: // 1,2,3루
						base[0] = 1;
						for (int i = 4-op; i < 4; ++i) {
							score += base[i];
							base[i] = 0;
						}
						for (int i = 3-op; i >= 0; --i) {
							base[i+op] = base[i];
							base[i] = 0;
						}
						break;
				}
				turn++;
			}
		}
		ans = max(ans, score);
		return;
	}
	for (int i = 1; i < 9; ++i) {
		if (!visited[i]) {
			if (cnt == 3) order.push_back(0); // 4번째 타자는 0번 선수
			visited[i] = true;
			order.push_back(i);
			dfs(cnt+1);
			if (cnt == 3) order.pop_back();
			order.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> stat[i][j];
		}
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}
