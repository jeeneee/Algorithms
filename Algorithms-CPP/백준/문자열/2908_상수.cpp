//
//  2908_상수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 07/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

string swap(string &str) {
    for (int i = 0; i < str.length() / 2; ++i) {
        char temp = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = str[i];
        str[i] = temp;
    }
    return str;
}

int main() {
    string a, b;
    cin >> a >> b;
    a = swap(a); b = swap(b);
    cout << max(stoi(a), stoi(b)) << endl;;
    
    return 0;
}
