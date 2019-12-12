//
//  10814_나이순 정렬.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 09/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare (pair<int, pair<int, string > > a,
              pair<int, pair<int, string > > b) {
    if (a.second.first == b.second.first)
        return a.first < b.first;
    else
        return a.second.first < b.second.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, string > > > v(n); // idx, age, name
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second.first >> v[i].second.second;
        v[i].first = i;
    }
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < n; ++i) {
        printf("%d %s\n", v[i].second.first, v[i].second.second.c_str());
    }
    
    return 0;
}
