//
//  9088_다이아몬드.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: N개의 다이아몬드 중 크기 차가 K 이하인 최대 개수를 구하는 문제.
 해설: 투포인터를 이용한다.
 알고리즘: 투포인터
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int n, k;
		scanf("%d %d", &n, &k);
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		sort(v.begin(), v.end());
		int lo = 0;
		int hi = 0;
		int ans = 0;
		while (hi < n) {
			if (v[hi] - v[lo] <= k) {
				ans = max(ans, hi-lo+1);
				hi++;
			}
			else lo++;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
