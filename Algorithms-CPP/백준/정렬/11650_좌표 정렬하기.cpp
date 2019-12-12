//
//  11650_좌표 정렬하기.cpp
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
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}

