//
//  6782_현주가 좋아하는 제곱근 놀이.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/14.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		long long n, m;
		scanf("%lld", &n);
		int cnt = 0;
		while (n != 2) {
			m = sqrt(n);
			if (m * m == n) {
				n = m;
				++cnt;
			}
			else {
				cnt += (m+1) * (m+1) - n + 1;
				n = m+1;
			}
		}
		printf("#%d %d\n", tc, cnt);
	}
	return 0;
}
