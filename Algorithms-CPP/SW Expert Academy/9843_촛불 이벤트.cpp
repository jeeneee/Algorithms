//
//  9843_촛불 이벤트.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/22.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		long long n;
		cin >> n;
		long long ans = (sqrt(n*8 + 1) - 1) / 2;
		if (ans * (ans + 1) != n * 2) ans = -1;
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
