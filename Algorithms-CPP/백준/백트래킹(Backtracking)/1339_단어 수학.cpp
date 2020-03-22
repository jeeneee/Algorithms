//
//  1339_단어 수학.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/21.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: A~Z에서 최대 10개로 이루어진 수가 있다. 0~9를 대입해서 가장 큰 수를 만드는 문제.
 해설: 다항식으로 풀 수 있지만 여기선 백트래킹을 이용했다.
 알고리즘: 백트래킹
 O(N*N!) = 36,000,000
 */
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool visited[10];
int num[10];
vector<int> chosen;
long long ans;

void dfs(int cnt) {
	if (cnt == 10) {
		long long sum = 0;
		for (int i = 0; i < 10; ++i)
			sum += num[i] * chosen[i];
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			chosen.push_back(i);
			dfs(cnt+1);
			chosen.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string str[n];
	int temp[26] = {0, };
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		for (int j = 0; j < str[i].size(); ++j)
			temp[str[i][j] - 'A'] += (int)pow(10.0, str[i].size()-j-1);
	}
	for (int i = 0, j = 0; i < 26; ++i)
		if (temp[i]) num[j++] = temp[i];
	dfs(0);
	cout << ans << '\n';
	return 0;
}
