//
//  10845_큐.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 10001
using namespace std;

int main() {
    int n, q[MAX], idx = 0, cnt = 0;
    char op[6];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", op);
        switch (op[1]) {
            case 'u':
                scanf("%d", &q[cnt++]);
                break;
            case 'o':
                printf("%d\n", cnt - idx ? q[idx++] : -1);
                break;
            case 'i':
                printf("%d\n", cnt - idx);
                break;
            case 'm':
                printf("%d\n", cnt == idx);
                break;
            case 'r':
                printf("%d\n", cnt - idx ? q[idx] : -1);
                break;
            case 'a':
                printf("%d\n", cnt - idx ? q[cnt - 1] : -1);
            default:
                break;
        }
    }
    
    return 0;
}
