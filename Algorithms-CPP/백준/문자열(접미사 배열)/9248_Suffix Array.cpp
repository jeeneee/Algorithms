//
//  9248_Suffix Array.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/12.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 LCP(Long Common Prefix) Array를 구하는 방법은 나중에 또 다시 보자.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t):group(_group), t(_t){}
	bool operator () (int a, int b) {
		if (group[a] != group[b])
			return group[a] < group[b];
		return group[a+t] < group[b+t];
	}
};

vector<int> getSuffixArray(const string& s) {
	int n = (int)s.size();
	
	vector<int> group(n+1);
	for (int i = 0; i < n; ++i) group[i] = s[i];
	group[n] = -1;
	
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;
	
	int t = 1;
	while (t < n) {
		Comparator comp(group, t);
		sort(perm.begin(), perm.end(), comp);
		
		t *= 2;
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

vector<int> getLCP(const string& s, const vector<int>& suf) {
	int n = (int)s.size();
	vector<int> ret(n, 0);
	vector<int>pos(n, 0);
	for (int i = 0; i < n; i++)
		pos[suf[i]] = i;
	for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
		if (pos[i] == n - 1) continue;
		for (int j = suf[pos[i] + 1]; s[i + k] == s[j + k]; k++);
		ret[pos[i]] = k;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	vector<int> suffix_array = getSuffixArray(s);
	vector<int> LCP_array = getLCP(s, suffix_array);
	for (auto& a : suffix_array)
		cout << a+1 << ' ';
	cout << '\n';
	cout << "x ";
	for (int i = 0; i < s.length()-1; ++i)
		cout << LCP_array[i] << ' ';
	cout << '\n';
	return 0;
}
