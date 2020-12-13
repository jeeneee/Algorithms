//
//  2981_검문.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/29.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
가장 큰 수와 가장 작은 수의 차이를 구한 후, 그 값의 약수들로 나눠 나머지가 같은 지 확인한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findCommonFactor(int num) {
    vector<int> v;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            v.push_back(i);
            if (i * i != num)
                v.push_back(num / i);
        }
    }
    if (num != 1) v.push_back(num);
    sort(v.begin(), v.end());
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    int *numbers = new int[n];
    
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];
    
    sort(numbers, numbers + n);
    
    vector<int> commonFactor = findCommonFactor(numbers[n - 1] - numbers[0]);
    
    for (int i = 0; i < commonFactor.size(); ++i) {
        int remainder = numbers[0] % commonFactor[i];
        bool flag = true;
        for (int j = 1; j < n; ++j) {
            if (numbers[j] % commonFactor[i] != remainder) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << commonFactor[i] << ' ';
    }
    cout << '\n';
    
    delete []numbers;
    return 0;
}
