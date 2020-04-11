//
//  [A형 준비 문제] 장훈이의 높은 선반.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;
int height[MAX];
int n, b, ans;

void dfs(int idx, int sum) {
	if (idx == n) {
		if (sum >= b)
			ans = min(ans, sum - b);
		return;
	}
	dfs(idx+1, sum);
	dfs(idx+1, sum + height[idx]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> b;
		for (int i = 0; i < n; ++i)
			cin >> height[i];
		ans = 987654321;
		dfs(0, 0);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
