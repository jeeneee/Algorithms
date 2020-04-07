//
//  [A형 준비 문제] 입국 심사(D4).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/07.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: m명의 승객이 소요시간이 각자 다른 n개의 심사대에서 입국 심사를 받는다.
	  여기서 가장 오래 걸리는 시간은 (n개의 심사대에서 가장 큰 값 x m명)이다. 이를 이용해 이분 탐색을 진행한다.
 알고리즘: 이분 탐색
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
long long t[MAX];
int n, m;

long long binarySearch(long long lo, long long hi) {
	long long ret = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; ++i)
			sum += mid / t[i];
		if (sum < m) lo = mid + 1;
		else {
			hi = mid - 1;
			ret = mid;
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &n, &m);
		long long lo = 0;
		long long hi = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &t[i]);
			hi = max(hi, t[i] * m);
		}
		printf("#%d %lld\n", tc, binarySearch(lo, hi));
	}
	return 0;
}
