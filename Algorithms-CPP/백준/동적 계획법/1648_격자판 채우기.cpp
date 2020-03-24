//
//  1648_격자판 채우기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/24.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: NxM 크기의 격자판을 1x2 크기의 도미노로 채우는 문제.
 해설: 다이나믹 프로그래밍이 필요한 문제이다. 주석 참고.
 알고리즘: 다이나믹 프로그래밍
 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 14;
int dp[MAX*MAX][1 << MAX];
int n, m;

// num=0부터 n*m-1까지의 칸, state=num칸부터 num+m-1칸까지의 상태
int go(int num, int state) {
	// 기저 사례
	if (num == n*m && state == 0)
		return 1;
	if (num >= n*m)
		return 0;
	if (dp[num][state] != -1)
		return dp[num][state];
	
	int& ret = dp[num][state];
	ret = 0;
	if (state & 1) { // 놓을 수 없는 경우 다음 칸으로 넘어간다.
		ret = go(num+1, (state >> 1));
	} else { // 2x1과 1x2를 채울 수 있다.
		ret = go(num+1, (state >> 1) | (1 << (m-1)));
		if ((num%m) != (m-1) && (state & 2) == 0)
			ret += go(num+2, state >> 2);
	}
	ret %= 9901;
	return ret;
}

int main() {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << '\n';
	return 0;
}
