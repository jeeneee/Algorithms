//
//  좌표 정렬하기2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 09/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].second >> v[i].first;
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", v[i].second, v[i].first);
    
    return 0;
}

