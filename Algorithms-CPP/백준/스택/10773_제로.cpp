//
//  10773_제로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 13/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stack;
    int n, sum = 0;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (num != 0) {
            stack.push(num);
            sum += num;
        }
        else {
            if (!stack.empty()) {
                sum -= stack.top();
                stack.pop();
            }
        }
    }
    cout << sum << endl;
    
    return 0;
}

