//
//  10828_스택.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
 push X: 정수 X를 스택에 넣는 연산이다.
 pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 size: 스택에 들어있는 정수의 개수를 출력한다.
 empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
 top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

enum option {
    push,
    pop,
    size,
    empty,
    top
};

option hashit(string const& op) {
    if (op == "push") return push;
    if (op == "pop") return pop;
    if (op == "size") return size;
    if (op == "empty") return empty;
    if (op == "top") return top;
    return push;
}

int main() {
    stack<int> stack;
    int n;
    string op;
    cin >> n;
    while (n--) {
        cin >> op;
        switch (hashit(op)) {
            case push:
                int num;
                cin >> num;
                stack.push(num);
                break;
            case pop:
                if (stack.empty())
                    puts("-1");
                else {
                    cout << stack.top() << endl;
                    stack.pop();
                }
                break;
            case size:
                cout << stack.size() << endl;
                break;
            case empty:
                cout << stack.empty() << endl;
                break;
            case top:
                if (stack.empty())
                    puts("-1");
                else
                    cout << stack.top() << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
