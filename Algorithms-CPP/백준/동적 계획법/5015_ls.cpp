//
//  5015_ls.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/31.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int cache[101][101];

bool match(int w, int s, const string& W, const string& S) {
    int &ret = cache[w][s];
    if (ret != -1) return cache[w][s];
    while (w < W.size() && s < S.size() && W[w] == S[s]) {
        ++w;
        ++s;
    }
    if (w == W.size())
        return ret = (s == S.size());
    if (W[w] == '*')
        for (int skip = 0; skip+s <= S.size(); ++skip)
            if (match(w + 1, skip+s, W, S))
                return ret = 1;
    return ret = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string W, S;
    int n;
    cin >> W >> n;
    
    for (int i = 0; i < n; ++i) {
        memset(cache, -1, sizeof(cache));
        cin >> S;
        if (match(0, 0, W, S))
            cout << S << '\n';
    }
    
    return 0;
    
}

