//
//  1966_프린터 큐.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        queue<pair<int, int> > q;
        priority_queue<int> pq;     // 우선 순위 큐 큰 값부터 정렬함.
        int n, m, cnt = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            q.push({x, i});
            pq.push(x);
        }
        while (!q.empty()) {
            int rank = q.front().first;
            int idx = q.front().second;
            q.pop();
            if (rank == pq.top()) {
                pq.pop();
                cnt++;
                if (idx == m) {
                    cout << cnt << endl;
                    break;
                }
            }
            else {
                q.push({rank, idx});
            }
        }
    }
    return 0;
}
