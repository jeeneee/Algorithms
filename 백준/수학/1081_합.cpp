//
//  1081_합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <1019_책 페이지>와 비슷한 문제.
	  [a,b]사이에 존재하는 모든 정수에 있는 0~9 숫자의 합을 구하는 문제.
 해설: a가 0이 올 수 있음에 유의한다. 
 */
#include <iostream>
#include <vector>
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
	long long a, b, d = 1;
	cin >> a >> b;
	if (a == 0) a++;
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
	return 0;
}
