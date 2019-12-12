//
//  10826_피보나치 수 4.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/30.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10001;

// a < b
string calc2str(string a, string b) {
    string temp, ans;
    int added, raise = 0;
    for (int i = (int)a.length() - 1, j = (int)b.length() - 1; j >= 0; --i, --j) {
        added = (i < 0) ? b[j] - 48 : a[i] + b[j] - 2 * 48;
        added += raise;
        temp.push_back((char)(added % 10 + 48));
        raise = added / 10;
    }
    if (raise) temp.push_back((char)(raise % 10 + 48));
    for (int i = (int)temp.length() - 1; i >= 0; --i) {
        ans.push_back(temp[i]);
    }
    return ans;
}



int main() {
    int n;
    cin >> n;
    string a = "0";
    string b = "1";
    string c;
    for (int i = 2; i <= n; ++i) {
        c = calc2str(a, b);
        a = b;
        b = c;
    }
    if (n == 0 || n == 1) { cout << n << endl; return 0; }
    cout << c << endl;
    return 0;
}
