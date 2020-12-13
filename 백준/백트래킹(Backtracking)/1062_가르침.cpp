//
//  1062_가르침.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
bool al[26];
string s[50];
int ans = 0;

void back_tracking(int x, int cnt) {
	if (cnt == k) {
		int tmp_ans = 0;
		for (int i = 0; i < n; ++i) {
			bool flag = true;
			for (int j = 0; j < s[i].length(); ++j) {
				if (!al[s[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)
				tmp_ans++;
		}
		ans = max(ans, tmp_ans);
		return;
	}
	
	for (int i = x; i < 26; ++i) {
		if (al[i])
			continue;
		al[i] = 1;
		back_tracking(i+1, cnt+1);
		al[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	
	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	} else if (k == 26) {
		cout << n << '\n';
		return 0;
	}
	
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		s[i] = s[i].substr(4);
		for (int j = 0; j < 4; ++j) {
			s[i].pop_back();
		}
	}
	// "anta", "tica"
	al['a'-'a'] = al['c'-'a'] = al['i'-'a'] = al['n'-'a'] = al['t'-'a'] = 1;
	k -= 5;
	
	back_tracking(0, 0);
	
	cout << ans << '\n';
	
	return 0;
}
