//
//  17497_계산기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/11/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string ans = "";
    int cnt = 0;
    while (n) {
        if (n & 1) {
            ans = "[/] " + ans;
            n *= 2;
        }
        else if (n & 2) {
            ans = "[+] " + ans;
            n -= 2;
        }
        else {
            ans = "[*] " + ans;
            n /= 2;
        }
        cnt++;
    }
    cout << cnt << endl << ans << endl;
    
    return 0;
}
