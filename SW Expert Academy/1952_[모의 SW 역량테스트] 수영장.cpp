//
//  1952_[모의 SW 역량테스트] 수영장.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/30.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 1일, 1개월, 3개월, 1년짜리 이용권이 있고 1년동안 이용 계획이 주어졌을 때, 최소 비용을 구하는 문제.
 해설: 완전 탐색 dfs 문제이다. 현재 달을 기준으로 dfs를 돌린다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int price[4];
int days[13];
int ans;

void calc(int month, int money) {
	if (month > 12) {
		ans = min(ans, money);
		return;
	}
	if (days[month] == 0)
		calc(month+1, money);
	else {
		calc(month+1, money + days[month] * price[0]);
		calc(month+1, money + price[1]);
	}
	// 10월달까지 가능
	if (month <= 10)
		calc(month+3, money + price[2]);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		for (int i = 0; i < 4; ++i)
			cin >> price[i];
		for (int i = 1; i <= 12; ++i)
			cin >> days[i];
		ans = 987654321;
		calc(1, 0);
		ans = min(ans, price[3]);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
