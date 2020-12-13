//
//  4008_[모의 SW 역량테스트] 숫자 만들기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/01.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 숫자 카드와 부호 카드가 주어지고 최대값과 최소값의 차이를 구하는 문제.
 해설: 숫자는 고정이고 계산 시 우선 순위를 고려하지 않고 왼쪽부터 오른쪽으로 순서대로 계산하기 때문에
	  쉬운 문제이다. 중복을 막기 위해 부호 별로 dfs를 돌린다.
 알고리즘: dfs 백트래킹
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 12;
int num[MAX];
int op[4];
int n, minRes, maxRes;

void dfs(int idx, int res) {
	if (idx == n-1) {
		minRes = min(minRes, res);
		maxRes = max(maxRes, res);
		return;
	}
	// +,-,*,/
	for (int i = 0; i < 4; ++i) {
		if (op[i]) {
			int temp = res;
			int next = num[idx+1];
			if (i == 0) temp += next;
			else if (i == 1) temp -= next;
			else if (i == 2) temp *= next;
			else temp /= next;
			op[i]--;
			dfs(idx+1, temp);
			op[i]++;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		for (int i = 0; i < 4; ++i)
			cin >> op[i];
		for (int i = 0; i < n; ++i)
			cin >> num[i];
		minRes = 987654321;
		maxRes = -987654321;
		dfs(0, num[0]);
		cout << "#" << tc << " " << maxRes - minRes << "\n";
	}
	return 0;
}
