//
//  라면공장.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0, idx = 0;
    priority_queue<int> pq;
    for (int day = 0; day < k; ++day) {
        if (day == dates[idx])
            pq.push(supplies[idx++]);
        if (stock == 0) {
            stock += pq.top();
            pq.pop();
            ++answer;
        }
        stock--;
    }
    return answer;
}
