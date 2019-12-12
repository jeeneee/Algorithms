//
//  11866_조세퍼스 문제 0.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    queue<int> queue;
    vector<int> ans;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        queue.push(i + 1);
    }
    for (int i = 1; !queue.empty(); ++i) {
        if (i % k != 0) {
            queue.push(queue.front());
            queue.pop();
        }
        else {
            ans.push_back(queue.front());
            queue.pop();
        }
    }
    printf("<");
    for (int i = 0; i < ans.size(); ++i) {
        if (i == ans.size() - 1)
            printf("%d>\n", ans[i]);
        else
            printf("%d, ", ans[i]);
    }
    
    return 0;
}
