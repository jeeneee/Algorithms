//
//  16639_괄호 추가하기 3.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/19.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 연산 우선순위가 존재하지만 <괄호 추가하기 1,2>와는 다르게 괄호의 중첩이 허용된다.
 그렇기 때문에 곱셈의 우선순위를 괄호로 처리하면 무시할 수 있다.
 O(N^3)의 DP문제로 변형이 가능하다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 10;
int maxCache[MAX][MAX], minCache[MAX][MAX];
int n;
string expr;

int calc(int x, int y, char op) {
	switch (op) {
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		default:
			return 0;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> expr;
	int numCnt = n / 2 + 1;
	for (int i = 0; i < numCnt; ++i) {
		for (int j = 0; j < numCnt; ++j) {
			minCache[i][j] = INT_MAX;
			maxCache[i][j] = INT_MIN;
		}
		minCache[i][i] = maxCache[i][i] = expr[i * 2] - '0';
	}
	for (int cnt = 1; cnt < numCnt; ++cnt) {
		for (int i = 0; i < numCnt - cnt; ++i) {
			int j = i + cnt;
			for (int k = i; k < j; ++k) {
				char op = expr[k * 2 + 1];
				int cand[4] = {
					calc(minCache[i][k], minCache[k+1][j], op),
					calc(minCache[i][k], maxCache[k+1][j], op),
					calc(maxCache[i][k], minCache[k+1][j], op),
					calc(maxCache[i][k], maxCache[k+1][j], op)
				};
				sort(cand, cand+4);
				minCache[i][j] = min(minCache[i][j], cand[0]);
				maxCache[i][j] = max(maxCache[i][j], cand[3]);
			}
		}
	}
	cout << maxCache[0][numCnt-1] << endl;
	return 0;
}
