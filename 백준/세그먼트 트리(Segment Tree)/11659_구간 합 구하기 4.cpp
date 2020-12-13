//
//  11659_구간 합 구하기 4.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/20.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 배열의 값이 바뀌지 않을 때 다이나믹 프로그래밍으로 구간 합을 구하는 문제
 부분합을 이용하였다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> psum(n+1);
	psum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> psum[i];
		psum[i] += psum[i-1];
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << psum[b] - psum[a-1] << '\n';
	}
	return 0;
}
