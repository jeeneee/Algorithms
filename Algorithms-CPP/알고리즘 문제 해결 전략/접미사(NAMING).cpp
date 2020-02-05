//
//  접미사(NAMING).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/05.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = (int)N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b, s;
    cin >> a >> b;
    s = a + b;
    
    int k = (int)s.length();
    vector<int> ans, pi = getPartialMatch(s);
    
    while (k > 0) {
        ans.push_back(k);
        k = pi[k-1];
    }
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        cout << *it << ' ';
    cout << '\n';
    
    return 0;
}
