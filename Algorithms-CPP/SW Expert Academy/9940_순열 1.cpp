//
//  9940_순열 1.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		string ans;
		set<int> s;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int tmp; cin >> tmp;
			s.insert(tmp);
		}
		if (*s.begin() == 1 && *s.rbegin() == n && s.size() == n)
			ans = "Yes";
		else ans = "No";
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
