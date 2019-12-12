//
//  1992_쿼드 트리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/17.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 64
using namespace std;

int mat[MAX][MAX];  // w:0, b:1

void quad(int n, int x, int y) {
    bool isEqual = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (mat[x+i][y+j] != mat[x][y])
                isEqual = false;
    if (isEqual)
        printf("%d", mat[x][y]);
    else {
        printf("(");
        quad(n/2, x, y);
        quad(n/2, x, y + n/2);
        quad(n/2, x + n/2, y);
        quad(n/2, x + n/2, y + n/2);
        printf(")");
    }
}
         
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%1d", &mat[i][j]);
    quad(n, 0, 0);
    
    return 0;
}
