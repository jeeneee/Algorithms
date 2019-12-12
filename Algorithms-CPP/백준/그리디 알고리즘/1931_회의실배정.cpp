//
//  1931_회의실배정.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 09/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int > > v(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    int endTime = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].first >= endTime) {
            endTime = v[i].second;
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
