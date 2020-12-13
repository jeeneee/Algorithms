//
//  7568_덩치.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 08/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
int ranking[51];

int main() {
    int n;
    cin >> n;
    v.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i].first > v[j].first && v[i].second > v[j].second) {
                ranking[j]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ++ranking[i] << ' ';
    }
    cout << endl;
    return 0;
}
