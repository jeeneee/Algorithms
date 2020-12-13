//
//  1476_날짜 계산.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/21.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    int i = 1;
    int j = 1;
    int k = 1;
    int ans = 1;
    while (true) {
        if (i == E && j == S && k == M)
            break;
        i++; j++; k++;
        if (i > 15) i = 1;
        if (j > 28) j = 1;
        if (k > 19) k = 1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
