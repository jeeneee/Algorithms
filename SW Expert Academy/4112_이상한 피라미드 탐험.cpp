//
//  4112_이상한 피라미드 탐험.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/09.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 규칙을 찾아 최단 거리를 구하는 문제.
 해설: 등차 수열을 이용해 두 점의 좌표를 구한 후 규칙에 맞게 계산한다.
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int A[150];

pair<int, int> coord(int x) {
	int i, j;
	for (i = 0; i < 150; ++i)
		if (x <= A[i]) break;
	j = x - A[i-1];
	return {i, j};
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int sum = 0;
	for (int i = 0; i < 150; ++i) {
		sum += i;
		A[i] += sum;
	}
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int a, b;
		cin >> a >> b;
		pair<int, int> posA = coord(a);
		pair<int, int> posB = coord(b);
		int ans = 0;
		int diff_x = posA.first - posB.first;
		int diff_y = posA.second - posB.second;
		if (diff_x * diff_y <= 0)
			ans = abs(diff_x) + abs(diff_y);
		else ans = max(abs(diff_x), abs(diff_y));
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
