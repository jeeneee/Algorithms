//
//  1837_암호 제작.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/20.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: n은 두 소수인 p, q의 곱으로 생성되었다. 두 수 중에서 k보다 작은 수가 있다면 BAD, 반대면 GOOD.
 해설: n의 범위가 너무 크기 때문에 k를 이용해 풀어야 한다.
	  k 이하의 모든 소수를 구한 뒤, n이 [2~k-1] 사이의 수로 나누어 떨어진다면 BAD, 반대면 GOOD이다.
 키워드: 소수, 에라토스테네스의 체, 큰 수의 나눗셈
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000000 + 1;
bool prime[MAX];

void sieve(int n) {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i*i <= n; ++i)
		if (prime[i])
			for (int j = i*i; j <= n; j += i)
				prime[j] = false;
	return;
}

bool divide(string p, int k) {
	int mod = 0;
	for (int i = 0; i < p.size(); ++i)
		mod = (mod * 10 + (p[i] - '0')) % k;
	return mod == 0;
}

int main() {
	string p;
	int k;
	cin >> p >> k;
	sieve(k);
	for (int i = 2; i < k; ++i)
		if (prime[i] && divide(p, i)) {
			cout << "BAD " << i << '\n';
			return 0;
		}
	cout << "GOOD\n";
	return 0;
}
