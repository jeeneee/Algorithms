//
//  5430_AC.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/16.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 MAX 값을 너무 작게 설정해 애를 썼다...
 arr은 100,000개(개당 최대 3자리 수)를 입력받을 수 있지만 charArr에서 문자열 수는 최대 400,001개
 가 될 수 있다. [ , ] 모두 포함해서.
 */
#include <iostream>
#include <cstring>
#define MAX 400010
using namespace std;

int main() {
    int testCase;
    scanf("%d", &testCase);
    while (testCase--) {
        int n, arr[MAX];
        char func[MAX], charArr[MAX];
        scanf("%s", func);
        scanf("%d", &n);
        scanf("%s", charArr);
        char * pch = strtok(charArr, "[,]");
        int num = 0;
        while (n--) {
            arr[num++] = atoi(pch);
            pch = strtok(NULL, "[],");
        }
        
        int leftIdx = 0, rightIdx = num;
        bool isReversed = false, error = false;
        for (int i = 0; func[i] != '\0'; ++i) {
            if (func[i] == 'R')
                isReversed = !isReversed;
            else {
                if (isReversed)
                    rightIdx--;
                else
                    leftIdx++;
                if (rightIdx < leftIdx) {
                    error = true;
                    break;
                }
            }
        }
        if (error)
            printf("error\n");
        else {
            printf("[");
            if (isReversed)
                for (int i = rightIdx - 1; i >= leftIdx; --i) {
                    printf("%d", arr[i]);
                    if (i != leftIdx)
                        printf(",");
                }
            else
                for (int i = leftIdx; i < rightIdx; ++i) {
                    printf("%d", arr[i]);
                    if (i != rightIdx - 1)
                        printf(",");
                }
            printf("]\n");
        }
    }
    return 0;
}
