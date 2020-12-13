//
//  2309_일곱 난쟁이.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/19.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

const int N = 9;
int height[N];
bool visited[N];
vector<int> cand;
bool flag;

void dfs(int idx, int total, int cnt) {
	if (flag) return;
	if (cnt == 7) {
		if (total != 100) return;
		sort(all(cand));
		for (auto& a : cand)
			cout << a << ' ';
		cout << endl;
		flag = true;
		return;
	}
	for (int i = idx; i < N; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		cand.push_back(height[i]);
		dfs(i+1, total+height[i], cnt+1);
		cand.pop_back();
		visited[i] = false;
	}
}

int main() {
	for (int i = 0; i < N; ++i)
		cin >> height[i];
	dfs(0, 0, 0);
	return 0;
}
