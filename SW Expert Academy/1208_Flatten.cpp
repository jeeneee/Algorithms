//
//  1208_Flatten.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T = 10;
	for (int tc = 1; tc <= T; ++tc) {
		int m;
		cin >> m;
		for (int i = 0; i < 100; ++i)
			cin >> a[i];
		while (m--) {
			sort(a, a+100);
			if (a[99] - a[0] <= 1)
				break;
			a[99]--;
			a[0]++;
		}
		sort(a, a+100);
		int ans = a[99] - a[0];
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
