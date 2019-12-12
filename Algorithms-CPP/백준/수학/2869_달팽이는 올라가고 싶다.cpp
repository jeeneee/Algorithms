//
//  2869_달팽이는 올라가고 싶다.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 10/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 처음엔 ceil((double)(v - a) / (a - b))와 같이 올림으로 처리했지만 double 처리에서
 약간의 오차율이 발생해 틀렸다. 너무 편하게 코딩하지 말자.
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, v, res;
    
    cin >> a >> b >> v;
    res = (v - a) / (a - b);
    if ((v - a) % (a - b) != 0)
        ++res;
    cout << ++res << endl;
    
    return 0;
}

