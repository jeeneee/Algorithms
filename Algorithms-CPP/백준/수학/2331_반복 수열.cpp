//
//  2331_반복 수열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/16.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int a, p;
    vector<int> arr;
    cin >> a >> p;
    bool flag = false;
    int res = 0;
    
    while (true) {
        arr.push_back(a);
        int num = 0;
        while (a) {
            num += pow(a % 10, p);
            a /= 10;
        }
        a = num;
        for (int i = 0; i < arr.size(); ++i) {
            if (a == arr[i]) {
                flag = true;
                res = i;
                break;
            }
        }
        if (flag)
            break;
    }
    cout << res << '\n';
    
    return 0;
}
