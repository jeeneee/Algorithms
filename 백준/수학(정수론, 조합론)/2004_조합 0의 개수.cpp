//
//  2004_조합 0의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/29.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 입력을 20억까지 받기 때문에 주석 친 코드로는 불가능하다.
 주석 친 코드는 2부터 n까지 소인수분해하는 내용.
 질문을 참조하니 아래와 같이 쉽게 풀 수 있었다.
 */
#include <iostream>
#include <algorithm>
using namespace std;

//typedef struct Counter {
//    int two;
//    int five;
//    void findElement(int x);
//} Counter;
//
//void Counter::findElement(int x) {
//    for (int i = 2; i <= x; ++i) {
//        int num = i;
//        for (int j = 2; j * j <= num; ++j) {
//            while (num % j == 0) {
//                if (j == 2) ++two;
//                if (j == 5) ++five;
//                num /= j;
//            }
//        }
//        if (num == 2) ++two;
//        if (num == 5) ++five;
//    }
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    Counter cnt1{0, 0}, cnt2{0, 0}, cnt3{0, 0};
//    cnt1.findElement(n);
//    cnt2.findElement(m);
//    cnt3.findElement(n - m);
//    int two = cnt1.two - (cnt2.two + cnt3.two);
//    int five = cnt1.five - (cnt2.five + cnt3.five);
//    cout << min(two, five) << '\n';
//
//    return 0;
//}
int findTwo(int x) {
    int two = 0;
    while (x > 1) {
        x /= 2;
        two += x;
    }
    return two;
}

int findFive(int x) {
    int five = 0;
    while (x > 1) {
        x /= 5;
        five += x;
    }
    return five;
}

int main() {
    int n, m;
    cin >> n >> m;
    int two = findTwo(n) - (findTwo(m) + findTwo(n - m));
    int five = findFive(n) - (findFive(m) + findFive(n - m));
    cout << min(two, five) << '\n';
    return 0;
}
