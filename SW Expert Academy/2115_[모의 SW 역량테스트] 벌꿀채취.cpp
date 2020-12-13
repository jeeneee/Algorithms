//
//  2115_[모의 SW 역량테스트] 벌꿀채취.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/31.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 두 명의 일꾼이 가로로 m개의 벌통에서 꿀을 채취하는데 서로 겹치지 않고 최대 양은 c이다.
 해설: 최대 양이 정해져있어 2^m개의 경우의 수가 있다. 예를 들어, c=12, m=3이고 한 줄에 1, 10, 12가 있다면
	  max(1^2 + 10^2, 12^2) = 144가 된다. 따라서 모든 경우의 수를 dfs + 비트마스킹을 이용해 계산하고
	  구한 배열을 이용해 시뮬레이션을 for문으로 구성하여 답을 구한다.
 알고리즘: dfs + bit masking
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 10;
int map[MAX][MAX];
int value[MAX][MAX];
int n, m, c;

int calc(int x, int y, int used, int maxProfit) {
	if (used >= (int)pow(2.0, m))
		return maxProfit;
	int sum = 0;
	int profit = 0;
	for (int i = 0; i < m; ++i) {
		if (used & (1 << i)) {
			int honey = map[x][y+i];
			sum += honey;
			profit += honey * honey;
		}
	}
	if (sum <= c)
		maxProfit = max(maxProfit, profit);
	return calc(x, y, used+1, maxProfit);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> m >> c;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j+m <= n; ++j)
				value[i][j] = calc(i, j, 1, 0);
		
		int ans = 0;
		if (n >= 2*m)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n-2*m+1; ++j)
					for (int k = j + m; k < n-m+1; ++k)
						ans = max(ans, value[i][j] + value[i][k]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n-m+1; ++j)
				for (int ii = i+1; ii < n; ++ii)
					for (int jj = 0; jj < n-m+1; ++jj)
						ans = max(ans, value[i][j] + value[ii][jj]);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
