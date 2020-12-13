//
//  [2020 KAKAO BLIND RECRUITMENT] 외벽 점검.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/14.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int weak_size, dist_size, ans;

void fix(vector<int>& dist, deque<int>& dq) {
	int now = 0, prev = 0, cnt = 0;
	vector<int> chk(weak_size, false);
	for (int i = 0; i < dist_size; ++i) {
		while (now < weak_size && dq[now] - dq[prev] <= dist[i])
			chk[now++] = true;
		cnt++;
		prev = now;
		if (prev >= weak_size) break;
	}
	for (int i = 0; i < weak_size; ++i)
		if (!chk[i]) return;
	ans = min(ans, cnt);
}

void backtracking(vector<int>& dist, vector<bool>& chk, vector<int>& weak,
				  vector<int>& temp, deque<int>& dq) {
	if (temp.size() == dist_size) {
		fix(temp, dq);
		return;
	}
	for (int i = 0; i < dist_size; ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		temp.push_back(dist[i]);
		backtracking(dist, chk, weak, temp, dq);
		temp.pop_back();
		chk[i] = false;
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	weak_size = weak.size();
	dist_size = dist.size();
	deque<int> dq;
	ans = 10;
	for (int i = 0; i < weak_size; ++i) dq.push_back(weak[i]);
	for (int i = 0; i < weak_size; ++i) {
		vector<bool> chk(dist_size, false);
		vector<int> temp;
		backtracking(dist, chk, weak, temp, dq);
		dq.push_back(dq.front() + n);
		dq.pop_front();
	}
	if (ans == 10) ans = -1;
    return ans;
}

int main() {
	int n = 12;
	vector<int> weak = {1, 3, 4, 9, 10};
	vector<int> dist = {3, 5, 7};
	cout << solution(n, weak, dist) << endl;
	return 0;
}
