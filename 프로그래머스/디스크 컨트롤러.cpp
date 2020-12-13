//
//  디스크 컨트롤러.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/15.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<vector<int>> jobs) {
    int answer = 0, now = 0, i = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (i < jobs.size() || !pq.empty()) {
        if (i < jobs.size() && now >= jobs[i][0]) {
            pq.push({ jobs[i][1], jobs[i][0] });
            ++i;
            continue;
        }
        if (!pq.empty()) {
            now += pq.top().first;
            answer += now - pq.top().second;
            pq.pop();
        }
        else now = jobs[i][0];
    }
    answer /= jobs.size();
    return answer;
}
