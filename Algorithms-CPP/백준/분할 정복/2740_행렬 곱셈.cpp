//
//  2740_행렬 곱셈.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/17.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 100
using namespace std;

int A[MAX][MAX];
int B[MAX][MAX];

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &A[i][j]);
    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < k; ++j)
            scanf("%d", &B[i][j]);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int value = 0;
            for (int t = 0; t < m; ++t) {
                value += A[i][t] * B[t][j];
            }
            printf("%d ", value);
        }
        printf("\n");
    }
    
    return 0;
}
