//
//  17280_카풀 매칭.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <14464_소가 길을 건너간 이유 4>와 같은 문제.
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		multiset<int> passenger;
		vector<pair<int, int>> driver(m);
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			passenger.insert(x);
		}
		for (int i = 0; i < m; ++i)
			cin >> driver[i].first >> driver[i].second;
		
		sort(all(driver), cmp);
		
		int cnt = 0;
		for (auto& d: driver) {
			auto it = passenger.lower_bound(d.first);
			if (it != passenger.end() && *it <= d.second) {
				cnt++;
				passenger.erase(it);
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

