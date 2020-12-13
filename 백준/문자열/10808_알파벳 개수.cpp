//
//  10808_알파벳 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char str[101];
    int al[26] {0};
    cin >> str;
    
    for (int i = 0; str[i] != 0; ++i)
        al[(int)str[i] - 97]++;
    
    for (int i = 0; i < 26; ++i) {
        cout << al[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
