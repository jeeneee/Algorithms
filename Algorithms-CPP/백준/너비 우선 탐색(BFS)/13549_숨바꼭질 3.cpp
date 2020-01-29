//
//  13549_숨바꼭질 3.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 100000 + 1;
bool visited[MAX];

int main() {
    int n, k;
    cin >> n >> k;
    
    if(n > k) {
        cout << n-k << endl;
        return 0;
    }
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push( {0, n} );
    while (!pq.empty()) {
        int t = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        
        if (x == k) {
            cout << t << endl;
            break;
        }
        visited[x] = true;
        int nx[3] = {x-1, x+1, x*2};
        for (int i = 0; i < 3; ++i) {
            if (0 <= nx[i] && nx[i] < MAX && !visited[nx[i]]) {
                if (i != 2) pq.push( {t+1, nx[i]} );
                else pq.push( {t, nx[i]} );
            }
        }
    }
    
    return 0;
}
