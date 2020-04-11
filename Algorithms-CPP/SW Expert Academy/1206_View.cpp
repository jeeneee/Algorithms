//
//  1206_View.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T = 10;
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			v.push_back(x);
		}
		int ans = 0;
		for (int i = 2; i < v.size()-2; ++i) {
			bool possible = true;
			int highest = 0;
			for (int j = i-2; j <= i+2; ++j) {
				if (i == j) continue;
				if (v[i] <= v[j]) {
					possible = false;
					break;
				}
				highest = max(highest, v[j]);
			}
			if (possible) ans += v[i] - highest;
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
