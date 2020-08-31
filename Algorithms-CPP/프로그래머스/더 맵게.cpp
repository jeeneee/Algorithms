//
//  더 맵게.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto t : scoville) pq.push(t);
    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        if (first >= K) break;
        int second = pq.top(); pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    if (pq.top() < K) answer = -1;
    return answer;
}
