//
//  10815_숫자 카드.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/19.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, num;
    
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i)
        cin >> cards[i];
    sort(cards.begin(), cards.end());
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        bool found = false;
        cin >> num;
        int lo = 0, hi = n - 1, mid;
        if (num < cards[lo] || num > cards[hi]) {
            cout << 0 << ' ';
            continue;
        }
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (cards[mid] == num) {
                found = true;
                break;
            }
            else if (cards[mid] < num) lo = mid + 1;
            else hi = mid - 1;
        }
        cout << found << ' ';
    }
    cout << '\n';

    return 0;
}
