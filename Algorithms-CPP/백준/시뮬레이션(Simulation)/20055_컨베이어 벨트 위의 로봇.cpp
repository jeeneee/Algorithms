//
//  20055_컨베이어 벨트 위의 로봇.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/10/21.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	int zeros = 0;
	deque<pair<int, bool>> dq;
	
	cin >> n >> k;
	for (int i = 0; i < n * 2; ++i) {
		int a;
		cin >> a;
		dq.push_back({ a, false });
		if (a == 0) zeros++;
	}
	int step = 1;
	while (1) {
		dq.push_front(dq.back());
		dq.pop_back();
		if (dq[n-1].second) dq[n-1].second = false;
		for (int i = n-2; i >= 0; --i) {
			if (dq[i].second && !dq[i+1].second && dq[i+1].first) {
				dq[i].second = false;
				dq[i+1].second = i+1 == n-1 ? false : true;
				if (--dq[i+1].first == 0) zeros++;
			}
		}
		if (dq[0].first) {
			if (--dq[0].first == 0) zeros++;
			dq[0].second = true;
		}
		if (zeros >= k) break;
		step++;
	}
	cout << step << endl;
	return 0;
}
