//
//  15668_방 번호.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/26.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int x, vector<bool>& ch) {
	while (x) {
		if (ch[x % 10])
			return false;
		ch[x % 10] = true;
		x /= 10;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int a = -1, b = -1;
	for (int i = 1; i <= 98765; ++i) {
		if (n-i <= 0) break;
		vector<bool> ch(10, false);
		if (check(i, ch) && check(n-i, ch)) {
			a = n-i;
			b = i;
			break;
		}
	}
	if (a == -1 && b == -1)
		cout << -1 << '\n';
	else
		cout << a << " + " << b << '\n';
	return 0;
}
