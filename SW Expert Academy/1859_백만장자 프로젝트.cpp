//
//  1859_백만장자 프로젝트.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/10.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 해설: 뒤에서 더 큰 수가 나오면 재귀를 써야하는데, 뒤에서부터 시작하면 고려할 필요가 없다.
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
long long price[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> price[i];
		int num = 0;
		long long resell = 0;
		long long total = 0;
		for (int i = n-1; i >= 0; --i) {
			if (price[i] > resell) {
				total += resell * num;
				resell = price[i];
				num = 0;
			} else {
				num++;
				total -= price[i];
			}
		}
		total += resell * num;
		cout << "#" << tc << " " << total << "\n";
	}
	return 0;
}
