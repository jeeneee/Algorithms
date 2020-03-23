//
//  5425_자리합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <1081_합>과 같은 문제.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long cnt[10];

void calc(long long n, long long d) {
	while (n) {
		cnt[n % 10] += d;
		n /= 10;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long a, b, d = 1;
		cin >> a >> b;
		if (a == 0) a++;
		memset(cnt, 0, sizeof(cnt));
		while (a <= b) {
			while (a % 10 != 0 && a <= b)
				calc(a++, d);
			if (a > b) break;
			while (b % 10 != 9 && a <= b)
				calc(b--, d);
			long long num = b/10 - a/10 + 1;
			for (int i = 0; i < 10; ++i)
				cnt[i] += num * d;
			a/=10; b/=10; d*=10LL;
		}
		long long ans = 0;
		for (int i = 0; i < 10; ++i)
			ans += cnt[i] * i;
		cout << ans << '\n';
	}
	return 0;
}
