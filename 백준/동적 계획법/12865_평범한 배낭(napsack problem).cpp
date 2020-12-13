//
//  12865_평범한 배낭(napsack problem).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/15.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define w first
#define v second

const int MAX = 100001;
int dp[MAX];

int main() {
    int n, k, weight, value;
    vector<pair<int, int> > items;
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> weight >> value;
        items.push_back(make_pair(weight, value));
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = k; j >= 1; --j) {
            if (items[i].w <= j)
                dp[j] = max(dp[j], dp[j - items[i].w] + items[i].v);
        }
    }
    
    cout << dp[k] << '\n';
    
    return 0;
}
