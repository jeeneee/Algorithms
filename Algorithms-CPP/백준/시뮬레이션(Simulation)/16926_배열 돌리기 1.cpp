//
//  16926_배열 돌리기 1.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/18.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 배열을 회전시키는 문제.
 해설: 회전 수가 한바퀴를 넘어설 때를 대비해 새로 계산한다. s를 통해 배열 안으로 진입하였다.
 */
#include <iostream>
using namespace std;

const int MAX = 300;
int A[MAX][MAX];
int n, m;

void rot(int r) {
	for (int s = 0; s < min(n, m) / 2; ++s) {
		int round = r;
		round %= 2 * (n + m - 4*s - 2);
		while (round--) {
			int temp = A[s][s];
			for (int j = s; j < m-s-1; ++j)
				A[s][j] = A[s][j+1];
			for (int i = s; i < n-s-1; ++i)
				A[i][m-s-1] = A[i+1][m-s-1];
			for (int j = m-s-1; j > s; --j)
				A[n-s-1][j] = A[n-s-1][j-1];
			for (int i = n-s-1; i > s; --i)
				A[i][s] = A[i-1][s];
			A[s+1][s] = temp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int r;
	cin >> n >> m >> r;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> A[i][j];
	rot(r);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
