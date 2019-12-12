//
//  1193_분수 찾기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 07/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, row;
    cin >> n;
    for (row = 1; ; ++row)
        if (row * (row - 1) / 2 < n && n <= row * (row + 1) / 2)
            break;
    int pos = n - row * (row - 1) / 2;  // 4
    int x = row - pos + 1;
    int y = pos;
    if (row % 2 == 0) {
        int temp = x;
        x = y;
        y = temp;
    }
    cout << x << '/' << y << endl;
    
    return 0;
}
