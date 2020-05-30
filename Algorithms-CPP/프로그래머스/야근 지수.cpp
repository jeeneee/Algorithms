//
//  야근 지수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/30.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	priority_queue<int> q(works.begin(), works.end());
	for (int i = 0; i < n; ++i) {
		int tmp = q.top();
		if (tmp <= 0) return 0;
		q.pop();
		q.push(tmp - 1);
	}
	while (!q.empty()) {
		answer += (long long)q.top() * q.top();
		q.pop();
	}
	return answer;
}

int main() {
	vector<int> works = {3, 4, 3};
	cout << solution(4, works) << endl;
	return 0;
}
