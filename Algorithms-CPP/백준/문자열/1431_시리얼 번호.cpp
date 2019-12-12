//
//  1431_시리얼 번호.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 07/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> v;

int getSum (string a) {
    int sum = 0;
    long int n = a.length();
    for (int i = 0; i < n; i++) {
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
            sum += a[i] - '0';
        }
    }
    return sum;
}

bool compare (string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else {
        int aSum = getSum(a);
        int bSum = getSum(b);
        if (aSum != bSum)
            return aSum < bSum;
        else
            return a < b;
    }
}

int main() {
    int n;
    string str;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}

