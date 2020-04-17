//
//  9015_배열의 분할.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/17.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		int state = 0, ans = 0;
		for (int i = 1; i < n; ++i) {
			if (arr[i] == arr[i-1]) continue;
			else if (arr[i] > arr[i-1]) {
				if (state == 0) state = 1;
				else if (state == -1) {
					state = 0;
					++ans;
				}
			} else if (arr[i] < arr[i-1]) {
				if (state == 0) state = -1;
				else if (state == 1) {
					state = 0;
					++ans;
				}
			}
		}
		cout << '#' << tc << ' ' << ++ans << '\n';
	}
	return 0;
}
