//
//  11655_ROT13.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + ((s[i] + 13 - 'a') % 26);
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'A' + ((s[i] + 13 - 'A') % 26);
    }
    
    cout << s << endl;
    
    return 0;
}
