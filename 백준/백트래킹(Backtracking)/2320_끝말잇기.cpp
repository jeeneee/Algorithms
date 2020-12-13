//
//  2320_끝말잇기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/29.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 주어진 단어를 모두 활용한다면 위상 정렬이지만 이 문제는 백트래킹을 활용한 완전 탐색에 대한 문제이다.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 16;
char words[MAX][3];
int point[MAX], dp[MAX], n;
bool visited[MAX];

int backTracking(int here) {
	int& ref = dp[here];
	if (ref != -1) return ref;
	ref = 0;
	visited[here] = true;
	for (int there = 0; there < n; ++there)
		if (!visited[there] && words[here][1] == words[there][0])
			ref = max(ref, backTracking(there));
	visited[here] = false;
	return ref += point[here];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		words[i][0] = str[0];
		words[i][1] = str[str.size() - 1];
		point[i] = str.size();
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		memset(visited, false, sizeof(visited));
		memset(dp, -1, sizeof(dp));
		ans = max(ans, backTracking(i));
	}
	cout << ans << endl;
	return 0;
}
