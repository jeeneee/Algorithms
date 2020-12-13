//
//  프린터.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/09.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int> pq;
	for (int i = 0; i < priorities.size(); ++i) {
		q.push({ priorities[i], i });
		pq.push(priorities[i]);
	}
	int cnt = 0;
	while (!q.empty()) {
		int rank = q.front().first;
		int idx = q.front().second;
		q.pop();
		if (rank == pq.top()) {
			pq.pop();
			++cnt;
			if (idx == location) {
				answer = cnt;
				break;
			}
		}
		else q.push({ rank, idx });
	}
    return answer;
}

int main() {
	cout << solution({2,1,3,2}, 2) << endl;
	return 0;
}
