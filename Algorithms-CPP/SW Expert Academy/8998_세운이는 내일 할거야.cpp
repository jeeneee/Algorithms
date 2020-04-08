//
//  8998_세운이는 내일 할거야.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct Task {
	int t, d;
};
const int MAX = 1000000;
Task task[MAX];
int n;

bool cmp(const Task& a, const Task& b) {
	return a.d > b.d;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> task[i].t >> task[i].d;
		
		sort(task, task + n, cmp);
		
		int ans = 1234567890;
		for (int i = 0; i < n; ++i) {
			ans = min(ans, task[i].d);
			ans -= task[i].t;
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
