//
//  20-3 재하의 금고(JAEHASAFE).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 환형 시프트(circular shift)
 단순히 haystack을 하나 더 이어붙여 kmp알고리즘을 이용한다.
 시간복잡도 : O(|L|) |L|=문자열 길이
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getPartialMatch(const string& N) {
	int m = (int)N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin+matched-1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
	int n = (int)H.size(), m = (int)N.size();
	vector<int> ret, pi = getPartialMatch(N);
	int begin = 0, matched = 0;
	
	while (begin + m <= n) {
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m)
				ret.push_back(begin);
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s[100];
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i <= n; ++i)
			cin >> s[i];
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0)
				ans += kmpSearch(s[i+1] + s[i+1], s[i])[0];
			else
				ans += kmpSearch(s[i] + s[i], s[i+1])[0];
		}
		cout << ans << '\n';
	}
	
	return 0;
}
