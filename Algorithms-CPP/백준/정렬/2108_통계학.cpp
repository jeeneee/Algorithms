//
//  2108_통계학.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 09/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define Round2Int(x) ((x) < 0 ? int((x) - 0.5) : int((x) + 0.5))
using namespace std;

vector<int> v;

int main() {
    int n, sum = 0;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    
    int cnt = 0, maxCnt = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] == v[i - 1]) {
            cnt++;
            if (cnt > maxCnt){
                maxCnt = cnt;
            }
        }
        else
            cnt = 0;
    }
    int * num = new int[n];
    int idx = 0;
    cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] == v[i - 1]) {
            cnt++;
            if (cnt == maxCnt) {
                num[idx] = v[i];
                idx++;
            }
        }
        else
            cnt = 0;
    }
    int fre;
    if (idx > 1)
        fre = num[1];
    else if (idx == 1)
        fre = num[0];
    else
        fre = v[1];
    if (n == 1)
        fre = v[0];
    int mean = Round2Int((double)sum / n);
    int middle = v[n / 2];
    int range = v[n - 1] - v[0];
    
    cout << mean << endl;
    cout << middle << endl;
    cout << fre << endl;
    cout << range << endl;
    
    delete []num;
    
    return 0;
}
