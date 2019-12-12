//
//  11053_가장 긴 증가하는 부분 수열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/31.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int > > v;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    v.push_back({arr[0]});
    
    for (int i = 1; i < n; ++i) {
        int size = (int)v.size();
        for (int j = 0; j < size; ++j) {
            vector<int> temp;
            if (arr[i] > v[j][v[j].size() - 1]) {
                v[j].push_back(arr[i]);
                continue;
            }
            else if (arr[i] < v[j][0]) {
                v.push_back({arr[i]});
                continue;
            }
            bool isEqual = false;
            for (int k = 0; k < v[j].size(); ++k) {
                if (arr[i] == v[j][k]) {
                    isEqual = true;
                    break;
                }
                if (arr[i] < v[j][k]) break;
                temp.push_back(v[j][k]);
            }
            if (!isEqual) {
                temp.push_back(arr[i]);
                v.push_back(temp);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        ans = max(ans, (int)v[i].size());
    }
    cout << ans << endl;
    
    return 0;
}
