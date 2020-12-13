//
//  1655_가운데를 말해요.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/09.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, x;
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (i == 0)
            maxHeap.push(x);
        else if (i == 1) {
            if (maxHeap.top() > x) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            } else
                minHeap.push(x);
        }
        else {
            if (maxHeap.size() == minHeap.size()) {
                if (x <= minHeap.top())
                    maxHeap.push(x);
                else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }
            } else {
                if (x >= maxHeap.top())
                    minHeap.push(x);
                else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                }
            }
        }
        printf("%d\n", maxHeap.top());
    }
    return 0;
}
