//
//  9375_패션왕 신해빈.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/29.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int main() {
    int TC;
    cin >> TC;
    int n;
    
    while (TC--) {
        cin >> n;
        string dress_name, dress_species;
        vector<string> v;
        cin.ignore();
        
        for (int i = 0; i < n; ++i) {
            getline(cin, dress_name);
            size_t found = dress_name.find(' ');
            dress_species = dress_name.substr(found + 1);
            v.push_back(dress_species);
        }
        
        vector<pair<string, int > > count;
        for (int i = 0; i < v.size(); ++i) {
            bool isFound = false;
            for (int j = 0; j < count.size(); ++j) {
                if (v[i] == count[j].first) {
                    count[j].second++;
                    isFound = true;
                    break;
                }
            }
            if (!isFound)
                count.push_back( {v[i], 1} );
        }
        
        ll ans = 1;
        for (int i = 0; i < count.size(); ++i) {
            ans *= count[i].second + 1;
        }
        cout << ans - 1 << '\n';
    }
    
    return 0;
}
