//
//  16916_부분 문자열.cpp
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

vector<int> getPartialMatch(const string& s) {
	int m = (int)s.size();
	vector<int> pi(m, 0);
	int j = 0;
	for (int i = 1; i < m; ++i) {
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

bool hasPartialArray(const string& H, const string& N) {
	int n = (int)H.size();
	int m = (int)N.size();
	vector<int> pi = getPartialMatch(N);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && H[i] != N[j]) j = pi[j-1];
		if (H[i] == N[j]) {
			++j;
			if (j == m)
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string H, N;
	cin >> H >> N;
	cout << hasPartialArray(H, N) << endl;
	return 0;
}
