//
//  4635_Speed Limit.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, v, t, d;
	int prev_t;
	while (1) {
		cin >> n;
		if (n == -1) break;
		prev_t = d = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v >> t;
			d += v * (t - prev_t);
			prev_t = t;
		}
		cout << d << " miles" << '\n';
	}
	return 0;
}
