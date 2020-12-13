//
//  1251_단어 나누기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/20.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 주어진 단어를 세 단어로 나누어 뒤집고 합쳐 사전순으로 가장 앞선 단어를 만든다.
 알고리즘: 백트래킹
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

string s, ans;
vector<int> chosen;
int n;

void dfs(int idx, int cnt) {
	if (cnt == 2) {
		string s1, s2, s3;
		s1 = s.substr(0, chosen[0]);
		s2 = s.substr(chosen[0], chosen[1] - chosen[0]);
		s3 = s.substr(chosen[1]);
		reverse(all(s1)); reverse(all(s2)); reverse(all(s3));
		string temp = s1 + s2 + s3;
		ans = min(ans, temp);
		return;
	}
	for (int i = idx; i < n; ++i) {
		chosen.push_back(i);
		dfs(i+1, cnt+1);
		chosen.pop_back();
	}
}

int main() {
	cin >> s;
	n = s.length();
	ans.resize(n);
	fill(all(ans), 'z');
	dfs(1, 0);
	cout << ans << '\n';
	return 0;
}
