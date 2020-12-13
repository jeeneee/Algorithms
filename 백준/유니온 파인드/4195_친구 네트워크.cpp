//
//  4195_친구 네트워크.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/03.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 관계 네트워크에 관한 문제로, 수가 아닌 알파벳으로 입력받는다. 입력받는 즉시 부모가 없는 경우
	  부모를 자기로 설정하고 자신의 네트워크의 원소 수를 1로 설정한다. merge에선 속도 향상을 위해
	  rank를 이용해 find에서 시간 소모를 줄여준다.
 알고리즘: 유니온 파인드 + 해싱
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> level, num;

string find(const string& u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int merge(string& u, string& v) {
	u = find(u); v = find(v);
	if (u == v) return num[v];
	if (level[u] > level[v]) swap(u, v);
	if (level[u] == level[v]) level[v]++;
	parent[u] = v;
	return num[v] += num[u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		parent.clear();
		level.clear();
		num.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string u, v;
			cin >> u >> v;
			if (parent[u].empty()) {
				parent[u] = u;
				num[u] = 1;
			}
			if (parent[v].empty()) {
				parent[v] = v;
				num[v] = 1;
			}
			cout << merge(u, v) << '\n';
		}
	}
	return 0;
}
