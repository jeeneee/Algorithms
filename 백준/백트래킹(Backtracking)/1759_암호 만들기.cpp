//
//  1759_암호 만들기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/26.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[15];
vector<char> picked;

void pick(vector<char> v, int toPick, int cur_idx) {
    if (toPick == 0) {
        int consonants = 0;
        int vowels = 0;
        string ans = "";
        
        for (char &c: picked) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ++vowels;
            else
                ++consonants;
            ans += c;
        }
        
        if (vowels >= 1 && consonants >= 2)
            cout << ans << '\n';
        
        return;
    }
    for (auto i = cur_idx; i < v.size(); ++i) {
        if (!visited[i]) {
            picked.push_back(v[i]);
            visited[i] = true;
            pick(v, toPick - 1, i);
            picked.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    int L, C;
    cin >> L >> C;
    vector<char> v(C);
    
    for (int i = 0; i < C; ++i) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    pick(v, L, 0);
    
    return 0;
}
