//
//  20-4 말버릇(HABIT).cpp
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

struct Comparator {
	const vector<int>& group;
	int t;
	
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}
	
	bool operator () (int a, int b) {
		if (group[a] != group[b])
			return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

vector<int> getSuffixArray(const string& s) {
	int n = (int)s.size();
	int t = 1;
	
	vector<int> group(n+1);
	for (int i = 0; i < n; ++i) group[i] = s[i];
	group[n] = -1;
	
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;
	while (t < n) {
		Comparator comp(group, t);
		sort(perm.begin(), perm.end(), comp);
		
		t <<= 1;
		if (t > n)
			break;
		
		vector<int> newGroup(n+1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		
		for (int i = 1; i < n; ++i) {
			if (comp(perm[i-1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i-1]];
		}
		group = newGroup;
	}
	return perm;
}

int commonPrefix(const string& s, int i, int j) {
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]) {
		++i; ++j; ++k;
	}
	return k;
}

int longestFrequent(int k, const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); ++i)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, k;
	cin >> t;
	string s;
	while (t--) {
		cin >> k >> s;
		cout << longestFrequent(k, s) << '\n';
	}
	return 0;
}
