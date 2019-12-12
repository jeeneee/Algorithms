//
//  2675_문자열 반복.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 07/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int main() {
    int n, r;
    string s;
    cin >> n;
    
    while (n--) {
        cin >> r >> s;
        char * new_str = new char[s.length() * r];
        int i = 0, j = 0;
        for (i = 0; i < s.length(); ++i) {
            for (j = 0; j < r; ++j) {
                new_str[i * r + j] = s[i];
            }
        }
        new_str[(i - 1) * r + j] = '\0';
        cout << new_str << endl;
        delete []new_str;
    }
    
    return 0;
}

