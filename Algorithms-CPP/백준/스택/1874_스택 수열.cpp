//
//  1874_스택 수열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    stack<int> stack;
    vector<char> vector;
    int n, num, idx = 1;
    cin >> n;
    while (n--) {
        cin >> num;
        while (idx <= num) {
            stack.push(idx);
            vector.push_back('+');
            idx++;
        }
        if (stack.top() != num){
            puts("NO");
            return 0;
        }
        else {
            stack.pop();
            vector.push_back('-');
        }
    }
    
    for (int i = 0; i < vector.size(); ++i) {
        printf("%c\n", vector[i]);
    }
    
    return 0;
}
