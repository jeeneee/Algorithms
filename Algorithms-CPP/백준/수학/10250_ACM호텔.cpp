//
//  10250.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 11/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;
    while (T--) {
        cin >> H >> W >> N;
        int a = N % H;
        if (a == 0)
            a = H;
        int b = N / H;
        if (N % H != 0)
            b++;
        printf("%d%02d\n", a, b);
    }
    
    return 0;
}
