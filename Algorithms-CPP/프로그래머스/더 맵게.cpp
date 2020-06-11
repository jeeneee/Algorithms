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
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); ++i)
        pq.push(scoville[i]);
    while (!pq.empty()) {
        int a = pq.top(); pq.pop();
        if (pq.empty()) {
            if (a < K) answer = -1;
            break;
        }
        int b = pq.top(); pq.pop();
        if (a >= K) break;
        pq.push(a + b * 2);
        ++answer;
    }
    return answer;
}
