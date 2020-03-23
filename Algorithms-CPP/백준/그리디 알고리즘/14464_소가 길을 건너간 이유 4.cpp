//
//  14464_소가 길을 건너간 이유 4.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 소가 닭의 도움을 받아 길을 건넌다. 소 [A, B]에 닭 T가 포함되면 소는 길을 건널 수 있다.
 해설: 그리디 알고리즘이 필요하다. 소를 정렬하되, B, A 우선순위를 갖고 정렬해야 한다.
	  닭은 이진 검색 트리 자료구조를 사용하였다.
 알고리즘: 그리디 알고리즘 + 이진 검색 트리 자료구조
 O(NlogM)
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

multiset<int> chicken;
vector<pair<int, int>> cow;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	cow.resize(m);
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		chicken.insert(x);
	}
	for (int i = 0; i < m; ++i)
		cin >> cow[i].first >> cow[i].second;
	
	sort(all(cow), cmp);
	
	int cnt = 0;
	for (auto& c: cow) {
		auto it = chicken.lower_bound(c.first);
		if (it != chicken.end() && *it <= c.second) {
			cnt++;
			chicken.erase(it);
		}
	}
	cout << cnt << '\n';
	return 0;
}

