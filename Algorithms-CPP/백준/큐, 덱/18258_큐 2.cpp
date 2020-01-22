//
//  18258_큐 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/21.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    int q[2000000] = {};
        // [l, r)
    int l = 0, r = 0;
    char op[6];
    scanf("%d", &n);
    
    while (n--) {
        scanf("%s", op);
        if (op[1] == 'u') scanf("%d", &q[r++]);
        else if (op[1] == 'o') printf("%d\n", r-l ? q[l++] : -1);
        else if (op[1] == 'i') printf("%d\n", r-l);
        else if (op[1] == 'm') printf("%d\n", r == l);
        else if (op[1] == 'r') printf("%d\n", r-l ? q[l] : -1);
        else if (op[1] == 'a') printf("%d\n", r-l ? q[r-1] : -1);
    }
    
    return 0;
}
