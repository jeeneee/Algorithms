//
//  [모의 SW 역량테스트] 보호 필름.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/28.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 2차원 배열에서 각 열을 기준으로 K개 이상 같은 수가 나오면 패스한다.
	  행을 기준으로 행 전체를 같은 수로 만들 수 있을 때, 최소값을 구하는 문제.
 해설: 맵을 바로바로 업데이트하지 않고 행을 저장한 다음 마지막 체크할 때에 지역 변수로 업데이트해줬다.
	  dfs의 기저 사례를 반드시 넣어줘야 시간초과가 나지 않는다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[13][20];
int s[13];
int n, m, k, ans;

bool pass() {
	int t, cnt, state;
	bool pass;
	for (int j = 0; j < m; ++j) {
		t = 3;
		cnt = 0;
		pass = false;
		for (int i = 0; i < n; ++i) {
			state = (s[i] == -1 ? map[i][j] : s[i]);
			if (t == state)
				cnt++;
			else {
				t = state;
				cnt = 1;
			}
			if (cnt >= k) {
				pass = true;
				break;
			}
		}
		if (!pass) return false;
	}
	return true;
}

void dfs(int idx, int state, int cnt) {
	if (cnt >= ans) return;
	s[idx] = state;
	if (idx == n-1) {
		if (!pass()) return;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] != -1) cnt++;
		ans = min(ans, cnt);
		return;
	}
	dfs(idx+1, -1, cnt);
	dfs(idx+1, 0, cnt+1);
	dfs(idx+1, 1, cnt+1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i) {
			s[i] = -1;
			for (int j = 0; j < m; ++j) {
				cin >> map[i][j];
			}
		}
		ans = k;
		dfs(0, -1, 0);
		dfs(0, 0, 1);
		dfs(0, 1, 1);
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}

