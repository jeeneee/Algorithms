//
//  1152_단어의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 07/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
    gets를 사용하면 메모리 범위를 벗어날 수 있기에, fgets를 사용했으며 개행문자까지 포함하므로
    str[strlen(str) - 1] = '\0';
 */
#include <iostream>
#include <cstring>
#include <stdlib.h>
#define MAX 1000003
using namespace std;

int main() {
    int i = 0, res = 0;
    char str[MAX];
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
            res++;
    }
    if (str[0] != ' ') res++;
    cout << res << endl;
    
    return 0;
}

