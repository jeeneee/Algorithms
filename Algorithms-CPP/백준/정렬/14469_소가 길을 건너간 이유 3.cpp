//
//  14469_소가 길을 건너간 이유 3.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 모든 소의 도착한 시간, 소요 시간이 주어지고 최소 시간을 구하는 문제.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> cow(n);
	for (int i = 0; i < n; ++i)
		cin >> cow[i].first >> cow[i].second;
	sort(cow.begin(), cow.end());
	int ans = 0;
	for (auto& a: cow)
		ans = max(ans, a.first) + a.second;
	cout << ans << '\n';
	return 0;
}
