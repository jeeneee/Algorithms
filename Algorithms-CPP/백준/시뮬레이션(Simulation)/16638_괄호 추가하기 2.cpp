//
//  16638_괄호 추가하기 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/13.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <16637_괄호 추가하기>와 마찬가지로 괄호를 우선적으로 처리한다. 여기에 곱셈 우선 순위 조건이 추가되었다.
	  하지만 괄호를 먼저 처리하고 곱셈을 처리하여 수와 연산 기호를 저장하여 순서대로 계산하면 된다.
 알고리즘: 백트래킹
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> num;
vector<char> symbol;
vector<int> sel;
string expr;
int ans = -987654321;

int calc(int a, int b, char c) {
	if (c == '-') return a - b;
	else if (c == '+') return a + b;
	else return a * b;
}

void selectBracket(int idx, int cnt, int m) {
	if (cnt == m) {
		// 괄호 처리
		vector<int> num2;
		vector<char> symbol2;
		bool visited[10] = {0, };
		for (int i = 0; i < sel.size(); ++i) {
			if (sel[i]) {
				num2.push_back(calc(num[i], num[i+1], symbol[i]));
				visited[i+1] = true;
			} else {
				if (!visited[i])
					num2.push_back(num[i]);
				symbol2.push_back(symbol[i]);
			}
		}
		if (!visited[sel.size()]) num2.push_back(num[sel.size()]);
		// 곱셈 우선 처리
		vector<int> num3;
		vector<char> symbol3;
		memset(visited, false, sizeof(visited));
		bool mul = false;
		for (int i = 0; i < symbol2.size(); ++i) {
			if (symbol2[i] == '*') {
				if (mul) {
					num3[num3.size()-1] *= num2[i+1];
					visited[i+1] = true;
					continue;
				}
				num3.push_back(calc(num2[i], num2[i+1], symbol2[i]));
				visited[i+1] = true;
				mul = true;
			} else {
				if (!visited[i])
					num3.push_back(num2[i]);
				symbol3.push_back(symbol2[i]);
				mul = false;
			}
		}
		if (!visited[symbol2.size()]) num3.push_back(num2[symbol2.size()]);
		// 순서대로 계산
		int res = num3[0];
		for (int i = 0; i < symbol3.size(); ++i)
			res = calc(res, num3[i+1], symbol3[i]);
		ans = max(ans, res);
		return;
	}
	for (int i = idx; i < symbol.size(); ++i) {
		if (i > 0 && sel[i-1]) continue;
		sel[i] = 1;
		selectBracket(i+1, cnt+1, m);
		sel[i] = 0;
	}
}

int main() {
	int n;
	cin >> n;
	cin >> expr;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) num.push_back(expr[i] - '0');
		else symbol.push_back(expr[i]);
	}
	sel.resize(symbol.size());
	for (int i = 0; i <= symbol.size()/2; ++i) {
		selectBracket(0, 0, i);
	}
	cout << ans << '\n';
	return 0;
}
