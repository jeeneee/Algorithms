//
//  6550_부분 문자열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/13.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		int i = 0;
		int j = 0;
		for (; j < t.size(); ++j) {
			if (s[i] == t[j]) {
				++i;
				if (i == s.size()) {
					cout << "Yes" << '\n';
					break;
				}
			}
		}
		if (j == t.size())
			cout << "No" << '\n';
	}
	return 0;
}
