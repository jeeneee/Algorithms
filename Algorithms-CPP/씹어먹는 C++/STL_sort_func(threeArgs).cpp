//
//  main.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 12/09/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
             pair<string, pair<int, int> > b) {
    if (a.second.first == b.second.first) {
        return a.second.second > b.second.second;
    }
    else {
        return a.second.first > b.second.first;
    }
}

int main() {
    vector<pair<string, pair<int, int> > > v;
    v.push_back(pair<string, pair<int, int> > ("a", make_pair(80, 19930218)));
    v.push_back(pair<string, pair<int, int> > ("b", make_pair(93, 19940218)));
    v.push_back(pair<string, pair<int, int> > ("c", make_pair(76, 19950218)));
    v.push_back(pair<string, pair<int, int> > ("d", make_pair(93, 19960218)));
    
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < 4; i++) {
        cout << v[i].first << ' ';
    }
    
    return 0;
}
