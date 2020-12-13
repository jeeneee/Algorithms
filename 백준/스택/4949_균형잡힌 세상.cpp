//
//  4949_균형잡힌 세상.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/16.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    while (getline(cin, str) && str != ".") {
        stack<char> stack;
        bool flag = true;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(' || str[i] == '[') stack.push(str[i]);
            else if (str[i] == ')') {
                if (stack.empty() || stack.top() != '(') {
                    flag = false;
                    break;
                }
                else stack.pop();
            }
            else if (str[i] == ']') {
                if (stack.empty() || stack.top() != '[') {
                    flag = false;
                    break;
                }
                else stack.pop();
            }
        }
        puts(flag && stack.empty() ? "yes" : "no");
    }
    
    return 0;
}

