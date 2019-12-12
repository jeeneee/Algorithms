//
//  10610_30.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/20.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string num;
    int arr[10] {0, };
    int sum = 0;
    cin >> num;
    for (char &c: num) {
        int n = c - '0';
        sum += n;
        arr[n]++;
    }
    if (!arr[0] || sum % 3 != 0) {
        printf("-1");
        return 0;
    }
    for (int i = 9; i >= 0; --i) {
        while (arr[i]--) {
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
