//
//  12899_데이터 구조.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2000000 + 1;
int tree[MAX];

void update(int x, int value) {
	for (; x < MAX; x += x&-x) tree[x] += value;
}

int kth(int x) {
	int res = 0;
	for (int i = 20; i >= 0; --i) {
		int p = res + (1 << i);
		if (p < MAX && tree[p] < x) {
			x -= tree[p];
			res += 1 << i;
		}
	}
	return res + 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int t, x;
		cin >> t >> x;
		if (t & 1) update(x, 1);
		else {
			int temp = kth(x);
			cout << temp << '\n';
			update(temp, -1);
		}
	}
	return 0;
}
