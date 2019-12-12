//
//  1780_종이의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/17.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 3000
using namespace std;

int mat[MAX][MAX];
int ans[3];

void cut(int n, int x, int y) {
    bool isEqual = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (mat[x][y] != mat[x+i][y+j]) {
                isEqual = false;
                break;
            }
    if (isEqual)
        ans[mat[x][y] + 1]++;
    else {
        cut(n/3, x, y);
        cut(n/3, x, y + n/3);
        cut(n/3, x, y + 2 * n/3);
        cut(n/3, x + n/3, y);
        cut(n/3, x + n/3, y + n/3);
        cut(n/3, x + n/3, y + 2 * n/3);
        cut(n/3, x + 2 * n/3, y);
        cut(n/3, x + 2 * n/3, y + n/3);
        cut(n/3, x + 2 * n/3, y + 2 * n/3);
    }
                
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &mat[i][j]);
    
    cut(n, 0, 0);
    printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
    
    return 0;
}
