//
//  10866_덱.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
 push_front X: 정수 X를 덱의 앞에 넣는다.
 push_back X: 정수 X를 덱의 뒤에 넣는다.
 pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 size: 덱에 들어있는 정수의 개수를 출력한다.
 empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
 front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
#include <iostream>
#include <cstring>
#define MAX 20000
using namespace std;

int main() {
    int n, deque[MAX], leftIdx = MAX / 2, rightIdx = MAX / 2;
    scanf("%d", &n);
    while (n--) {
        char op[11];
        scanf("%s", op);
        if (!strcmp(op, "push_front"))
            scanf("%d\n", &deque[--leftIdx]);
        else if (!strcmp(op, "push_back"))
            scanf("%d\n", &deque[rightIdx++]);
        else if (!strcmp(op, "pop_front"))
            printf("%d\n", rightIdx - leftIdx ? deque[leftIdx++] : -1);
        else if (!strcmp(op, "pop_back"))
            printf("%d\n", rightIdx - leftIdx ? deque[--rightIdx] : -1);
        else if (!strcmp(op, "size"))
            printf("%d\n", rightIdx - leftIdx);
        else if (!strcmp(op, "empty"))
            printf("%d\n", rightIdx == leftIdx);
        else if (!strcmp(op, "front"))
            printf("%d\n", rightIdx - leftIdx ? deque[leftIdx] : -1);
        else if (!strcmp(op, "back"))
            printf("%d\n", rightIdx - leftIdx ? deque[rightIdx - 1] : -1);
    }
    return 0;
}
