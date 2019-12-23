//
//  14-2 마법의 약(POTION).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/23.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

vector<int> solve(const vector<int>& recipe,
                  const vector<int>& put) {
    auto n = recipe.size();
    int b = recipe[0];
    for (int i = 1; i < n; ++i) b = gcd(b, recipe[i]);
    int a = b;
    for (int i = 0; i < n; ++i)
        a = max(a, ceil(put[i] * b, recipe[i]));
    vector<int> ret(n);
    for (int i = 0; i < n; ++i)
        ret[i] = recipe[i] * a / b - put[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> recipe(n);
        vector<int> put(n);
        
        for (int i = 0; i < n; ++i)
            cin >> recipe[i];
        for (int i = 0; i < n; ++i)
            cin >> put[i];
        
        vector<int> ans = solve(recipe, put);
        
        for (int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
