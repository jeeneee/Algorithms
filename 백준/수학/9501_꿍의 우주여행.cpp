//
//  9501_꿍의 우주여행.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n, d, v, f, c;
		int cnt = 0;
		cin >> n >> d;
		for (int i = 0; i < n; ++i) {
			cin >> v >> f >> c;
			if (d * c <= f * v) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
