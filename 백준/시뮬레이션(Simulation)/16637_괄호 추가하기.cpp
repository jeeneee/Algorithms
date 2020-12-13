//
//  16637_괄호 추가하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/13.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 사칙연산 우선순위에 상관없이 앞에서부터 계산한다. DFS에서 괄호는 연속된 부호가 나올 수 없음에 유의하고,
	  괄호가 있다면 미리 계산하여 배열에 넣어준 후 앞에서부터 계산한다.
 알고리즘: 백트래킹
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
vector<char> symbol;
vector<int> sel;
string expr;
int ans = -987654321;

void selectBracket(int idx, int cnt, int m) {
	if (cnt == m) {
		vector<int> num2;
		vector<char> symbol2;
		bool visited[10] = {0, };
		for (int i = 0; i < sel.size(); ++i) {
			if (sel[i]) {
				int temp = 0;
				char& c = symbol[i];
				if (c == '-') temp = num[i] - num[i+1];
				else if (c == '+') temp = num[i] + num[i+1];
				else if (c == '*') temp = num[i] * num[i+1];
				num2.push_back(temp);
				visited[i+1] = true;
			} else {
				if (!visited[i])
					num2.push_back(num[i]);
				symbol2.push_back(symbol[i]);
			}
		}
		if (!visited[sel.size()]) num2.push_back(num[sel.size()]);
		
		int res = num2[0];
		for (int i = 0; i < symbol2.size(); ++i) {
			if (symbol2[i] == '-') res -= num2[i+1];
			else if (symbol2[i] == '+') res += num2[i+1];
			else if (symbol2[i] == '*') res *= num2[i+1];
		}
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
