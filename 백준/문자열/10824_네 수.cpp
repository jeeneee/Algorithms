//
//  10824_네 수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << stoll(a + b) + stoll(c + d) << endl;

    return 0;
}
