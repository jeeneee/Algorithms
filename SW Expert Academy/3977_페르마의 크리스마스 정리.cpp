//
//  3977_페르마의 크리스마스 정리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/16.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: "홀수인 소수 p가 어떤 두 자연수 a, b에 대해 p = a^2 + b^2 로 나타날 수 있다는 것과
	  p를 4로 나눈 나머지가 1이라는 것은 필요충분 조건이다."에 착안한 문제.
 해설: 범위가 100만 이하이므로 시간 내에 구할 수 있다. i+=4를 하지 않으면 시간초과, 여기서 2를 고려해야 한다.
 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000000 + 1;
bool prime[MAX];
bool squareSum[MAX];

void sieve() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i * i <= MAX-1; ++i)
		if (prime[i])
			for (int j = i*i; j <= MAX-1; j += i)
				prime[j] = false;
}

void getSquareSum() {
	for (int i = 1; i < 1000; ++i) {
		for (int j = 1; j < 1000; ++j) {
			if (i*i + j*j >= MAX) break;
			squareSum[i*i + j*j] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	sieve();
	getSquareSum();
	for (int tc = 1; tc <= T; ++tc) {
		int l, r, ans = 0;
		cin >> l >> r;
		if (l <= 2) ++ans;
		l += (5 - l % 4) % 4;
		for (int i = l; i <= r; i += 4)
			if (prime[i] && squareSum[i])
				++ans;
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
