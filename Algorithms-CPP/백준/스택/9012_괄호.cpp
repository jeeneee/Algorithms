//
//  9012_괄호.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 13/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    string str;
    cin >> t;
    while (t--) {
        int cnt = 0;
        cin >> str;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ')') {
                if (cnt == 0) {
                    cnt--;
                    cout << "NO" << endl;
                    break;
                }
                else
                    cnt--;
            }
            else cnt++;
        }
        if (cnt == 0)
            cout << "YES" << endl;
        else if (cnt > 0)
            cout << "NO" << endl;
    }
    return 0;
}
