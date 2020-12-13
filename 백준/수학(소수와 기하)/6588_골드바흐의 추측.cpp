//
//  6588_골드바흐의 추측.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/14.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 cout << '\n' 을 하더라도 시간초과가 났다. 물론 cin으로 입력받았다.
 scanf, printf를 사용하니 통과하였다.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAX = 1000001;

int main() {
    bool primeArray[MAX];
    fill(primeArray, primeArray + MAX, true);
    for (int i = 2; i * i <= MAX; ++i)
        if (primeArray[i])
            for (int j = i * i; j <= MAX; j += i)
                primeArray[j] = false;
    int n;
    while (scanf("%d", &n) && n != 0) {
        bool flag = false;
        for (int i = 3; i <= n / 2; i += 2) {
            if (primeArray[i] && primeArray[n - i]) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("Goldbach's conjecture is wrong.\n");
    }
    
    return 0;
}
