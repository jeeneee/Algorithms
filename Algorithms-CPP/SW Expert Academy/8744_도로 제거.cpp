//
//  8744_도로 제거.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/14.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int edge[10001];

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i)
			edge[i] = n-1;
		int ans = 987654321;
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			edge[a]--;
			edge[b]--;
		}
		for (int i = 1; i <= n; ++i)
			ans = min(ans, edge[i]);
		printf("#%d %d\n", tc, ans-1);
	}
	return 0;
}
